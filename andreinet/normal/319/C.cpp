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

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    deque<Line> stk;
    deque<int64_t> stkTime;
    stk.push_back(Line(B[0], 0));
    stkTime.push_back(-LINF);

    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
        int64_t val = A[i];
        while (SZ(stk) >= 2 && stkTime[1] <= val) {
            stk.pop_front();
            stkTime.pop_front();
        }
        stkTime[0] = -LINF;
        
        int64_t dp = stk.front().a * val + stk.front().b;

        int64_t ca = B[i], cb = dp;
        int64_t time = -LINF;
        while (!stk.empty()) {
            int64_t ra = stk.back().a, rb = stk.back().b;
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
        if (stk.empty()) time = -LINF;
        stk.push_back(Line(ca, cb));
        stkTime.push_back(time);

        ans = dp;
    }

    cout << ans << '\n';
}