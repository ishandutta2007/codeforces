#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct node{
    ll sum;
    ll Min, Max;
};

node t[5 * MAXN];

node unite(node l, node r){
    node res;
    res.sum = l.sum + r.sum;
    res.Min = min(l.Min, l.sum + r.Min);
    res.Max = max(l.Max, l.sum + r.Max);
    return res;
}

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        t[v].sum = t[v].Max = t[v].Min = val;
    }else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = unite(t[v << 1], t[v << 1 | 1]);
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll q;

    cin >> q;

    ll stn = 1e6 + 200;

    ll uk = 1;
    while(q--){
        char tp;
        cin >> tp;
        if(tp == 'L')uk--;
        else if(tp == 'R')uk++;
        else if(tp == '('){
            modify(1, 1, stn, uk, +1);
        }
        else if(tp == ')'){
            modify(1, 1, stn, uk, -1);
        }
        else{
            modify(1, 1, stn, uk, 0);
        }
        uk = max(1ll, uk);
        if(t[1].sum || t[1].Min < 0)cout << "-1 ";
        else cout << t[1].Max << " ";
    }
    cout << "\n";

    return 0;
}