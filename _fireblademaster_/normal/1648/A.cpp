#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x) {
    x = 0;
    int c = gc();
    int flag = 0;
    while (c < '0' || c > '9') {
        flag |= (c == '-'), c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    }
    if (flag) {
        x = -x;
    }
}
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
int n, m;
vector<vector<int>> a;
vector<int> A[100005], B[100005];

void init() {
    scanf("%d%d", &n, &m);
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i].resize(m + 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            A[a[i][j]].push_back(i);
            B[a[i][j]].push_back(j);
        }
    }
}

void solve() {
    ll ans = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (!A[i].empty()) {
            sort(A[i].begin(), A[i].end());
            ll sum = 0, num = 0;
            for (int j = 0; j < sz(A[i]); ++j) {
                ans += 1LL * num * A[i][j] - sum;
                num += 1;
                sum += A[i][j];
            }
        }
    }
    for (int i = 1; i <= 100000; ++i) {
        if (!B[i].empty()) {
            sort(B[i].begin(), B[i].end());
            ll sum = 0, num = 0;
            for (int j = 0; j < sz(B[i]); ++j) {
                ans += 1LL * num * B[i][j] - sum;
                num += 1;
                sum += B[i][j];
            }
        }
    }
    printf("%lld\n", ans);
}

//#define CASES_WITH_T
int main() {
    int t = 1;
    #ifdef CASES_WITH_T
    scanf("%d", &t);
    #endif
    while (t--) {
        init();
        solve();
    }
    return 0;
}