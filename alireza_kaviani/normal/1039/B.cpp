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
//#define endl                        '\n'
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

set_random;

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

ll n , k , l , r;
string s;

void randomQuery() {
    ll x = l + rng() % (r - l + 1);
    cout << x << sep << x << endl;
    cin >> s;
    if(s == "Yes")  exit(0);
    l = max(1LL , l - k);
    r = min(n , r + k);
}

void BSQuery()
{
    ll mid = (l + r) / 2;
    cout << l << sep << mid << endl;
    cin >> s;
    if(s == "Yes")  r = mid;
    else            l = mid;
    l = max(1LL , l - k);
    r = min(n , r + k);
}

int main() {
    fast_io;

    cin >> n >> k;

    l = 1 , r = n;

    while(1)
    {
        if(r - l + 1 <= 50) randomQuery();
        else                BSQuery();
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