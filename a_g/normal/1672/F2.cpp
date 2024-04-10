#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), freq(n+1), indeg(n+1);
    vector<vector<int>> out(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      freq[a[i]]++;
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    int m = max_element(freq.begin(), freq.end()) - freq.begin();
    for (int i = 0; i < n; i++) {
      if (a[i] == m || b[i] == m) continue;
      out[a[i]].push_back(b[i]);
      indeg[b[i]]++;
    }
    vector<int> que;
    for (int i = 1; i <= n; i++) {
      if (indeg[i] == 0) que.push_back(i);
    }
    for (int i = 0; i < que.size(); i++) {
      for (int j: out[que[i]]) {
        indeg[j]--;
        if (indeg[j] == 0) {
          que.push_back(j);
        }
      }
    }
    cout << (que.size() == n ? "AC" : "WA") << '\n';
  }
}