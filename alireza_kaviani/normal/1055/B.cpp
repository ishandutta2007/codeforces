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

const ll MAXN = 1e5 + 10;
ll n , q , l , t , p , d , ans , a[MAXN] , g[MAXN];

int main()
{
    fast_io;

    cin >> n >> q >> l;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        g[i] = (a[i] > l);
        if(g[i])
        {
            ans += 1 - (g[i - 1] + g[i + 1]);
        }
    }

    while(q--)
    {
        cin >> t;
        if(t == 0)
        {
            cout << ans << endl;
            continue;
        }
        cin >> p >> d;
        a[p] += d;
        if(g[p] == 0 && a[p] > l)
        {
            g[p] = 1;
            ans += 1 - (g[p - 1] + g[p + 1]);
        }
    }

    return 0;
}