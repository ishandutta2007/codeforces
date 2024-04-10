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
constexpr int N = 200005;
int n, m;
int a[N], nxt[N];

void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
}

void solve() {
    map<int, int> Map;
    for (int i = n; i >= 1; --i) {
        Map[a[i]] += 1;
    }
    for (auto &[x, y] : Map) {
        if (y & 1) {
            printf("-1\n");
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] == a[i]) {
                nxt[i] = j;
                break;
            }
        }
    }
    vector<pii> lis;
    vector<int> sta;
    vector<int> nxt;
    vector<int> seq;
    Map.clear();
    auto ins = [&](int w) {
        sta.push_back(w);
        if (Map.count(w)) {
            nxt.push_back(Map[w]);
        } else {
            nxt.push_back(-1);
        }
        Map[w] = sz(sta) - 1;
    };
    auto del = [&]() {
        int w = sta.back();
        Map[w] = nxt.back();
        sta.pop_back();
        nxt.pop_back();
        return w;
    };
    for (int i = n; i >= 1; --i) ins(a[i]);
    int total = 0;
    while (!sta.empty()) {
        int l = sz(sta) - 1, r = nxt[l];
        del();
        assert(r != -1);
        vector<int> tmp;
        total += l - r + 1;
        for (int i = l - 1; i >= r + 1; --i) {
            int w = del();
            tmp.push_back(w);
        }
        for (auto &ele : tmp) {
            lis.emplace_back(total, ele);
            total += 1;
        }
        del();
        for (auto &ele : tmp) {
            ins(ele);
        }
        seq.push_back((l - r) << 1);
    }
    printf("%d\n", sz(lis));
    for (auto &[x, y] : lis) {
        printf("%d %d\n", x, y);
    }
    printf("%d\n", sz(seq));
    for (auto &ele : seq) {
        printf("%d ", ele);
    }
    printf("\n");
}

#define CASES_WITH_T
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