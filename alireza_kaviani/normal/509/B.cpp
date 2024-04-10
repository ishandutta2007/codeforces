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

    int n , k , imin = 2e9 , imax = 0;
    cin >> n >> k;

    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        imin = min(imin , a[i]);
        imax = max(imax , a[i]);
    }

    if(imax - imin > k) return cout << "NO" << endl , 0;
    cout << "YES" << endl;

    for(int i = 0 ; i < n ; i++ , cout << endl)
    {
        for(int j = 0 ; j < a[i] ; j++)    cout << j % k + 1 << ends;
    }

    return 0;
}