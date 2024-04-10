#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];

int dp [MAX_N][2];

void calc_dp (int u, int p) {
  int chc = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_dp(nxt, u);
      dp[u][1] = max(dp[u][1], dp[nxt][0]);
      chc++;
      dp[u][0] = max(dp[u][0], max(dp[nxt][0], dp[nxt][1]));
    }
  }

  dp[u][1]++;
  if (chc != 0) {
    dp[u][0] += chc - 1;
  }
}

struct TwoBest {
  pair<int, int> fst, snd; // <val, idx>
  TwoBest () : fst({0, -1}), snd({0, -1}) {
  }

  void add (pair<int, int> u) {
    if (u > fst) {
      snd = fst;
      fst = u;
    } else if (u > snd) {
      snd = u;
    }
  }

  int get (int idx) {
    if (fst.second == idx) return snd.first;
    return fst.first;
  }
};

int updp [MAX_N][2];
int ans [MAX_N][2];
void calc_updp (int u, int p) {
  TwoBest dp0s;
  TwoBest dp01s;

  if (u != p) {
    dp0s.add(make_pair(updp[u][0], p));
    dp01s.add(make_pair(max(updp[u][0], updp[u][1]), p));
  }

  int chc = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dp0s.add(make_pair(dp[nxt][0], nxt));
      dp01s.add(make_pair(max(dp[nxt][0], dp[nxt][1]), nxt));
      chc++;
    }
  }

  if (u == p) {
    chc--;
  }
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      // cerr << u << " " << nxt << " "<< dp0s.get(nxt) << " "<< dp01s.get(nxt) << endl;
      updp[nxt][1] = 1 + dp0s.get(nxt);
      updp[nxt][0] = dp01s.get(nxt) + max(0, chc - 1);
    }
  }

  chc = (int) adj[u].size();
  ans[u][1] = 1 + dp0s.get(-2);
  ans[u][0] = dp01s.get(-2) + max(0, chc - 1);

  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_updp(nxt, u);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  calc_dp(1, 1);
  calc_updp(1, 1);

  int anss = 0;
  for (int i = 1; i <= n; i++) {
    // cerr << i << " " << ans[i][0] << " " << ans[i][1] << endl;
    // cerr << "  " << updp[i][0] << " " << updp[i][1] << endl;
    anss = max(anss, ans[i][0]);
    anss = max(anss, ans[i][1]);
  }
  cout << anss << endl;
}