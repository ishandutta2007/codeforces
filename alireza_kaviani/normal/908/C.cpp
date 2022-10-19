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

const int MAXN = 1010;
ll x[MAXN];
double y[MAXN];

int main()
{
    fast_io;

    double n , r;
    cin >> n >> r;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i];
        y[i] = r;
        for(int j = 0 ; j < i ; j++)
        {
            double d = abs(x[j] - x[i]);
            y[i] = max(y[i] , (d > r * 2 ? r : y[j] + sqrt(r * r * 4 - d * d)));
        }
        printf("%.10f " , y[i]);
    }

    return 0;
}