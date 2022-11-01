#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005, DMAX = 2e8;

struct Point {
    int x, y;
    bool operator< (const Point& other) const {
        return x < other.x;
    }
};

Point A[NMAX];
int leftMaxY[NMAX], leftMinY[NMAX];
int rightMaxY[NMAX], rightMinY[NMAX];

bool works(int i, int j, int64_t dmax) {
    int ymax = max(leftMaxY[i - 1], rightMaxY[j]);
    int ymin = min(leftMinY[i - 1], rightMinY[j]);
    int64_t d1 = (int64_t) A[i].x * A[i].x +
                 (int64_t) ymax * ymax;
    int64_t d2 = (int64_t) A[i].x * A[i].x +
                 (int64_t) ymin * ymin;
    int64_t d3 = ymax - ymin;
    d3 *= d3;
    return d1 <= dmax && d2 <= dmax && d3 <= dmax;
}

int64_t getDist(int x, int y) {
    return (int64_t) x * x + (int64_t) y * y;
}

int64_t solve(int n) {
    int64_t ans = min(A[n].x - A[1].x, leftMaxY[n] - leftMinY[n]);
    ans *= ans;

    for (int i = 1; i <= n; ++i) {
        if (A[i].x > 0) break;
        int64_t cdist = (int64_t) DMAX * DMAX;
        for (int64_t dstep = 1LL << 61; dstep > 0; dstep /= 2) {
            if (cdist - dstep < 0) continue;
            cdist -= dstep;

            int pos = n + 1;
            for (int pstep = 1 << 16; pstep > 0; pstep /= 2) {
                if (pos - pstep > i && works(i, pos - pstep, cdist)) {
                    pos -= pstep;
                }
            }
            int ymax = max(leftMaxY[i - 1], rightMaxY[pos]);
            int ymin = min(leftMinY[i - 1], rightMinY[pos]);

            int64_t mdist = A[pos - 1].x - A[i].x;
            mdist *= mdist;
            if (i > 1 || pos <= n) {
                mdist = max(mdist, getDist(0, ymax - ymin));
                mdist = max(mdist, getDist(A[i].x, ymax));
                mdist = max(mdist, getDist(A[i].x, ymin));
                mdist = max(mdist, getDist(A[pos - 1].x, ymax));
                mdist = max(mdist, getDist(A[pos - 1].x, ymin));
            }

            if (mdist > cdist) {
                cdist += dstep;
            }
        }
        ans = min(ans, cdist);
    }
    
    /*for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int ymax = max(leftMaxY[i - 1], rightMaxY[j + 1]);
            int ymin = min(leftMinY[i - 1], rightMinY[j + 1]);
            int64_t mdist = max(A[j].x - A[i].x, ymax - ymin);
            mdist *= mdist;
            if (ymin != DMAX) {
                mdist = max(mdist, getDist(A[i].x, ymax));
                mdist = max(mdist, getDist(A[i].x, ymin));
                mdist = max(mdist, getDist(A[j].x, ymax));
                mdist = max(mdist, getDist(A[j].x, ymin));
            }
            ans = min(ans, mdist);
            if (mdist == 100) {
                cerr << i << ' ' << j << endl;
            }
        }
    }*/

    return ans;
}

void precalc(int n) {
    leftMaxY[0] = -DMAX;
    leftMinY[0] = DMAX;
    for (int i = 1; i <= n; ++i) {
        leftMaxY[i] = max(leftMaxY[i - 1], A[i].y);
        leftMinY[i] = min(leftMinY[i - 1], A[i].y);
    }

    rightMaxY[n + 1] = -DMAX;
    rightMinY[n + 1] = DMAX;
    for (int i = n; i > 0; --i) {
        rightMaxY[i] = max(rightMaxY[i + 1], A[i].y);
        rightMinY[i] = min(rightMinY[i + 1], A[i].y);
    }
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

    for (int i = 1; i <= n; ++i) {
        cin >> A[i].x >> A[i].y;
    }
    sort(A + 1, A + n + 1);

    precalc(n);

    int64_t ans = solve(n);
    for (int i = 1; i <= n; ++i) {
        A[i].x *= -1;
    }
    reverse(A + 1, A + n + 1);
    precalc(n);
    ans = min(ans, solve(n));
    cout << ans << '\n';
}