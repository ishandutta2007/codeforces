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
ll n, k;
string s[1000];
vector <pair <ll, pll> > v;
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    cin >> n >> k;
    ll start = 0;
    for (int i = 1; i <= n; ++i){
        cin >> s[i];
    }
    for (int i = 1; i <= n; ++i){
        s[i] += 'P';
//        s[i] += 'P';
        s[i] = 'P' + s[i];
//        s[i] = 'P' + s[i];
        ll da = s[i].size();
        for (int j = 1; j < da - 1; ++j){
            ll ans = 0;
            if (s[i][j] == 'P' or s[i][j] == 'S'){
                if (s[i][j - 1] == 'S') ans++;
                if (s[i][j + 1] == 'S') ans++;
                start += ans;
            }
            ans = 0;
            if (s[i][j] == '.'){
                if (s[i][j - 1] == 'S') ans++;
                if (s[i][j + 1] == 'S') ans++;
                v.push_back(m_p(ans, m_p(i, j)));
            }
        }
    }
    sort(v.begin(), v.end());
    ll d = 0;
    for (int i = 0; i < k; ++i){
        d += v[i].fi;
        s[v[i].se.fi][v[i].se.se] = 'x';
    }
    cout << d + start  << endl;
    for (int i = 1; i <= n; ++i){
        ll da = s[i].size();
        for (int j = 1; j < da - 1; ++j){
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}