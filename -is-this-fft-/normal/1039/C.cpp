#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long llong;

const int MOD = 1000000007;
struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
    val = _val % MOD;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint((p.val * q.val) % MOD);
}

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

const int maxv = 500005;

int root [maxv], age [maxv];
int cur_gen;

void reset () {
  cur_gen++;
}

int getroot (int u) {
  if (age[u] < cur_gen) {
    age[u] = cur_gen;
    root[u] = u;
  }
  return root[u];
}

int find (int u) {
  if (getroot(u) != u) {
    root[u] = find(getroot(u));
  }
  return getroot(u);
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (u != v) {
    root[u] = v;
  }
}

llong arr [maxv];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec, k;
  cin >> vertexc >> edgec >> k;

  for (int i = 1; i <= vertexc; i++) {
    cin >> arr[i];
  }
  
  vector<pair<llong, pair<int, int>>> edges (edgec);
  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].second.first >> edges[i].second.second;

    edges[i].first = arr[edges[i].second.first] ^ arr[edges[i].second.second];
  }

  sort(edges.begin(), edges.end());

  vector<vector<pair<int, int>>> blocks;
  for (int i = 0; i < edgec; i++) {
    if (i == 0 || edges[i].first != edges[i - 1].first) {
      blocks.push_back(vector<pair<int, int>> (0));
    }
    blocks.back().push_back(edges[i].second);
  }

  int specc = 0;
  modint ans (0);
  for (int i = 0; i < (int) blocks.size(); i++) {
    reset();
    set<int> cur;
    for (int j = 0; j < (int) blocks[i].size(); j++) {
      cur.insert(blocks[i][j].first);
      cur.insert(blocks[i][j].second);
      merge(blocks[i][j].first, blocks[i][j].second);
    }

    int compc = 0;
    for (int u : cur) {
      if (find(u) == u) {
        compc++;
      }
    }

    specc++;
    ans = ans + (modint(2) ^ (vertexc + compc - (int) cur.size()));
  }

  ans = ans + ((modint(2) ^ k) - specc) * (modint(2) ^ vertexc);
  cout << ans.val << endl;
}