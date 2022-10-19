#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N];
vector<pair<int, int>> ops;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int, vector<int>> compressor;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    compressor[a[i]].push_back(i);
  }

  int id = 1;
  for (auto & p: compressor) {
    vector<int> x = p.second;
    for (int i: x) a[i] = id++;
  }
  for (int i = n; i > 1; i--) {
    vector<pair<int, int>> inversions;
    for (int j = 1; j < i; j++) {
      if (a[j] > a[i]) {
        inversions.push_back(make_pair(a[j], j));
      }
    }
    sort(inversions.begin(), inversions.end());
    for (pair<int, int>& p: inversions) {
      ops.push_back(make_pair(p.second, i));
      swap(a[p.second], a[i]);
    }
  }

  cout << ops.size() << '\n';
  for (pair<int, int>& p: ops) {
    cout << p.first << " " << p.second << '\n';
  }

}