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

int main()
{
    fast_io;

    ll n , s1 = 0 , s2 = 0 , mx = 0;
    cin >> n;

    ll a[n];
    for(ll i = 0 ; i < n ; i++) { cin >> a[i]; mx = max(mx , a[i]);}
    for(ll i = 0 ; i < n ; i++)
    {
        s1 += a[i];
        s2 += mx - a[i];
    }
    cout << mx + max(0LL , ((s1 - s2) + n) / n);


    return 0;
}