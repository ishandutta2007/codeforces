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

const int MAXN = 110;
int a[MAXN] , b[MAXN];

int main()
{
    fast_io;

    int n , m , x , y;
    cin >> n >> m >> x;
    for(int i = 0 ; i < x ; i++)  a[input()] = 1;
    cin >> y;
    for(int i = 0 ; i < y ; i++)  b[input()] = 1;

    for(int i = 0 ; i < 2 * n * m ; i++)
    {
        a[i % n] = b[i % m] = (a[i % n] | b[i % m]);
    }

    for(int i = 0 ; i < n ; i++)    if(!a[i])   return cout << "No" << endl , 0;
    for(int i = 0 ; i < m ; i++)    if(!b[i])   return cout << "No" << endl , 0;
    cout << "Yes" << endl;

    return 0;
}