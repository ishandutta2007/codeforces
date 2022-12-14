#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

struct node{
    ll Val, t1;
};

struct SegmentTree{
private:
    vector <node> T;
public:

    void anons(ll n){
        T.resize(4 * n + 2);
        for(int i = 0; i < 4 * n + 2; i++){
            T[i].Val = -1e18;
        }
    }

    void push(ll v){
        T[v << 1].Val += T[v].t1;
        T[v << 1].t1 += T[v].t1;
        T[(v << 1) + 1].Val += T[v].t1;
        T[(v << 1) + 1].t1 += T[v].t1;
        T[v].t1 = 0;
    }

    void update(ll v, ll tl, ll tr, ll pos, ll val){
        if(tl == tr){
            T[v].Val = max(T[v].Val, val);
        }else{
            ll tm = (tl + tr) >> 1;
            if(T[v].t1)push(v);
            if(pos <= tm)update(v << 1, tl, tm, pos, val); else update((v << 1) + 1, tm + 1, tr, pos, val);
            T[v].Val = max(T[v << 1].Val, T[(v << 1) + 1].Val);
        }
    }

    void modify(ll v, ll tl, ll tr, ll l, ll r){
        if(l > r)return;
        if(tl == l && tr == r){
            T[v].Val++;
            T[v].t1++;
            return;
        }
        ll tm = (tl + tr) >> 1;
        if(T[v].t1)push(v);
        modify(v << 1, tl, tm, l, min(r, tm));
        modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
        T[v].Val = max(T[v << 1].Val, T[(v << 1) + 1].Val);
    }

    ll Max(){
        return T[1].Val;
    }

};

SegmentTree dp[52];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;
    for(int i = 0; i <= k + 1; i++)dp[i].anons(n);

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    map <ll, ll> last;
    dp[1].update(1, 1, n, 1, 1);
    last[a[1]] = 1;
    for(int i = 2; i <= n; i++){
        ll x = a[i], uk = last[x] + 1;

        for(int j = k; j > 0; j--){
            ll val = -1e18;
            if(j != 1){
                val = dp[j - 1].Max();
                dp[j].update(1, 1, n, i, val + 1);
            }
            dp[j].modify(1, 1, n, uk, i - 1);

        }
        last[x] = i;
    }

    cout << dp[k].Max() << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}