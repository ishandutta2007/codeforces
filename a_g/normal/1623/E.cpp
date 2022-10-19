#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int l[N];
int r[N];
int dist_to_marked[N];
bool marked[N];
bool ban[N];
char nextchar[N];
char y, z;
int n, k;
string ans;
string label;

void dfs1(int v, int p) {
  if (r[v]) dfs1(r[v], v);
  if (y == label[v]) {
    nextchar[v] = z;
  }
  else {
    nextchar[v] = y;
    z = y;
    y = label[v];
  }
  if (l[v]) dfs1(l[v], v);
}

void dfs2(int v, int p) {
  dist_to_marked[v] = dist_to_marked[p] + 1;
  if (ban[p]) ban[v] = 1;
  if (l[v]) {
    dfs2(l[v], v);
    if (marked[l[v]]) {
      marked[v] = 1;
      dist_to_marked[v] = 0;
    }
  }
  if (!marked[v] && nextchar[v] < label[v]) {
    ban[v] = 1;
  }
  if (!ban[v] && nextchar[v] > label[v] && dist_to_marked[v] <= k) {
    k -= dist_to_marked[v];
    marked[v] = 1;
    dist_to_marked[v] = 0;
  }
  ans.push_back(label[v]);
  if (marked[v]) ans.push_back(label[v]);
  if (r[v]) {
    dfs2(r[v], v);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  cin >> label;
  label = "!" + label;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }

  dfs1(1, 1);
  dfs2(1, 1);
  cout << ans << endl;
}