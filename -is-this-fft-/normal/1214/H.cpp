#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void failure () {
  cout << "No" << endl;
  exit(0);
}

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

int longdown [MAX_N];
void calc_longdown (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_longdown(nxt, u);
      longdown[u] = max(longdown[u], 1 + longdown[nxt]);
    }
  }
}

int longup [MAX_N];
void calc_longup (int u, int p) {
  vector<pair<int, int>> diams;
  diams.push_back(make_pair(1 + longup[u], -1));

  for (int nxt : adj[u]) {
    if (nxt != p) {
      diams.push_back(make_pair(2 + longdown[nxt], nxt));
    }
  }
  sort(diams.begin(), diams.end(), greater<pair<int, int>>());
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (diams[0].second == nxt) {
        longup[nxt] = diams[1].first; 
      } else {
        longup[nxt] = diams[0].first;
      }
      calc_longup(nxt, u);
    }
  }
}

int K;
void check (int u, int p) {
  vector<pair<int, int>> paths;
  if (p != 0) {
    paths.push_back(make_pair(longup[u], p));
  }
  for (int nxt : adj[u]) {
    if (nxt != p) {
      paths.push_back(make_pair(1 + longdown[nxt], nxt));
    }
  }

  if ((int) paths.size() >= 3) {
    sort(paths.begin(), paths.end(), greater<pair<int, int>>());
    if (paths[0].first + paths[1].first >= K - 1 &&
        paths[0].first + paths[2].first >= K - 1 &&
        paths[1].first + paths[2].first >= K - 1) {
      failure();
    }
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      check(nxt, u);
    }
  }
}

int ans [MAX_N];

void dfs2 (int u, int p) {
  ans[u] = !ans[p];
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs2(nxt, u);
    }
  }
}

void get_longds (int u, int p, vector<int> &longds) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      get_longds(nxt, u, longds);
      longds[u] = max(longds[u], 1 + longds[nxt]);
    }
  }
}

pair<int, int> get_ans (int u, int p, int cur, int depth, int dir, const vector<int> &longds) {
  ans[u] = cur;
  auto maxd = make_pair(depth, u);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (depth + longds[nxt] + 1 >= K - 1) {
        maxd = max(maxd, get_ans(nxt, u, (cur + dir + K) % K, depth + 1, dir, longds));
      }
    }
  }
  return maxd;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> K;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (K == 2) {
    dfs2(1, 0);

    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
      cout << 1 + ans[i] << " ";
    }
    cout << endl;
    
    return 0;
  }
  
  calc_longdown(1, 0);
  calc_longup(1, 0);
  check(1, 0);
  
  pair<int, int> ra = make_pair(-1, 0);
  for (int i = 1; i <= n; i++) {
    ra = max(ra, make_pair(longup[i], i));
  }
  
  int root_a = ra.second;
  vector<int> longds_a (n + 1, 0);
  get_longds(root_a, 0, longds_a);
  int root_b = get_ans(root_a, 0, 0, 0, 1, longds_a).second;

  vector<int> longds_b (n + 1, 0);
  get_longds(root_b, 0, longds_b);
  get_ans(root_b, 0, ans[root_b], 0, -1, longds_b);

  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) {
    cout << 1 + ans[i] << " ";
  }
  cout << endl;
}