#include <bits/stdc++.h>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
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
vector <ll> v;
ll f[MAXN], a[MAXN], k;
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    ll n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (f[a[i]] == 0){
            f[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (f[a[i]]){
            v.push_back(f[a[i]]);
            f[a[i]] = 0;
            if (v.size() == k){
                cout << "YES" << endl;
                for (int i = 0; i < v.size(); ++i){
                    cout << v[i] << " ";
                }
                return 0;
            }
        }
    }
    cout << "NO" << endl;


    return 0;
}