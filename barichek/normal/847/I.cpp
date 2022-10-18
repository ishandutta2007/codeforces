#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
const pair<int, int> turns[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m, p, qq;
long long a[MAXN][MAXN];
char c[MAXN][MAXN];
int d[MAXN][MAXN];

int main() {
    #ifdef Fekete
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else

    #endif // Fekete

//    ios::sync_with_stdio(false);
  //  cin.tie(nullptr);


    cin >> n >> m >> qq >> p;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!isalpha(c[i][j])) continue;
            queue<pair<int, int>> q;
            for(int ii = max(i - 30, 1); ii <= min(i + 30, n); ii++) {
                for(int jj = max(j - 30, 1); jj <= min(j + 30, m); jj++) {
                    d[ii][jj] = 1e9;
                }
            }
            d[i][j] = 0;
            q.push({i, j});
            int power = (c[i][j] - 'A' + 1) * qq;
            int lastDist = 0;
            while(!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(d[x][y] == 1e9) break;
                if(d[x][y] > lastDist) {
                    power /= 2;
                    lastDist = d[x][y];
                }
                if(power == 0) break;
                a[x][y] += power;
                for(auto turn : turns) {
                    pair<int, int> to = {x + turn.first, y + turn.second};
                    if(to.first <= 0 || to.first > n || to.second < 1 || to.second >m) continue;
                    if(c[to.first][to.second] == '*') continue;
                    if(d[to.first][to.second] > d[x][y] + 1) {
                        q.push(to);
                        d[to.first][to.second] = d[x][y] + 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m;j++) {
            if(a[i][j] > p) ans++;

        }
    }
    cout << ans;
}