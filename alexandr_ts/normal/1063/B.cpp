#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll MAX = 1e9;
const ll MAX2 = 1e7;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e3 + 10;


char s[N][N];
int dist[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int cost[] = {1, 1, 0, 0};

struct S {
    int first, second;
    bool operator < (const S a) const {
        if (dist[first][second] != dist[a.first][a.second])
            return dist[first][second] < dist[a.first][a.second];
        if (first != a.first)
            return first < a.first;
        return second < a.second;
    }
};

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, r, c, x, y;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &r, &c);
    scanf("%d %d", &x, &y);
    fr(i, n)
        scanf("%s", &s[i]);
    fr(i, n)
        fill(dist[i], dist[i] + m, INF);
    r--, c--;
    dist[r][c] = 0;
    set<S> q;
    q.insert({r, c});
    while (q.size()) {
        auto t = *q.begin();
        q.erase(q.begin());
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + t.first;
            int y = dy[i] + t.second;
            if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '*') {
                if (dist[x][y] > dist[t.first][t.second] + cost[i]) {
                    dist[x][y] = dist[t.first][t.second] + cost[i];
                    q.insert({x, y});
                }
            }
        }
    }

    int ans = 0;
    fr(i, n)
        fr(j, m) {
            if (dist[i][j] == INF) continue;
            int r = (dist[i][j] + j - c) / 2;
            int l = dist[i][j] - r;
            if (l <= x && r <= y) {
                ans++;
            }
        }
    cout << ans;
}