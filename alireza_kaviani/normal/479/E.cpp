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
//#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 5010;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , a , b , k , t , sum = 1 , p[MAXN] , dp[MAXN][MAXN];

int main()
{
    fast_io;

    cin >> n >> a >> b >> k;
    if(a > b)
    {
        a = n - a + 1;
        b = n - b + 1;
    }

    dp[0][a] = 1;
    for(ll i = 1 ; i <= k ; i++)
    {
        fill(p , p + MAXN , 0);
        for(ll j = 1 ; j < b ; j++)
        {
            dp[i][j] = (sum - dp[i - 1][j] + MOD) % MOD;
            p[1] -= dp[i - 1][j];
            p[max(0LL , j * 2 - b) + 1] += dp[i - 1][j];
        }

        sum = 0 , t = 0;
        for(ll j = 1 ; j < n ; j++)
        {
            t += p[j];
            dp[i][j] = (dp[i][j] + t + MOD * MAXN) % MOD;
            sum = (sum + dp[i][j]) % MOD;
        }
    }
    cout << sum << endl;

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