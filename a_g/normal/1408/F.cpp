#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ops;

void merge(int l, int start) {
  if (!l) return;
  merge(l-1, start);
  merge(l-1, start+(1<<(l-1)));
  for (int i = 0; i < (1<<(l-1)); i++) {
    ops.emplace_back(start+i, start+i+(1<<(l-1)));
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int k = 31-__builtin_clz(n);
  merge(k, 1);
  merge(k, n-(1<<k)+1);

  cout << ops.size() << '\n';
  for (pair<int, int> p: ops) {
    cout << p.first << " " << p.second << '\n';
  }
}