#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        a.push_back({p[i], i});
      }
      else {
        b.push_back({p[i], i});
      }
    }
    vector<int> q(n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int x = 1;
    for (pair<int, int> v: b) {
      q[v.second] = x++;
    }
    for (pair<int, int> v: a) {
      q[v.second] = x++;
    }
    for (int i: q) cout << i << ' ';
    cout << '\n';
  }
}