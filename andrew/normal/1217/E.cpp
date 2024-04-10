#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct Set{
    int a, b;

    void insert(int x){
        b = min(b, x);
        if(a > b)swap(a, b);
    }

};

Set t[10][800010];

void build(int xe, int v, int tl, int tr){
    t[xe][v].a = t[xe][v].b = 2e9;
    if(tl != tr){
        int tm = (tl + tr) >> 1;
        build(xe, v << 1, tl, tm);
        build(xe, (v << 1) + 1, tm + 1, tr);
    }
}

void modify(ll xe, ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        t[xe][v].a = val;
    }else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(xe, v << 1, tl, tm, pos, val);
        else modify(xe, (v << 1) + 1, tm + 1, tr, pos, val);
        t[xe][v].a = t[xe][v].b = 2e9;
        t[xe][v].insert(t[xe][v << 1].a);
        t[xe][v].insert(t[xe][v << 1].b);
        t[xe][v].insert(t[xe][(v << 1) + 1].a);
        t[xe][v].insert(t[xe][(v << 1) + 1].b);
    }
}

Set ans;

void get(ll xe, ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return;
    if(tl == l && tr == r){
        ans.insert(t[xe][v].a);
        ans.insert(t[xe][v].b);
        return;
    }
    ll tm = (tl + tr) >> 1;
    get(xe, v << 1, tl, tm, l, min(r, tm));
    get(xe, (v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

ll st[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    st[0] = 1;

    for(int i = 0; i < 10; i++){
        build(i, 1, 1, n);
    }

    for(int i = 1; i < 10; i++)st[i] = st[i - 1] * 10ll;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 0; j < 10; j++){
            if((x / st[j]) % 10)modify(j, 1, 1, n, i, x);
        }
    }

    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll i, x;
            cin >> i >> x;
            for(int j = 0; j < 10; j++){
                if((x / st[j]) % 10)modify(j, 1, 1, n, i, x);
                else modify(j, 1, 1, n, i, 2e9);
            }
        }else{
            ll l, r;
            cin >> l >> r;
            int answer = 2e9 + 5;
            for(int j = 0; j < 10; j++){
                ans.a = ans.b = 2e9;
                get(j, 1, 1, n, l, r);
                if(ans.a != 2e9 && ans.b != 2e9)answer = min(answer, ans.a + ans.b);
            }
            if(answer == 2e9 + 5)cout << "-1\n";
            else cout << answer << "\n";
        }
    }

    return 0;
}