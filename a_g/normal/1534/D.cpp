#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int d[N][N];
int n;

void query(int r) {
  cout << "? " << r << endl;
  for (int i = 1; i <= n; i++) {
    cin >> d[r][i];
    d[i][r] = d[r][i];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  query(1);
  vector<int> odd;
  vector<int> even;
  for (int i = 2; i <= n; i++) {
    if (d[1][i]&1) odd.push_back(i);
    else even.push_back(i);
  }
  vector<int> b = (odd.size() > even.size() ? even : odd);
  for (int k: b) query(k);
  if (b == even) b.push_back(1);
  vector<pair<int, int>> edges;
  for (int k: b) {
    for (int i = 1; i <= n; i++) {
      if (d[k][i] == 1) {
        edges.emplace_back(min(k, i), max(k, i));
      }
    }
  }
  sort(edges.begin(), edges.end());
  edges.resize(unique(edges.begin(), edges.end())-edges.begin());
  cout << "!" << endl;
  for (pair<int, int>& e: edges) {
    cout << e.first << " " << e.second << endl;
  }
}