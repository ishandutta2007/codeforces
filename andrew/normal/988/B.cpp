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
string s[MAXN], s1[MAXN];
ll n, f[MAXN];
vector <pair <ll, string> > v;
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> s[i];
    }
    for (int i = 1; i <= n; ++i){
        ll fl = 0;
        for (int j = 1; j <= n; ++j){
            if (f[j] == 0){
                ll ans = 0;
                for (int i1 = 1; i1 <= n; ++i1){
                    if (f[i1] == 0 && i1 != j && s[i1].find(s[j]) != string :: npos){
                        ans++;
                    }
                }
                if (ans == n - i){
                    f[j] = 1;
                    s1[i] = s[j];
                    fl = 1;
                    break;
                }
            }
        }
        if (fl == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i){
        cout << s1[i] << endl;
    }
    return 0;
}