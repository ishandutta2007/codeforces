#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e5 + 10;
ll n , a[MAXN];
vector<ll> f , s , t;

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(a[i] == 1)   f.push_back(a[i]);
        if(a[i] == 2 || a[i] == 3)  s.push_back(a[i]);
        if(a[i] == 4 || a[i] == 6)  t.push_back(a[i]);
    }
    Sort(f) ; Sort(s) ; Sort(t);

    if(f.size() != n / 3 || s.size() != n / 3 || t.size() != n / 3) return cout << -1 << endl , 0;
    for(ll i = 0 ; i < n / 3 ; i++)
    {
        if(t[i] % s[i] != 0)    return cout << -1 << endl , 0;
    }
    for(ll i = 0 ; i < n / 3 ; i++)
    {
        cout << f[i] << ends << s[i] << ends << t[i] << endl;
    }

    return 0;
}