#include <iostream>
#include <queue>

using namespace std;

#define x first
#define y second

const int INF = 2e9 + 2e4 + 5;
const int MAX_N = 2e3 + 5;

char grid [MAX_N][MAX_N];
int dist [MAX_N][MAX_N];
int vis [MAX_N][MAX_N];

int ni [4] = {1, 0, -1, 0};
int nj [4] = {0, 1, 0, -1}; // left is 3

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int sr, sc;
  cin >> sr >> sc;

  int cl, cr;
  cin >> cl >> cr;

  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      grid[i][j] = '*';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      dist[i][j] = INF;
    }
  }

  queue<pair<int, int>> Qc;
  queue<pair<int, int>> Qn;
  dist[sr][sc] = 0;
  Qc.push(make_pair(sr, sc));
  while (!Qc.empty() || !Qn.empty()) {
    if (Qc.empty()) {
      swap(Qc, Qn);
    }

    auto cur = Qc.front();
    Qc.pop();

    if (!vis[cur.x][cur.y]) {
      vis[cur.x][cur.y] = 1;

      for (int k = 0; k < 3; k++) {
        if (grid[cur.x + ni[k]][cur.y + nj[k]] == '.' &&
            dist[cur.x + ni[k]][cur.y + nj[k]] > dist[cur.x][cur.y]) {
          dist[cur.x + ni[k]][cur.y + nj[k]] = dist[cur.x][cur.y];
          Qc.push(make_pair(cur.x + ni[k], cur.y + nj[k]));
        }
      }

      int k = 3;
      if (grid[cur.x + ni[k]][cur.y + nj[k]] == '.' &&
          dist[cur.x + ni[k]][cur.y + nj[k]] > dist[cur.x][cur.y] + 1) {
        dist[cur.x + ni[k]][cur.y + nj[k]] = dist[cur.x][cur.y] + 1;
        Qn.push(make_pair(cur.x + ni[k], cur.y + nj[k]));
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int lefts = dist[i][j];
      int rights = lefts + j - sc;
      if (lefts <= cl && rights <= cr) {
        ans++;
        //  cout << '+';
      } else {
        //  cout << grid[i][j];
      }
    }
    // cout << endl;
  }
  cout << ans << endl;
}