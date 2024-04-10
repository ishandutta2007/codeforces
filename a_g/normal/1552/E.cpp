#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  int t = (n-1)/(k-1)+1;
  vector<vector<int>> positions(n);
  vector<pair<int, int>> ans(n);
  set<int> colors;
  for (int i = 0; i < n; i++) colors.insert(i);
  for (int i = 0; i < n*k; i++) {
    int c;
    cin >> c;
    positions[c-1].push_back(i+1);
  }
  for (int i = 0; i < k-1; i++) {
    vector<pair<int, int>> candidates(n);
    for (int j = 0; j < n; j++) {
      candidates[j] = {positions[j][i+1], j};
    }
    sort(candidates.begin(), candidates.end());
    int used = 0;
    for (int j = 0; j < n; j++) {
      if (used >= t) break;
      int c = candidates[j].second;
      if (colors.count(c)) {
        colors.erase(c);
        used++;
        ans[c] = {positions[c][i], positions[c][i+1]};
      }
    }
  }


  for (pair<int, int> p: ans) {
    cout << p.first << " " << p.second << endl;
  }
}