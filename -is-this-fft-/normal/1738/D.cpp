#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> foll [MAX_N];

bool cmp (int u, int v) {
  return foll[u].size() < foll[v].size();
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i <= n + 1; i++) {
    foll[i].clear();
  }

  vector<int> b (n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int K = 0;
  for (int i = 1; i <= n; i++) {
    if (i < b[i]) {
      K++;
    }
  }

  for (int i = 1; i <= n; i++) {
    foll[b[i]].push_back(i);
  }

  for (int i = 0; i <= n + 1; i++) {
    sort(foll[i].begin(), foll[i].end(), cmp);
  }

  int prev = foll[0].empty() ? n + 1 : 0;
  vector<int> ans;
  while (!foll[prev].empty()) {
    for (int u : foll[prev]) {
      ans.push_back(u);
    }

    prev = foll[prev].back();
  }
  
  cout << K << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}