#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (a[i] > b[i]) count++;
  }
  return (count > 2);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> athletes(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> athletes[i][j];
      }
    }
    vector<int> winner = athletes[0];
    int index = 0;
    bool valid = 1;
    for (int i = 1; i < n; i++) {
      if (compare(winner, athletes[i])) {
        winner = athletes[i];
        index = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != index && compare(winner, athletes[i])) {
        valid = 0;
      }
    }
    cout << (valid ? index+1 : -1) << endl;
  }
}