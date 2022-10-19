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
ll n , k , m , ans , x = 1 , p[MAXN] , nxt[MAXN];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/
    fill(nxt , nxt + MAXN , -1);

    cin >> n >> k;
    ans = (n - 1) * 2 - k + 1;
    for(ll i = 0 ; i < k ; i++)
    {
        cin >> m;
        for(ll j = 1 ; j <= m ; j++)
        {
            cin >> p[j];
            if(j != 1 && p[j] == p[j - 1] + 1)  nxt[p[j - 1]] = p[j];
        }
    }

    while(nxt[x] != -1)
    {
        ans -= 2;
        x = nxt[x];
    }
    cout << ans << endl;

    return 0;
}