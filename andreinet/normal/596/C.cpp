#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int DMAX = 200005, OFFSET = 100003;

struct Point {
    int x, y;

    bool operator < (const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

vector<Point> diags[DMAX];

void noSolution() {
    cout << "NO\n";
    exit(0);
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

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        diags[OFFSET + y - x].push_back({x, y});
    }
    for (int i = 0; i < DMAX; ++i) {
        sort(diags[i].begin(), diags[i].end());
        reverse(diags[i].begin(), diags[i].end());
    }

    vector<Point> ans;
    set<Point> put;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;

        if (diags[OFFSET + w].empty()) noSolution();

        Point p = diags[OFFSET + w].back();
        diags[OFFSET + w].pop_back();

        if (p.x > 0) {
            Point l = {p.x - 1, p.y};
            if (!put.count(l)) noSolution();
        }
        if (p.y > 0) {
            Point l = {p.x, p.y - 1};
            if (!put.count(l)) noSolution();
        }

        put.insert(p);
        ans.push_back(p);
    }

    cout << "YES\n";
    for (const Point& p: ans)
        cout << p.x << ' ' << p.y << '\n';
}