#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 2e3 + 5;
const ll INF = 1e18;

ll val [MAX_N];

vector<pair<int, ll>> adj [MAX_N];
ll dist [2][MAX_N];

void calc_dist (int idx, int src, int n) {
  for (int i = 1; i <= n; i++) {
    dist[idx][i] = INF;
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  Q.push(make_pair(0LL, src));
  while (!Q.empty()) {
    auto qtop = Q.top();
    Q.pop();

    int cur = qtop.second;
    if (dist[idx][cur] == INF) {
      dist[idx][cur] = qtop.first;
      
      for (auto pr : adj[cur]) {
        int nxt = pr.first;
        ll w = pr.second;
        
        if (dist[idx][nxt] > dist[idx][cur] + w) {
          Q.push(make_pair(dist[idx][cur] + w, nxt));
        }
      }
    }
  }

  map<ll, int> compr;
  for (int i = 1; i <= n; i++) {
    compr[dist[idx][i]] = 0;
  }

  int cur = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }
  
  for (int i = 1; i <= n; i++) {
    dist[idx][i] = compr[dist[idx][i]];
  }
}

ll table [MAX_N][MAX_N];
ll tablei [MAX_N][MAX_N];
ll tablej [MAX_N][MAX_N];
ll dp [MAX_N][MAX_N][2];

int nonem [MAX_N][MAX_N];
int nonemi [MAX_N][MAX_N];
int nonemj [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int s, t;
  cin >> s >> t;

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  calc_dist(0, s, n);
  calc_dist(1, t, n);
  
  for (int i = 1; i <= n; i++) {
    table[dist[0][i]][dist[1][i]] += val[i];
    nonem[dist[0][i]][dist[1][i]] = 1;
  }

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      tablei[i][j] = table[i][j];
      tablej[i][j] = table[i][j];
      nonemi[i][j] = nonem[i][j];
      nonemj[i][j] = nonem[i][j];
    }
  }
  
  for (int i = MAX_N - 2; i >= 0; i--) {
    for (int j = 0; j < MAX_N; j++) {
      tablei[i][j] += tablei[i + 1][j];
      nonemi[i][j] |= nonemi[i + 1][j];
    }
  }

  for (int i = 0; i < MAX_N; i++) {
    for (int j = MAX_N - 2; j >= 0; j--) {
      tablej[i][j] += tablej[i][j + 1];
      nonemj[i][j] |= nonemj[i][j + 1];
    }
  }

  for (int k = 2 * MAX_N; k >= 0; k--) {
    for (int i = 0; i < MAX_N - 1; i++) {
      int j = k - i;
      if (j >= 0 && j < MAX_N - 1) {
        if (nonemj[i][j]) {
          dp[i][j][0] = max(dp[i + 1][j][0], dp[i + 1][j][1]) + tablej[i][j];
        } else {
          dp[i][j][0] = dp[i + 1][j][0] + tablej[i][j];
        }

        if (nonemi[i][j]) {
          dp[i][j][1] = min(dp[i][j + 1][0], dp[i][j + 1][1]) - tablei[i][j];
        } else {
          dp[i][j][1] = dp[i][j + 1][1] - tablei[i][j];
        }
      }
    }
  }

  /*
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << dp[i][j][0] << " ";
    }
    cout << endl;
  }
  cout << " = " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << dp[i][j][1] << " ";
    }
    cout << endl;
  }
  */
  
  if (dp[0][0][0] < 0) {
    cout << "Cry" << endl;
  } else if (dp[0][0][0] == 0) {
    cout << "Flowers" << endl;
  } else {
    cout << "Break a heart" << endl;
  }
}