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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , q[MAXN] , p[MAXN] , t[MAXN] , mn;

int main() {
    fast_io;
    set_random;

    cin >> n;
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> q[i];
        p[i] = p[i - 1] + q[i];
        mn = min(mn , p[i]);
    }

    for(ll i = 0 ; i < n ; i++)
    {
        p[i] += 1 - mn;
        t[i] = p[i];
    }

    sort(t , t + n);
    for(ll i = 0 ; i < n ; i++)
    {
        if(t[i] != i + 1)   return cout << -1 << endl , 0;
    }
    for(ll i = 0 ; i < n ; i++) cout << p[i] << sep;


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