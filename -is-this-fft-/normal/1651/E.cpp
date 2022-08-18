#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 3e3 + 5;

vector<int> adj [MAX_N];
bool vis [MAX_N];

void dfs (int u, vector<int> &cyc) {
  vis[u] = true;
  cyc.push_back(u);

  for (int nxt : adj[u]) {
    if (!vis[nxt]) {
      dfs(nxt, cyc);
      return;
    }
  }
}

void proc_half_cyc (const vector<int> &cyc, int n, ll &ans) {
  // assume even positions are left half
  int m = cyc.size();
  for (int i = 0; i < m; i += 2) {
    int lmn = cyc[i], lmx = cyc[i];
    int rmn = 2 * n + 1, rmx = -1;
    for (int j = i + 1; j != i; j++, j %= m) {
      if (j % 2 == 0) {
        lmn = min(lmn, cyc[j]);
        lmx = max(lmx, cyc[j]);
      } else {
        rmn = min(rmn, cyc[j]);
        rmx = max(rmx, cyc[j]);

        if ((j + 1) % m != i) {
          // consider the good chain i---j
          int prv = cyc[(i + m - 1) % m]; // right half
          ll pways = 0;
          if (prv < rmn) {
            pways = (rmn - prv) * (2 * n - rmx + 1);
          } else if (prv > rmx) {
            pways = (rmn - n) * (prv - rmx);
          }

          int nxt = cyc[(j + 1) % m]; // left half
          ll nways = 0;
          if (nxt < lmn) {
            nways = (lmn - nxt) * (n - lmx + 1);
          } else if (nxt > lmx) {
            nways = lmn * (nxt - lmx);
          }

          ans += pways * nways;
        }
      }
    }
  }
}

void proc_cyc (vector<int> cyc, int n, ll &ans) {
  proc_half_cyc(cyc, n, ans);
  for (int i = 0; i < (int) cyc.size(); i++) {
    if (cyc[i] <= n) {
      cyc[i] += n;
    } else {
      cyc[i] -= n;
    }
  }

  int bk = cyc.back();
  cyc.pop_back();
  cyc.insert(cyc.begin(), bk);
  proc_half_cyc(cyc, n, ans);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);

    ll lways = u * (n - u + 1);
    ll rways = (v - n) * (n - (v - n) + 1);
    ans += lways * rways;
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vector<int> cyc;
      dfs(i, cyc);

      proc_cyc(cyc, n, ans);
    }
  }

  cout << ans / 2 << endl; 
}