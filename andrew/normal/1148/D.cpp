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
const ll N = 6e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

pll T[MAXN];
ll pr[MAXN];
ll dp[MAXN];

void u(ll pos, pll val){
    for(int i = pos; i <= N; i += i & -i)T[i] = max(T[i], val);
}

pll f(ll pos){
    pll res = {0, 0};
    for(int i = pos; i > 0; i -= i & -i)res = max(res, T[i]);
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector < pair<pll, ll> > a, b;
    ll n;
    cin >> n;

    ll step = 0;

    ll OLD = n;

    while(n--){
        ll x, y;
        step++;
        cin >> x >> y;
        if(x > y){
            b.p_b({{y, x}, step});
        }else{
            a.p_b({{y, x}, step});
        }
    }

    sort(all(b));

    ll ans = 0;

    for(auto i : b){
        ll sc = f(i.fi.se).fi + 1;
        dp[i.se] = sc;
        pr[i.se] = f(i.fi.se).se;
        ans = max(ans, sc);
        u(i.fi.fi, {sc, i.se});
    }

    for(int i = 0; i <= N; i++)T[i] = {0ll, 0ll};

    sort(all(a));
    reverse(all(a));

    for(auto i : a){
        ll sc = f(N - i.fi.se + 1).fi + 1;
        dp[i.se] = sc;
        pr[i.se] = f(N - i.fi.se + 1).se;
        ans = max(ans, sc);
        u(N - i.fi.fi + 1, {sc, i.se});
    }

    cout << ans << "\n";

    vector <ll> res;

    for(int i = 1; i <= OLD; i++)if(dp[i] == ans){
        ll x = i;
        while(x){
            res.p_b(x);
            x = pr[x];
        }
        break;
    }
    reverse(all(res));
    for(auto i : res)cout << i << " ";
    cout << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}