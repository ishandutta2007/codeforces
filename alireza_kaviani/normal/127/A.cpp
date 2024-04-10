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

double dis(pdd a , pdd b)
{
    return sqrt(pw( abs(a.X - b.X) , 2) + pw( abs(a.Y - b.Y) , 2));
}

const ll MAXN = 110;
pdd point[MAXN];
double n , k , ans = 0;

int main()
{
    fast_io;

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> point[i].X >> point[i].Y;
        ans += (i == 0 ? 0 : dis(point[i] , point[i - 1]));
    }
    printf("%10f" , ans * k / 50);

    return 0;
}