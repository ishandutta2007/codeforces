#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 3;
const int INF = 2e9 + 1;

char a[N][N];
int dist[N][N];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string side = "DLRU";

bool ok(int x, int y, int k) {
    return dist[x][y] <= k;
}

bool tryGo(pair <int, int> cur, int i, int k, int n, int m) {
    int x = dx[i] + cur.first;
    int y = dy[i] + cur.second;
    return (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] != INF && dist[x][y] <= k);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    pair <int, int> start;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            if (a[i][j] == 'X')
                start = mp(i, j);
        }

    fr(i, n)
        fr(j, m)
            dist[i][j] = INF;
    dist[start.first][start.second] = 0;

    queue <pair <int, int> > q;
    q.push(start);
    while (!q.empty()) {
        pair <int, int> cur = q.front();
        q.pop();
        fr(i, 4) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == INF && a[x][y] == '.') {
                dist[x][y] = dist[cur.first][cur.second] + 1;
                q.push(mp(x, y));
            }
        }
    }

    string ans;
    pair <int, int> cur = start;

    while (k) {
        bool found = false;
        fr(i, 4)
            if (tryGo(cur, i, k - 1, n, m)) {
                ans += side[i];
                cur.first += dx[i];
                cur.second += dy[i];
                found = true;
                break;
            }
        if (!found) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        k--;
    }
    cout << ans;
    //cerr << (ld)clock() / CLOCKS_PER_SEC;
}