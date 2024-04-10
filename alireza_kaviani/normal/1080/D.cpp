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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll t , n , k;

ll All(ll x)
{
    return pw(4 , x , INF) / 3;
}

ll Get(ll x)
{
    return pw(2 , x + 1 , INF) - (x + 2);
}

int main() {
    fast_io;
    set_random;

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n >= 32 || 1 + All(n - 1) >= k)
        {
            cout << "YES " << n - 1 << endl;
            continue;
        }
        if(All(n) < k)
        {
            cout << "NO" << endl;
            continue;
        }
        if(Get(n) <= k)
        {
            cout << "YES 0" << endl;
            continue;
        }
        if(n == 2)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES 1" << endl;
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