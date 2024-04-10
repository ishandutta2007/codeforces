#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <complex>
#include <chrono>
#include <sstream>
#include <fstream>
#include <deque>
#include <cassert>
#include <unordered_map>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

const char el = '\n';
const int inf = 1000'000'000, mod = 998244353;//, mod2 = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int (i) = 0; i < (int)(n); ++(i))
#define firn(i, n) for (int (i) = 1; i < (int)(n); ++(i))
//#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
//#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
//#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T& a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T& a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd_64(chrono::high_resolution_clock::now().time_since_epoch().count());

vector<int> solve(int n, vector<int> b) {
    if (n == 0) return {};
    if (n == 1) return b;
    int k = 1;
    while ((k << 1) <= n) k <<= 1;
    if (k == n) {
        vector<int> tmp(solve(n / 2, vector<int>(b.begin() + n / 2, b.end())));
        vector<int> ans(n);
        copy(tmp.begin(), tmp.end(), ans.begin());
        vector<int> c(n / 2);
        forn(i, n / 2) c[i] = b[i] ^ b[i + n / 2];
        tmp = solve(n / 2, c);
        copy(tmp.begin(), tmp.end(), ans.begin() + n / 2);
        return ans;
    } else {
        int diff = n - k;
        vector<int> c(diff);
        forn(i, diff) c[i] = b[i] ^ b[i + k];
        vector<int> ans(n);
        vector<int> tmp(solve(diff, c));
        copy(tmp.begin(), tmp.end(), ans.begin() + k);
        tmp = solve(k, vector<int>(b.begin(), b.begin() + k));
        forn(i, k) {
            if (i < diff) ans[i] = tmp[i] ^ ans[i + k];
            else ans[i] = tmp[i];
        }
        return ans;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n);
    forn(i, n) cin >> b[i];
    auto ans = solve(n, b);
    reverse(all(ans));
    output(ans);
    return 0;
}