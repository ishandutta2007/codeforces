#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define pll pair<ll, ll>
#define m_p make_pair
#define p_b push_back
#define all(v) v.begin(), v.end()
#define sqr(x)  (x) * (x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 3e5 + 5;
const ll M = 20;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    ll n, m;
    cin >> m >> n;

    vector <pll> a(n);

    map <ll, ll> mp;

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;

    ll x = a[0].fi, kol = 0;

    for(int i = 0; i < n; i++)if(a[i].fi != x && a[i].se != x){
        kol++;
        mp[a[i].fi]++;
        mp[a[i].se]++;
    }
    if(!kol)vout("Yes");

    bool f = 0;

    for(auto i : mp)if(i.se == kol)f = 1;

    if(f)vout("Yes");

    x = a[0].se, kol = 0;

    mp.clear();

    for(int i = 0; i < n; i++)if(a[i].fi != x && a[i].se != x){
        kol++;
        mp[a[i].fi]++;
        mp[a[i].se]++;
    }

    if(!kol)vout("Yes");
    f = 0;

    for(auto i : mp)if(i.se == kol)f = 1;

    if(f)vout("Yes");

    cout << "No\n";
    return 0;
}