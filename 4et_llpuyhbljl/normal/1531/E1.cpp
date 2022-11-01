//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
//#pragma comment(linker, "/STACK:36777216")
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
    cout << "-1\n";
    exit(0);
}
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
string s;
int n;
vector<int>to_srt, by;
vector<int>arr[2];
int sz[2];
pair<int, int> prec[20 * maxN];
int id = 0, yk = 0;
void build_lns(int l, int r) {
    if (l + 1 >= r)return;
    int m = (l + r) / 2;
    build_lns(l, m);
    build_lns(m, r);
    if (yk > n)return;
    int l1 = m - l, l2 = r - m;
    int f1, f2;
    tie(f1, f2) = prec[yk];
    if (f1 + l1 >= sz[0] && f2 + l2 >= sz[1]) {
        yk = n + 1;
        return;
    }
    if (f1 + l1 >= sz[0]) {
        yk = arr[1][f2 + l2 - 1] + 1;
        return;
    }
    if (f2 + l2 >= sz[1]) {
        yk = arr[0][f1 + l1 - 1] + 1;
        return;
    }
    yk = min(arr[0][f1 + l1 - 1], arr[1][f2 + l2 - 1]) + 1;
}
bool f(int len) {
    yk = 0;
    build_lns(0, len);
    return yk == n;
}
void build_ans(int l, int r) {
    if (l + 1 >= r)return;
    int m = (l + r) / 2;
    build_ans(l, m);
    build_ans(m, r);
    int yl = l, yr = m;
    int yb = 0;
    while (yl < m && yr < r) {
        if (s[id++] == '0') {
            by[yb++] = to_srt[yl++];
        }
        else {
            by[yb++] = to_srt[yr++];
        }
    }
    while (yl < m) {
        by[yb++] = to_srt[yl++];
    }
    while (yr < r) {
        by[yb++] = to_srt[yr++];
    }
    for (int i = 0; i < yb; ++i)
        to_srt[i + l] = by[i];
}
int ans[maxN];
void solve() {
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')arr[0].emplace_back(i);
        else arr[1].emplace_back(i);
    }
    arr[1].emplace_back(n);
    arr[0].emplace_back(n);
    sz[0] = arr[0].size();
    sz[1] = arr[1].size();
    for (int i = 0; i <= n; ++i) {
        int tl = lower_bound(arr[0].begin(), arr[0].end(), i) - arr[0].begin();
        int tr = lower_bound(arr[1].begin(), arr[1].end(), i) - arr[1].begin();
        prec[i] = { tl,tr };
    }
    int e = 1;
    while (!f(e))
        ++e;
    cout << e << "\n";
    to_srt.assign(e, 0);
    for (int i = 0; i < e; ++i)
        to_srt[i] = i;
    by.resize(e);
    build_ans(0, e);
    int v = 1;
    for (auto x : to_srt)ans[x] = v++;
    for (int i = 0; i < e; ++i)cout << ans[i] << " ";
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