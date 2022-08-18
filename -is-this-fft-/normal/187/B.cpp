#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 65;
const int INF = 1e9 + 5;

int conn [MAX_N][MAX_N][MAX_N]; // car, from, to
int mconn [MAX_N][MAX_N];
int dist [MAX_N][MAX_N][MAX_N]; // from, to, #switch
bool vis [MAX_N][MAX_N][MAX_N];

struct State {
  int pos, swc;

  State (int _pos = 0, int _swc = 0) :
    pos(_pos), swc(_swc) {}
};

bool operator< (State p, State q) {
  if (p.pos != q.pos) return p.pos < q.pos;
  return p.swc < q.swc;
}

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m, qc;
  cin >> n >> m >> qc;

  for (int a = 0; a < m; a++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> conn[a][i][j];
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          conn[a][i][j] = min(conn[a][i][j], conn[a][i][k] + conn[a][k][j]);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mconn[i][j] = INF;
      for (int a = 0; a < m; a++) {
        mconn[i][j] = min(mconn[i][j], conn[a][i][j]);
      }
    }
  }
  
  for (int s = 0; s < n; s++) { // from
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[s][i][j] = INF;
      }
    }

    dist[s][s][0] = 0;
    ipq<pair<int, State>> Q; // dist, state
    Q.push(make_pair(0, State(s, 0)));

    while (!Q.empty()) {
      auto cur = Q.top().second;
      Q.pop();

      if (vis[s][cur.pos][cur.swc]) {
        continue;
      }

      if (cur.swc == n - 1) {
        continue;
      }

      for (int i = 0; i < n; i++) {
        auto nxt = State(i, cur.swc + 1);
        auto ndist = dist[s][cur.pos][cur.swc] + mconn[cur.pos][i];
        if (dist[s][nxt.pos][nxt.swc] > ndist) {
          dist[s][nxt.pos][nxt.swc] = ndist;
          Q.push(make_pair(ndist, nxt));
        }
      }
    }
  }

  for (int i = 0; i < qc; i++) {
    int s, t, k;
    cin >> s >> t >> k;
    
    s--; t--; k++;
    k = min(k, n - 1);

    cout << dist[s][t][k] << '\n';
  }
}