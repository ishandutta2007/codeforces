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
#define error(x)                    cerr << #x << " = " << x << endl
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

const ll MAXN = 60;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , ans , s , now = 1 , p[MAXN];
map<ll , ll> dp[MAXN];

int main() {
    fast_io;
    set_random;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];
    partial_sum(p , p + MAXN , p);

    for(ll i = 1 ; i <= n ; i++)
    {
        for(auto j : dp[i - 1])
        {
            dp[i][j.X] = max(j.Y , dp[i][j.X]);
        }
        for(ll j = 1 ; j <= i ; j++)
        {
            ll sum = p[i] - p[j - 1];
            dp[i][sum] = max(dp[i][sum] , dp[j - 1][sum] + 1);
        }
    }

    for(auto i : dp[n])
    {
        if(i.Y > ans)
        {
            ans = i.Y;
            s = i.X;
        }
    }

    cout << ans << endl;
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = now ; j <= i ; j++)
        {
            ll sum = p[i] - p[j - 1];
            if(sum == s)
            {
                cout << j << sep << i << endl;
                now = i + 1;
                break;
            }
        }
    }


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