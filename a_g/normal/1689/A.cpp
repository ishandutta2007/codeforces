#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end(), greater<char>());
    sort(b.begin(), b.end(), greater<char>());
    string c;
    int last = -1;
    int cur = 0;
    while (a.size() && b.size()) {
      int n = -1;
      if (cur == k) {
        n = 1-last;
      }
      else {
        n = (a.back() < b.back() ? 0 : 1);
      }
      if (n) {
        c.push_back(b.back());
        b.pop_back();
      }
      else {
        c.push_back(a.back());
        a.pop_back();
      }
      if (n == last) {
        cur++;
      }
      else {
        last = n;
        cur = 1;
      }
    }
    cout << c << '\n';
  }
}