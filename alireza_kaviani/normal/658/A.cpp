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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 100;
ll n , c , sx , sy , ansx , ansy , x[MAXN] , y[MAXN];


int main()
{
    fast_io;

    cin >> n >> c;
    for(ll i = 0 ; i < n ; i++) cin >> x[i];
    for(ll i = 0 ; i < n ; i++) cin >> y[i];

    for(ll i = 0 ; i < n ; i++)
    {
        sx += y[i];
        ansx += max(0LL , x[i] - sx * c);
    }
    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        sy += y[i];
        ansy += max(0LL , x[i] - sy * c);
    }
    if(ansx == ansy)    return cout << "Tie" << endl , 0;
    if(ansx < ansy)     return cout << "Radewoosh" << endl , 0;
    cout << "Limak" << endl;

    return 0;
}