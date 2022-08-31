#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
int lvl [MAX_N];
int par [MAX_N];
int dp [MAX_N];
vector<int> bk_up [MAX_N];
vector<int> bk_dn [MAX_N];
int lord [MAX_N];
int rord [MAX_N];
int cur;

void dfs (int vertex, int parent) {
  par[vertex] = parent;
  lvl[vertex] = lvl[parent] + 1;

  cur++;
  lord[vertex] = cur;

  for (int nxt : adj[vertex]) {
    if (lvl[nxt] == 0) {
      dfs(nxt, vertex);
      dp[vertex] += dp[nxt];
    } else if (lvl[nxt] < lvl[vertex] && nxt != parent) {
      dp[vertex]++;
      bk_up[vertex].push_back(nxt);
    } else if (lvl[nxt] > lvl[vertex]) {
      dp[vertex]--;
      bk_dn[vertex].push_back(nxt);
    }
  }

  rord[vertex] = cur;
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= vertexc; i++) {
    if (lvl[i] == 0) {
      dfs(i, i);
    }
  }

  pair<int, int> mid = {-1, -1};
  for (int i = 1; i <= vertexc; i++) {
    if (dp[i] >= 2 && par[i] != i) {
      mid = max(mid, {lvl[i], i});
    }
  }

  if (mid.first == -1) {
    cout << "NO" << endl;
    return 0;
  }

  vector<pair<int, int>> bks;
  int sv = mid.second;
  for (int u = par[sv]; (int) bks.size() < 2 ; u = par[u]) {
    for (int v : bk_dn[u]) {
      if (lord[sv] <= lord[v] && lord[v] <= rord[sv]) {
        bks.push_back({u, v});
        if (bks.size() == 2) {
          break;
        }
      }
    }
  }
  
  if (lvl[bks[0].first] < lvl[bks[1].first]) {
    swap(bks[0], bks[1]);
  }

  int fv = bks[0].first;  
  
  deque<int> easy;
  for (int i = sv; i != fv; i = par[i]) {
    easy.push_back(i);
  }
  easy.push_back(fv);

  deque<int> med;
  med.push_front(fv);
  for (int i = bks[0].second; i != sv; i = par[i]) {
    med.push_front(i);
  }
  med.push_front(sv);

  deque<int> hard;
  for (int i = fv; i != bks[1].first; i = par[i]) {
    hard.push_front(i);
  }
  hard.push_front(bks[1].first);
  for (int i = bks[1].second; i != sv; i = par[i]) {
    hard.push_front(i);
  }
  hard.push_front(sv);
  
  cout << "YES" << endl;
  cout << (int) easy.size();
  for (int u : easy) {
    cout << " " << u;
  }
  cout << endl;

  cout << (int) med.size();
  for (int u : med) {
    cout << " " << u;
  }
  cout << endl;

  cout << (int) hard.size();
  for (int u : hard) {
    cout << " " << u;
  }
  cout << endl;
}