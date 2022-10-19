#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll MAXK = 210;
const ll INF = 8e18;
const ll MOD = 998244353;

ll n , ans , p[MAXN] , dp[MAXN][MAXK][2]; // 0 : less-equal | 1 : greater

int main() {
    fast_io;
    set_random;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];

    dp[0][0][0] = 1;
    for(ll i = 1 ; i <= n ; i++)
    {
        ll sum = 0;
        for(ll j = 200 ; j >= 1 ; j--)
        {
            dp[i][j][0] = (sum + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
            sum = (sum + dp[i - 1][j][0]) % MOD;
        }

        sum = dp[i - 1][0][0] + dp[i - 1][0][1];
        for(ll j = 1 ; j <= 200 ; j++)
        {
            dp[i][j][1] = sum;
            sum = (sum + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
        }

        if(p[i] != -1)
        {
            for(ll j = 0 ; j < MAXK ; j++)
            {
                if(j != p[i])
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                }
            }
        }
    }

    for(ll i = 0 ; i < MAXK ; i++)
    {
        ans = (ans + dp[n][i][0]) % MOD;
    }
    cout << ans << endl;

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