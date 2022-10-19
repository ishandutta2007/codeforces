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
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , p , sum , x , dp[5];
map<char , ll> ind;
string s;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/
    ind['h'] = 1;
    ind['a'] = 2;
    ind['r'] = 3;
    ind['d'] = 4;

    cin >> n >> s;

    s = "." + s;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> p;
        x = ind[s[i]]; sum += p;
        for(ll j = 0 ; j <= 4 ; j++)
        {
            if(x == 0)
            {
                dp[j] = dp[j] + p;
                continue;
            }
            if(x == j + 1)
            {
                dp[j] = dp[j];
                continue;
            }
            if(x == j)
            {
                dp[j] = max(dp[j] + p , dp[j - 1] + p);
                continue;
            }
            dp[j] = dp[j] + p;
        }
    }
    cout << sum - max({dp[0] , dp[1] , dp[2] , dp[3]}) << endl;

    return 0;
}