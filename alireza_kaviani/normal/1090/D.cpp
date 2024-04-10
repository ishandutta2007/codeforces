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

ll n, m, v, u, x, y, val = 3, p[MAXN], deg[MAXN];
set<ll> adj[MAXN];

int main() {
    fast_io;
    set_random;

    cin >> n >> m;
    if (n * (n - 1) / 2 == m) return cout << "NO" << endl, 0;
    for (ll i = 0; i < m; i++) {
        cin >> v >> u;
        adj[v].insert(u);
        adj[u].insert(v);
    }

    for (ll i = 1; i <= n; i++) {
        if (adj[i].size() != n - 1) {
            x = i;
            break;
        }
    }

    for (ll i = 1; i <= n; i++) {
        if (i != x && adj[x].find(i) == adj[x].end()) {
            y = i;
            break;
        }
    }
    p[x] = 1;
    p[y] = 2;
    for (ll i = 1; i <= n; i++) {
        if (p[i] == 0) p[i] = val++;
    }

    cout << "YES" << endl;
    for (ll i = 1; i <= n; i++) cout << p[i] << sep;
    cout << endl;
    for (ll i = 1; i <= n; i++) cout << p[i] - (i == y) << sep;

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