#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]++;
    }
    if (freq.size() > 4) {
      cout << "NO\n";
      continue;
    }
    vector<int> a;
    for (pair<int, int> p: freq) {
      for (int i = 0; i < min(3, p.second); i++) {
        a.push_back(p.first);
      }
    }
    int m = a.size();
    bool good = 1;
    for (int i = 0; i < m; i++) {
      for (int j = i+1; j < m; j++) {
        for (int k = j+1; k < m; k++) {
          long long v = a[i]+a[j]+a[k];
          if (!freq.count(v)) {
            good = 0;
          }
        }
      }
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}