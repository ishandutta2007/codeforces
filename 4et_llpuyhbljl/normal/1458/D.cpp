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
vector<vector<pair<int, int>>>G;
vector<int>used;
vector<int>cnt;
string mv;
void eler(int v, int d) {
    for (; cnt[v] < G[v].size(); ++cnt[v]) {
        int to, num;
        tie(to, num) = G[v][cnt[v]];
        if (used[num])continue;
        used[num] = 1;
        eler(to, (to > v ? 0 : 1));
    }
    if (d != -1)mv.push_back(d + '0');
}
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int mn = 0, mx = 0, b = 0;
    for (auto x : s) {
        if (x == '0')++b;
        else --b;
        mx = max(mx, b);
        mn = min(mn, b);
    }
    G.assign(mx - mn + 1, vector<pair<int, int>>(0));
    b = -mn;
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int b1;
        if (s[i] == '0')b1 = b + 1;
        else b1 = b - 1;
        G[b].push_back({ b1,i });
        G[b1].push_back({ b,i });
        b = b1;
    }
    for (auto& vec : G) {
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
    }
    mv.clear();
    cnt.assign(mx - mn + 1, 0);
    eler(-mn, -1);
    reverse(mv.begin(), mv.end());
    cout << mv;
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}