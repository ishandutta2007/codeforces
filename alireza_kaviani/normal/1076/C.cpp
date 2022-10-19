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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

ll t;
double x;

bool check(double y)
{
    return ((x - y) * y <= x && y <= x);
}

double BS(double l , double r , ll cnt = 0)
{
    if(cnt >= 1000 || abs(l - r) <= 1e-9)  return l;
    double mid = (l + r) / 2;
    if(check(mid))  return BS(mid , r , cnt + 1);
    return BS(l , mid , cnt + 1);
}

int main()
{
    fast_io;

    cin >> t;
    while(t--)
    {
        cin >> x;
        if(x == 0)
        {
            printf("Y 0.000000000 0.0000000000\n");
            continue;
        }
        double y = BS(1 , sqrt(x));
        if(abs(x - (x - y) * y) <= 1e-6)
        {
            printf("Y %.10f %.10f\n" , x - y , y);
        }
        else
        {
            printf("N\n");
        }
    }

    return 0;
}