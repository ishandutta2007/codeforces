#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int64_t LINF = 1LL << 62;

struct Line {
    int64_t a, b;
    Line() {}
    Line(int64_t _a, int64_t _b):
        a(_a), b(_b) {}
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> dist(n, 0);
    for (int i = 1; i < n; ++i) {
        cin >> dist[i];
        dist[i] += dist[i - 1];
    }

    vector<int> A(m);
    for (int i = 0; i < m; ++i) {
        int h, t;
        cin >> h >> t;
        h--;
        A[i] = t - dist[h];
    }
    sort(A.begin(), A.end());
    vector<int64_t> sum(m);
    int64_t s = 0;
    for (int i = 0; i < m; ++i) {
        s += A[i];
        sum[i] = s;
    }

    vector<int64_t> pdp(m);
    for (int i = 0; i < m; ++i) {
        pdp[i] = (int64_t) (i + 1) * A[i] - sum[i];
    }
    for (int t = 1; t < p; ++t) {
        vector<int64_t> ndp(m);

        vector<Line> stk;
        vector<int64_t> stkTime;
        stk.push_back(Line(1, 0));
        stkTime.push_back(-LINF);
        int64_t ans = 0;
        int first = 0;
        for (int i = 0; i < m; ++i) {
            int64_t val = A[i];
            while (first + 1 < SZ(stk) && stkTime[first + 1] <= val) {
                ++first;
            }
            int64_t dp = stk[first].b + val * stk[first].a
                            - sum[i] + (int64_t) A[i] * i;

            int64_t time = -LINF;
            int64_t ca = -i;
            int64_t cb = pdp[i] + sum[i];
            while (first < SZ(stk)) {
                int64_t ra = stk.back().a;
                int64_t rb = stk.back().b;

                time = (cb - rb) / (ra - ca);
                while (ca * time + cb > ra * time + rb) {
                    ++time;
                }

                if (time <= stkTime.back()) {
                    stk.pop_back();
                    stkTime.pop_back();
                } else {
                    break;
                }
            }
            if (first == SZ(stk)) time = -LINF;
            stk.push_back(Line(ca, cb));
            stkTime.push_back(time);
            
            ndp[i] = dp;
        }
        pdp = ndp;
    }

    cout << pdp[m - 1] << '\n';
}