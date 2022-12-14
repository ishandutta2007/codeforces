#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl "\n"
#define pll pair <ll,ll>
#define vl vector <ll>

typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;
const double eps = 1e-9;
const ll mod = 1e9 + 7;
using namespace std;

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n&1) ans*=a;
        a*=a;
        n >>= 1;
    }
    return ans;
}
ll x1, x2, x0 = 1e18, n, mn = 1e18;
vector <ll> v, v2;
ll prime[MAXN + 1000], f[MAXN * 5], ans[MAXN], da[MAXN];
set <ll> s;
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    n = 1000000;
    for (int i = 1; i <= n; ++i){
        prime[i] = 1;
    }
    ll i, j;
    for (i = 2; i <= n; ++i) if (prime[i]){
            v.push_back(i);
            f[i] = 1;
            ll kek = i; for (j = i * i; j <= n; j += i) prime[j] = 0;
        }
    cin >> x2;
//    for (int i = 0; i < v.size() / 2; ++i){
//        cout << v[i] << endl;
//    }
    for (int i = MAXN; i >= 2; --i){
        if (f[i]){
            for (int j = i; j <= MAXN; j += i){
                ans[j] = max(ans[j], ll(i));
            }
        }
    }
    for (int i = 0; i < v.size(); ++i){
        if (x2 % v[i] == 0){
            for (int j = x2 - 1; j >= x2 - v[i] + 1; j--){
                if (!da[j]) {
                        v2.push_back(j);
                        da[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < v2.size(); ++i){
//        cout << ans[v2[i]] << " " << v2[i] << endl;
        if (v2[i] - ans[v2[i]] + 1 != 1) mn = min(mn, v2[i] - ans[v2[i]] + 1);
        else mn = min(v2[i], mn);
    }
    cout << mn << endl;



    return 0;
}