#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int wins = 0;
    int pairs = 0;
    vector<int> gaps;
    int len = 0;
    bool start = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        if (i && s[i-1] == 'W') pairs++;
        wins++;
        if (len && start) gaps.push_back(len);
        len = 0;
        start = 1;
      }
      else {
        len++;
      }
    }
    sort(gaps.begin(), gaps.end());
    for (int v: gaps) {
      if (v <= k) {
        k -= v;
        wins += v;
        pairs += v+1;
      }
      else {
        wins += k;
        pairs += k;
        k = 0;
      }
    }

    if (k > 0) {
      if (wins) {
        int m = min(k, n-wins);
        wins += m;
        pairs += m;
      }
      else {
        wins = k;
        pairs = max(0, k-1);
      }
    }
    cout << pairs+wins << '\n';
  }
}