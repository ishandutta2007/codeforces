#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> deltas(n);
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        cur += i;
        deltas.push_back(n-1-2*i);
      }
      else {
        cur += n-1-i;
        deltas.push_back(2*i+1-n);
      }
    }
    sort(deltas.begin(), deltas.end(), greater<int>());
    for (int k = 0; k < n; k++) {
      if (deltas[k] > 0) cur += deltas[k];
      cout << cur << ' ';
    }
    cout << '\n';
  }
}