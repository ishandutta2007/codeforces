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
ll k, q[MAXN];
vector <ll> v[MAXN];
map <ll, set <ll> > mp;
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    cin >> k;
    for (int i = 1; i <= k; ++i){
        cin >> q[i];
        for (int j = 1; j <= q[i]; ++j){
            ll x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    ll ansl = 0, ansr = 0, sum = 0, ans = 0;
    for (int i = 1; i <= k; ++i){
        sum = 0;
        for (int j = 0; j < q[i]; ++j){
            sum += v[i][j];
        }
        for (int j = 0; j < q[i]; ++j){
            sum -= v[i][j];
            mp[sum].insert(i);
            if (mp[sum].size() > 1){
                ansl = *mp[sum].begin();
                ansr = *--mp[sum].end();
                ans = sum;
                goto l1;
            }
            sum += v[i][j];
        }
    }
    l1:;
    ll l = 0, r = 0;
    if (ansl == 0){
        cout << "NO" << endl;
        return 0;
    }
    sum = 0;
    for (int j = 0; j < v[ansl].size(); ++j){
        sum += v[ansl][j];
    }
    for (int j = 0; j < v[ansl].size(); ++j){
        sum -= v[ansl][j];
        if (sum == ans){
            l = j + 1;
            break;
        }
        sum += v[ansl][j];
    }

    sum = 0;
    for (int j = 0; j < v[ansr].size(); ++j){
        sum += v[ansr][j];
    }
    for (int j = 0; j < v[ansr].size(); ++j){
        sum -= v[ansr][j];
        if (sum == ans){
            r = j + 1;
            break;
        }
        sum += v[ansr][j];
    }
    cout << "YES" << endl;
    cout << ansl << " " << l << endl;
    cout << ansr << " " << r << endl;

    return 0;
}