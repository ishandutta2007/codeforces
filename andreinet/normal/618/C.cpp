#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

struct Point {
    int x, y, pos;
    Point() {}
    Point(int _x, int _y):
        x(_x), y(_y) {}
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

int64_t crossProduct(const Point& o, const Point& a, const Point& b) {
    return (int64_t) (a.x - o.x) * (b.y - o.y) -
           (int64_t) (a.y - o.y) * (b.x - o.x);
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

    vector<Point> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y;
        A[i].pos = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (A[i] < A[0]) {
            swap(A[i], A[0]);
        }
    }
    sort(A.begin() + 1, A.begin() + n, [&](const Point& a, const Point& b) -> bool {
        return crossProduct(A[0], a, b) < 0;
    });
    int pos = 2;
    while (pos < n && crossProduct(A[0], A[1], A[pos]) == 0) {
        ++pos;
    }
    int pos1 = pos;
    while (pos1 < n && crossProduct(A[0], A[pos], A[pos1]) == 0) {
        ++pos1;
    }

    Point p1 = *min_element(A.begin() + 1, A.begin() + pos);
    Point p2 = *min_element(A.begin() + pos, A.begin() + pos1);

    if (pos == n) throw 15;

    cout << A[0].pos << ' ' << p1.pos << ' ' << p2.pos << '\n';
}