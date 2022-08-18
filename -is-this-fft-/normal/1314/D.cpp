#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")

using namespace std;

const int MAX_N = 80;
const int INF = 1e8 + 5;

int dist [MAX_N][MAX_N];

const int MAX_W = 5;

pair<int, int> sdist [MAX_W][MAX_W];
int bfrom [MAX_W][MAX_W];

int rd [MAX_W][MAX_W];

bool white [MAX_N];
vector<int> whites;

int K;
int ans;
int dp [MAX_W][5];
void count_paths () {
  if (K == 1) {
    ans = min(ans, rd[0][0]);
    return;
  }
  
  for (int u = 0; u < 5; u++) {
    dp[1][u] = rd[0][u];
  }

  for (int i = 2; i < K; i++) {
    for (int u = 0; u < 5; u++) {
      dp[i][u] = dp[i - 1][0] + rd[0][u];
      for (int v = 1; v < 5; v++) {
        dp[i][u] = min(dp[i - 1][v] + rd[v][u], dp[i][u]);
      }
    }
  }

  for (int u = 0; u < 5; u++) {
    ans = min(ans, dp[K - 1][u] + rd[u][0]);
  }
}

void solve () {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sdist[i][j] = make_pair(2 * INF + 20, 2 * INF + 20);
      for (int k = 0; k < MAX_N; k++) {
        if (!white[k]) {
          int d = dist[whites[i]][k] + dist[k][whites[j]];
          if (d < sdist[i][j].first) {
            bfrom[i][j] = k;
            sdist[i][j].second = sdist[i][j].first;
            sdist[i][j].first = d;
          } else if (d < sdist[i][j].second) {
            sdist[i][j].second = d;
          }
        }
      }
    }
  }

  for (int u = whites.back() + 1; u < MAX_N; u++) {
    if (!white[u]) {
      white[u] = 1;
      whites.push_back(u);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (bfrom[i][j] == u) {
            rd[i][j] = sdist[i][j].second;
          } else {
            rd[i][j] = sdist[i][j].first;
          }
        }
      }

      for (int i = 0; i < 5; i++) {
        rd[i][4] = 2 * INF + 20;
        rd[4][i] = 2 * INF + 20;
        for (int k = 0; k < MAX_N; k++) {
          if (!white[k]) {
            rd[i][4] = min(rd[i][4], dist[whites[i]][k] + dist[k][whites[4]]);
            rd[4][i] = min(rd[4][i], dist[whites[4]][k] + dist[k][whites[i]]);
          }
        }
      }

      count_paths();
      
      whites.pop_back();
      white[u] = 0;
    }
  }
}

void dfs () {
  if ((int) whites.size() == 4) {
    solve();
  } else {
    for (int i = whites.back() + 1; i < MAX_N - 1; i++) {
      whites.push_back(i);
      white[i] = 1;
      dfs();
      white[i] = 0;
      whites.pop_back();
    }
  }
}

int main () {
  int n;
  cin >> n >> K;

  K /= 2;

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      dist[i][j] = INF;
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dist[i][j];
    }
  }

  ans = 1e9 + 200;
  
  white[0] = 1;
  whites.push_back(0);
  dfs();

  cout << ans << endl;
}