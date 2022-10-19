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

double f(double x , double y)
{
    return (x * y / (y - 1));
}

int main()
{
    fast_io;

    int n;
    double m , k;
    cin >> n >> m;

    double a[n] , b[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = 0 ; i < n ; i++)    cin >> b[i];

    k = m;
    for(int i = 0 ; i < n ; i++)
    {
        k = f(k , b[i]);
        k = f(k , a[n - i - 1]);
        if(b[i] == 1 || a[n - i - 1] == 1)  return cout << -1 << endl , 0;
    }
    printf("%.10f" , (k - m));

    return 0;
}