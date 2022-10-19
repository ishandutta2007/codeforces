#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    string t(s.begin(), s.end());
    sort(t.begin(), t.end());
    int ops = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) ops = 1;
    }
    cout << ops << endl;
    if (ops) {
      vector<int> prefsum(n+1, 0);
      for (int i = 0; i < n; i++) prefsum[i+1] = prefsum[i] + s[i] - '0';
      int cut = 0;
      for (int i = 0; i <= n; i++) {
        if (prefsum[i] == n-i-prefsum[n]+prefsum[i]) {
          cut = i;
          break;
        }
      }
      vector<int> indices;
      for (int i = 0; i < cut; i++) {
        if (s[i] == '1') indices.push_back(i);
      }
      for (int i = cut; i < n; i++) {
        if (s[i] == '0') indices.push_back(i);
      }
      cout << indices.size() << " ";
      for (int x: indices) cout << x+1 << " ";
      cout << endl;
    }
  }
}