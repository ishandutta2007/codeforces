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

const ll MAXN = 1010;
ll n , l[MAXN] , r[MAXN] , a[MAXN];

int main()
{
    fast_io;

    cin >> n;

    for(ll i = 0 ; i < n ; i++) cin >> l[i];
    for(ll i = 0 ; i < n ; i++) cin >> r[i];

    for(ll i = 0 ; i < n ; i++)
    {
        a[i] = n - (l[i] + r[i]);
    }
    for(ll i = 0 ; i < n ; i++)
    {
        ll x = 0 , y = 0;
        for(ll j = 0 ; j < i ; j++)
        {
            if(a[j] > a[i]) x++;
        }
        for(ll j = i + 1 ; j < n ; j++)
        {
            if(a[j] > a[i]) y++;
        }
        if(x != l[i] || y != r[i])  return cout << "NO" << endl , 0;
    }
    cout << "YES" << endl;
    for(ll i = 0 ; i < n ; i++)
    {
        cout << a[i] << ends;
    }

    return 0;
}