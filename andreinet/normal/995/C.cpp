#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int64_t L_VALUE = 1000000LL * 1000000LL;

struct Point {
    int x, y;
    Point operator-() const {
        return Point{-x, -y};
    }
    Point operator+(const Point& o) const {
        return Point{x + o.x, y + o.y};
    }
    int64_t dot(const Point& o) const {
        return x * (int64_t) o.x + y * (int64_t) o.y;
    }
    int64_t norm() const {
        return dot(*this);
    }
};

int64_t dot(const Point& a, const Point& b) {
    return a.x * (int64_t) b.x + a.y * (int64_t) b.y;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<Point> a;
    vector<int> son1, son2;
    vector<int> sign(2 * n, 1);
    int last1 = -1, last2 = -1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        son1.push_back(-1);
        son2.push_back(-1);
        if (last1 == -1) {
            last1 = SZ(a) - 1;
        } else if (last2 == -1) {
            last2 = SZ(a) - 1;
        } else {
            Point curr = a.back();
            if ((curr + a[last1]).norm() > L_VALUE && (-curr + a[last1]).norm() > L_VALUE) {
                swap(last1, last2);
            }
            son1.push_back(last1);
            son2.push_back(SZ(a) - 1);
            if ((-curr + a[last1]).norm() <= L_VALUE) {
                curr = -curr;
                cerr << SZ(a) << endl;
                sign[SZ(a) - 1] *= -1;
            }
            a.push_back(curr + a[last1]);
            last1 = SZ(a) - 1;
        }
        if (last1 != -1 && last2 != -1) {
            if (dot(a[last1], a[last2]) > 0) {
                a[last2] = -a[last2];
                sign[last2] *= -1;
            }
            if ((a[last1] + a[last2]).norm() <= L_VALUE) {
                a.push_back(a[last1] + a[last2]);
                son1.push_back(last1);
                son2.push_back(last2);
                last1 = SZ(a) - 1;
                last2 = -1;
            }
        }
    }
    for (int i = SZ(a) - 1; i >= 0; --i) {
        if (son1[i] != -1) {
            sign[son1[i]] *= sign[i];
            sign[son2[i]] *= sign[i];
        }
    }
    for (int i = 0; i < SZ(a); ++i) {
        if (son1[i] == -1) {
            cout << sign[i] << ' ';
        }
    }
    cout << '\n';

}