#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 201;

bitset<MAXN> b[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN / 4];

struct Point {
    ll x, y;
};

Point operator - (const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

bool operator < (const Point &a, const Point &b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

Point origin;

bool comp(const Point &a, const Point &b) {
    return cross(a - origin, b - origin) > 0;
}

bool comp1(const pair<Point, int> &a, const pair<Point, int> &b) {
    return comp(a.first, b.first) > 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n = 200, k = 50;
    cin >> n >> k;
    vector<Point> p(n);
    /*for (int i = 0; i < n; ++i)
        p[i] = {i, i * i};*/

    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    sort(all(p));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            for (int k = 0; k < n; ++k) {
                if (cross(p[j] - p[i], p[k] - p[i]) > 0)
                    b[i][j][k] = 1;
            }
        }
    }

    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        vector<Point> q;
        vector<pair<Point, int>> qq;

        for (int i = l + 1; i < n; ++i)
            qq.push_back({p[i] - p[l], i});
        origin = {0, 0};
        sort(all(qq), comp1);
        for (int i = 0; i < sz(qq); ++i)
            q.push_back(qq[i].first);
        int m = sz(q);

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int x = l, y = qq[i].second, z = qq[j].second;
                if (!((b[x][y] & b[y][z] & b[z][x]).any())) {
                    dp[i][j][3] = cross(q[i], q[j]);
                }
            }
        }

        for (int a = 0; a < m; ++a) {
            vector<pair<Point, int>> up, down;
            origin = q[a];
            for (int i = 0; i < a; ++i) {
                down.push_back({q[i], i});
            }
            sort(all(down), comp1);
            for (int i = a + 1; i < m; ++i) {
                up.push_back({q[i], i});
            }
            sort(all(up), comp1);

            for (int i = 4; i <= k; ++i) {
                vector<ll> s(sz(down) + 1);
                for (int j = 0; j < sz(down); ++j) {
                    s[j + 1] = max(s[j], dp[down[j].second][a][i - 1]);
                }
                int ptr = sz(down);
                for (int j = sz(up) - 1; j >= 0; --j) {
                    int b = up[j].second;
                    for (; ptr > 0 && cross(q[b] - q[a], down[ptr - 1].first - q[a]) < 0; --ptr);
                    if (s[ptr] > 0 && dp[a][b][3] > 0)
                        dp[a][b][i] = max(dp[a][b][i], s[ptr] + dp[a][b][3]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                ans = max(ans, dp[i][j][k]);
            }
        }
    }

    cout << ans / 2;
    if (ans & 1) {
        cout << ".50\n";
    } else {
        cout << ".00\n";
    }
}