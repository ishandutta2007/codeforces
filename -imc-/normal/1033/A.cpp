#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

//#define int li
//const int mod = 1000000007;

struct point {
    int x, y;
};

bool attacked(point a, point b) {
    int dx = abs(a.x - b.x), dy = abs(a.y - b.y);
    return dx == 0 || dy == 0 || dx == dy;
}

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;

    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    --a.x; --a.y; --b.x; --b.y; --c.x; --c.y;

    vector<vector<bool>> used(n, vector<bool>(n,false));
    deque<point> q;
    q.push_back(b);
    used[b.x][b.y] = true;

    while (!q.empty()) {
        point p = q.front();
        q.pop_front();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                point u = p;
                u.x += dx;
                u.y += dy;
                if (u.x < 0 || u.y < 0 || u.x >= n || u.y >= n || used[u.x][u.y] || attacked(a, u)) {
                    continue;
                }
                used[u.x][u.y] = true;
                q.push_back(u);
            }
        }
    }

    cout << (used[c.x][c.y] ? "YES" : "NO") << endl;
}