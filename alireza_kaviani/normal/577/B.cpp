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

const ll MAXN = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , m , a[MAXN] , dp[MAXN][MAXN];

ll get(ll x)
{
    return (x % m == 0 ? m : x % m);
}

int main()
{
    fast_io;

    cin >> n >> m;
    if(n > m)   return cout << "YES" << endl , 0;
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];

    dp[0][0] = 1;
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = m ; j >= 0 ; j--)
        {
            if(dp[i - 1][j] == 1)
            {
                dp[i][get(j + a[i])] = 1;
                dp[i][j] = 1;
            }
        }
        if(dp[i][m] == 1)  return cout << "YES" << endl , 0;
    }
    cout << "NO" << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/