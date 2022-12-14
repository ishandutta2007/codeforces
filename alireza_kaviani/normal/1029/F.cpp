/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll Sqrt(ll x, ll y) {
    ll t = pow(x, 1. / y);
    for (ll i = max(0LL, t - 10); i <= t + 10; i++) {
        if (poww(i, y, ll(8e18)) == x) return i;
    }
    return -1;
}

set_random;

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

vector<ll> A, B;
ll x, y, sum, ans = INF;

vector<ll> divisors(ll n) {
    vector<ll> ans;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    return ans;
}

ll check(ll a, ll b) {
    ll ind = upper_bound(all(A), a) - A.begin() - 1;
    if (x / A[ind] <= b) return 1;
    ind = upper_bound(all(B), a) - B.begin() - 1;
    if (y / B[ind] <= b) return 1;
    return 0;
}

int main() {
    fast_io;

    cin >> x >> y;
    sum = x + y;

    A = divisors(x);
    B = divisors(y);
    Sort(A);
    Sort(B);

    for (ll i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            if (check(i, sum / i)) {
                ans = min(ans, (i + sum / i) * 2);
            }
        }
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