#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;
const int NMAX = 2000 + 5;

struct Point {
    int x, y;
    Point() { x = y = 0; }
    Point(int _x, int _y): x(_x), y(_y) {}

} points[NMAX];

lint ccw(const Point &a, const Point &b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool operator<(const Point &a, const Point &b) {
    return ccw(a, b) > 0;
}

vector <Point> p1, p2;
void doSort(vector <Point> &v) {
    p1.clear(), p2.clear();
    for (const auto p: v) {
        if (p.y > 0 || (p.y == 0 && p.x > 0))
            p1.push_back(p);
        else
            p2.push_back(p);
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    v.clear();
    v = p2;
    for (auto it: p1)
        v.push_back(it);
}


lint ans;
void doSolve(vector <Point> &v) {
    const int N = v.size();
    v.resize(2 * N);
    for (int i = 0; i < N; ++ i)
        v[N + i] = v[i];

    int j = -1;
    int cnt = 0;
    for (int i = 0; i < N; ++ i) {
        while (j + 1 < i + N && ccw(v[i], v[j + 1]) >= 0)
            ++ j, ++ cnt;

        // Update answer
        const int a = cnt - 1;
        const int b = N - cnt;
        ans += (a * (a - 1LL) / 2LL) * (b * (b - 1LL) / 2LL);

        // Erase current point
        -- cnt;
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    int N = 2000;
    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> points[i].x >> points[i].y;

    /*for (int i = 1; i <= N; ++ i) {
        points[i].x = rand() % 3000;
        points[i].y = rand() % 3000;
    }*/

    vector <Point> v;
    for (int i = 1; i <= N; ++ i) {
        v.clear();
        for (int j = 1; j <= N; ++ j)
            if (i != j)
                v.emplace_back(points[j].x - points[i].x, points[j].y - points[i].y);
        doSort(v);
        doSolve(v);
    }

    cout << ans / 2 << endl;
    return 0;
}