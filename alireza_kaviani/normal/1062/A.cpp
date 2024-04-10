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

const ll MAXN = 110;
ll n , t = 1 , ans , p[MAXN];

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];
    p[0] = 0;
    p[n + 1] = 1001;

    for(ll i = 1 ; i <= n + 1 ; i++)
    {
        if(p[i] == p[i - 1] + 1)    t++;
        else    t = 1;
        ans = max(ans , t - 2);
    }
    cout << ans << endl;

    return 0;
}