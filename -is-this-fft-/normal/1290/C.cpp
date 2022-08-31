#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 5;

int root [MAX_N];
int wsz [MAX_N];
int bsz [MAX_N];
int color [MAX_N];
int in_stone [MAX_N];

pair<int, int> find (int u) {
  if (root[u] == u) return make_pair(u, 1);
  pair<int, int> ans = find(root[u]);
  ans.second *= color[u];
  return ans;
}

int ans;

void del_ans (int u) {
  if (in_stone[u] == -1) ans -= bsz[u];
  if (in_stone[u] == 1) ans -= wsz[u];
  if (in_stone[u] == 0) ans -= min(bsz[u], wsz[u]);
}

void add_ans (int u) {
  if (in_stone[u] == -1) ans += bsz[u];
  if (in_stone[u] == 1) ans += wsz[u];
  if (in_stone[u] == 0) ans += min(bsz[u], wsz[u]);
}

void merge (int u, int v, int sgn) {
  pair<int, int> up = find(u);
  pair<int, int> vp = find(v);
  u = up.first;
  v = vp.first;
  sgn *= up.second * vp.second;

  if (u == v) return;

  if (wsz[u] + bsz[u] < wsz[v] + bsz[v]) {
    swap(u, v);
  }

  del_ans(u);
  del_ans(v);
  
  if (in_stone[v] != 0) {
    in_stone[u] = sgn * in_stone[v];
  }
  
  if (sgn == 1) {
    wsz[u] += wsz[v];
    bsz[u] += bsz[v];
  } else {
    wsz[u] += bsz[v];
    bsz[u] += wsz[v];
  }

  add_ans(u);
  
  root[v] = u;
  color[v] = sgn;
}

void set_in_stone (int u, int sgn) {
  pair<int, int> up = find(u);
  del_ans(up.first);
  in_stone[up.first] = up.second * sgn;
  add_ans(up.first);
}

int arr [MAX_N];
vector<int> cont [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
    color[i] = 1;
    wsz[i] = 1;
    bsz[i] = 0;
  }

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;

    arr[i] = c - '0';
  }

  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;

    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;

      cont[x].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cont[i].size() == 1) {
      if (arr[i] == 0) {
        set_in_stone(cont[i][0], 1);
      } else {
        set_in_stone(cont[i][0], -1);
      }
    } else if (cont[i].size() == 2) {
      if (arr[i] == 0) {
        merge(cont[i][0], cont[i][1], -1);
      } else {
        merge(cont[i][0], cont[i][1], 1);
      }
    }
    
    cout << ans << endl;
  }
}