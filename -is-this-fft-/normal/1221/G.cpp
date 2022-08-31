#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 40;
const int HALF = 20;

typedef long long ll;

vector<int> adj [MAX_N];
int conn [MAX_N][MAX_N];

int vis [MAX_N];
void dfs (int u, int col, bool &bip) {
  vis[u] = col;
  for (int nxt : adj[u]) {
    if (vis[nxt] == 0) {
      dfs(nxt, -col, bip);
    } else if (vis[nxt] == col) {
      bip = false;
    }
  }
}

ll lfdp [1 << HALF];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;
  
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);

    conn[u][v] = 1;
    conn[v][u] = 1;
  }

  for (int mask = 0; mask < 1 << min(vertexc, HALF); mask++) {
    bool ok = true;
    
    for (int u = 0; u < HALF; u++) {
      if (mask & 1 << u) {
        for (int v = 0; v < HALF; v++) {
          if (mask & 1 << v) {
            if (conn[u][v]) {
              ok = false;
              break;
            }
          }
        }

        if (!ok) {
          break;
        }
      }
    }

    if (ok) {
      lfdp[mask] = 1;
    }
  }

  for (int k = 0; k < HALF; k++) {
    int m = 1 << k;
    for (int i = 0; i < 1 << HALF; i++) {
      if (i & m) {
        lfdp[i] = lfdp[i] + lfdp[i - m];
      }
    }
  }

  ll n_ind = 0;
  for (int mask = 0; mask < 1 << max(0, vertexc - HALF); mask++) {
    bool ok = true;

    for (int u = HALF; u < vertexc; u++) {
      if (mask & 1 << (u - HALF)) {
        for (int v = HALF; v < vertexc; v++) {
          if (mask & 1 << (v - HALF)) {
            if (conn[u][v]) {
              ok = false;
              break;
            }
          }
        }

        if (!ok) {
          break;
        }
      }
    }

    if (ok) {
      int to_ch = (1 << HALF) - 1;
      for (int u = HALF; u < vertexc; u++) {
        if (mask & 1 << (u - HALF)) {
          for (int v : adj[u]) {
            if (v < HALF) {
              if (to_ch & 1 << v) {
                to_ch -= 1 << v;
              }
            }
          }
        }
      }
      // cerr << mask << " " << to_ch << " " << lfdp[to_ch] << endl;
      n_ind += lfdp[to_ch];
    }
  }

  bool bip = true;
  int compc = 0;
  int sngc = 0;
  for (int i = 0; i < vertexc; i++) {
    if (vis[i] == 0) {
      compc++;
      dfs(i, 1, bip);
    }

    if (adj[i].empty()) {
      sngc++;
    }
  }

  ll n_bipc = bip ? 1LL << compc : 0;
  ll fakec = ((1LL << (compc - sngc)) - 2) * (1LL << sngc);
  if (sngc == compc) fakec = 0;
  ll ans = (1LL << vertexc) - n_ind - n_ind + n_bipc - fakec;
  cerr << (1LL << vertexc) << " " << n_ind << " " << n_bipc
       << " " << fakec << " " << sngc << " " << compc << endl;
  cout << ans << endl;
}