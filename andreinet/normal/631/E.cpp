#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int64_t LINF = 1LL << 62;
const int MINF = 1000005;

struct Line {
    int64_t a, b;
    int64_t time;
    bool operator<(const Line& o) const {
        return a * -MINF + b > o.a * -MINF + o.b;
    }
};

struct Elem {
    int64_t a, s;
    int i;
    bool operator<(const Elem& o) const {
        return a < o.a;
    }
};

struct cmp {
    bool operator()(const Line& a, const Line& b) const {
        return a.time < b.time;
    }
};

int64_t solve(vector<int> A) {
    int n = SZ(A) - 1;
    vector<Elem> E(n + 1);
    vector<Line> lines(n + 1);

    int64_t sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += A[i];
        E[i] = {A[i], sum, i};
        lines[i] = {i, -sum, 0};
    }
    sort(lines.begin(), lines.end());
    vector<Line> stk;

    for (const Line& e: lines) {
        int64_t time = -LINF;
        while (!stk.empty()) {
            Line r = stk.back();
            if (e.a <= r.a) {
                time = LINF;
                break;
            }
            time = (r.b - e.b) / (e.a - r.a);
            while (e.a * time + e.b < r.a * time + r.b) {
                ++time;
            }
            if (time <= r.time) {
                stk.pop_back();
            } else {
                break;
            }
        }
        if (stk.empty()) {
            time = -LINF;
        }
        if (time != LINF) {
            stk.push_back(e);
            stk.back().time = time;
        }
    }

    int pos = 0;
    int64_t ans = 0;
    sort(E.begin(), E.end());
    for (const Elem& e: E) {
        if (e.i == 0) continue;
        int64_t val = -e.a * e.i + e.s;
        while (pos + 1 < SZ(stk) && stk[pos + 1].time <= e.a) {
            ++pos;
        }
        val += e.a * stk[pos].a + stk[pos].b;
        ans = max(ans, val);
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    int64_t ans = solve(A);
    int64_t s = 0;
    for (int i = 1; i <= n; ++i) {
        s += (int64_t) i * A[i];
    }
    ans = max(s, ans + s);

    cout << ans << '\n';
}