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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    ll n , k , ans = 8e18;
    cin >> n >> k;

    ll a[n] , b[n];
    pll x[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = 0 ; i < n ; i++)    cin >> b[i];
    for(int i = 0 ; i < n ; i++)    x[i] = {a[i] , b[i]};

    for(int i = 0 ; i < k ; i++)
    {
        ll ind = 0 , mn = 8e18;
        for(int j = 0 ; j < n ; j++)
        {
            if(x[j].Y / x[j].X < mn)    mn = x[j].Y / x[j].X , ind = j;
        }
        x[ind] = {x[ind].X , x[ind].Y + 1};
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(x[i].Y / x[i].X < ans)    ans = x[i].Y / x[i].X;
    }
    cout << ans << endl;

    return 0;
}