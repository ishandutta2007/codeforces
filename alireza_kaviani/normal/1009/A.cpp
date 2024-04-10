#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

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

    int n , m;
    cin >> n >> m;

    int c[n] , a[m];
    for(int i = 0 ; i < n ; i++)    cin >> c[i];
    for(int i = 0 ; i < m ; i++)    cin >> a[i];

    int i = 0 , j = 0;
    while(i < n && j < m)
    {
        if(a[j] >= c[i])    j++;
        i++;
    }
    cout << j << endl;

    return 0;
}