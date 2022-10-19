#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const int M = 4005;
int G[N];

struct vtx {
  int to[N];
  int go[N];
  int val;
  int par;
  int wt;
  int sufflink = -1;
} trie[M];
int num_vtx = 1;

void insert(vector<int>& a, int c) {
  int cur = 0;
  for (int x: a) {
    if (!trie[cur].to[x]) {
      trie[num_vtx].val = x;
      trie[num_vtx].par = cur;
      trie[cur].to[x] = num_vtx++;
    }
    cur = trie[cur].to[x];
  }
  trie[cur].wt += c;
}

int go(int v, int x);

int get_link(int v) {
  if (trie[v].sufflink == -1) {
    if (v == 0 || trie[v].par == 0) {
      trie[v].sufflink = 0;
    }
    else {
      trie[v].sufflink = go(get_link(trie[v].par), trie[v].val);
    }
    get_link(trie[v].sufflink);
    trie[v].wt += trie[trie[v].sufflink].wt;
  }
  return trie[v].sufflink;
}

int go(int v, int x) {
  if (trie[v].go[x] == -1) {
    if (trie[v].to[x]) {
      trie[v].go[x] = trie[v].to[x];
    }
    else if (v == 0) {
      trie[v].go[x] = 0;
    }
    else {
      trie[v].go[x] = go(get_link(v), x);
    }
  }
  return trie[v].go[x];
}

pair<int, pair<int, int>> dp[1<<N][M];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < M; i++) {
    fill(trie[i].go, trie[i].go+N, -1);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    fill(G, G+N, 0);
    int c;
    string s;
    cin >> c >> s;
    int m = (int)s.size();
    for (int j = 0; j + 1 < m; j++) {
      int u = s[j]-'a';
      int v = s[j+1]-'a';
      G[u] |= 1<<v;
      G[v] |= 1<<u;
    }
    bool ok = 1;
    int e = -1;
    for (int j = 0; j < N; j++) {
      if (__builtin_popcount(G[j]) > 2) ok = 0;
      else if (__builtin_popcount(G[j]) == 1) e = j;
    }
    if (!ok || e == -1) continue;

    vector<int> a(1, e);
    while (G[a.back()]) {
      int u = a.back();
      int v = __lg(G[u]);
      G[v] ^= 1<<u;
      a.push_back(v);
    }
    insert(a, c);
    reverse(a.begin(), a.end());
    insert(a, c);
  }

  for (int i = 0; i < num_vtx; i++) {
    for (int j = 0; j < N; j++) {
      go(i, j);
    }
  }
  
  for (int i = 0; i < (1<<N); i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j] = make_pair(-1, make_pair(-1, -1));
    }
  }
  dp[0][0].first = 0;
  for (int mask = 0; mask < (1<<N); mask++) {
    for (int v = 0; v < num_vtx; v++) {
      if (dp[mask][v].first == -1) continue;
      dp[mask][v].first += trie[v].wt;
      for (int x = 0; x < N; x++) {
        if ((mask>>x)&1) continue;
        int u = go(v, x);
        dp[mask|1<<x][u] = max(dp[mask|1<<x][u],
            make_pair(dp[mask][v].first, make_pair(mask, v)));
      }
    }
  }
  int cur_v = 0;
  int mask = (1<<N)-1;
  for (int v = 0; v < num_vtx; v++) {
    if (dp[mask][v] > dp[mask][cur_v]) {
      cur_v = v;
    }
  }
  while (mask) {
    int x = __lg(mask^dp[mask][cur_v].second.first);
    cout << (char)(x+'a');
    tie(mask, cur_v) = dp[mask][cur_v].second;
  }
  cout << '\n';
}