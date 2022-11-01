#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
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
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
//#define int long long
const long long INF = -(1LL << 31);
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 100010;
void panic() {
    cout << "NIE\n";
    exit(0);
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>>a(3, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[0][i][j] = i;
            a[1][i][j] = j;
            cin >> a[2][i][j];
            --a[2][i][j];
        }
    }
    vector<int>shift(3), sp(3);
    sp[1] = 1;
    sp[2] = 2;
    string s;
    cin >> s;
    for (auto c : s) {
        if (c == 'U') {
            shift[0] = (shift[0] + n - 1) % n;
            continue;
        }
        if (c == 'D') {
            shift[0] = (shift[0] + 1) % n;
            continue;
        }
        if (c == 'R') {
            shift[1] = (shift[1] + 1) % n;
            continue;
        }
        if (c == 'L') {
            shift[1] = (shift[1] + n - 1) % n;
            continue;
        }
        if (c == 'I') {
            swap(shift[1], shift[2]);
            swap(sp[1], sp[2]);
            continue;
        }
        if (c == 'C') {
            swap(shift[0], shift[2]);
            swap(sp[0], sp[2]);
            continue;
        }
    }
    vector<vector<int>>ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int f = (a[sp[0]][i][j] + shift[0]) % n, s = (a[sp[1]][i][j] + shift[1]) % n;
            int d = (a[sp[2]][i][j] + shift[2]) % n;
            ans[f][s] = d;
        }
    }
    for (auto vec : ans) {
        for(auto x:vec)cout << x + 1 << ' ';
        cout << '\n';
    }
    cout << '\n';
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(11);
#ifdef _MY
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}