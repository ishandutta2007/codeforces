#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#pragma comment(linker, "/STACK:36777216")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
#define pb push_back
#define eb emplace_back
#define F first
#define S second

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;
ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-7, pi = acosl(-1);
const ll maxN = 100010, maxT = 1000000, A = 263;
void panic() {
    cout << "NO\n";
    exit(0);
}
void solve() {
    ll ans = 0;
    int n;
    cin >> n;
    set<ll>vls;
    map<ll, ll>f, s;
    map<pair<ll, ll>, ll>ct;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if (a > b)swap(a, b);
        vls.insert(a);
        vls.insert(b);
        if (a == b) {
            ++f[a];
        }
        else {
            ++s[a];
            ++s[b];
            ++ct[{a, b}];
        }
    }
    for (auto x : vls) {
        ans += f[x] * s[x] + s[x] * (s[x] - 1) / 2 + f[x] * (f[x] - 1) / 2;
    }
    for (auto x : ct)ans -= x.second * (x.second - 1) / 2;
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);
    // srand(time(0));
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}