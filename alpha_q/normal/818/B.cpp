#include <bits/stdc++.h> 

using namespace std;

const int N = 105;

set <int> s;
int n, m, a[N], l[N];

int main() {
  cin >> n >> m;
  memset(a, -1, sizeof a);
  for (int i = 1; i <= m; ++i) {
    cin >> l[i];
  } 
  for (int i = 1; i < m; ++i) {
    int cur = (n + l[i + 1] - l[i]) % n;
    if (cur == 0) cur = n;
    if (a[l[i]] != -1 and a[l[i]] != cur) {
      puts("-1");
      return 0;
    }
    a[l[i]] = cur;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) continue;
    if (s.count(a[i])) {
      puts("-1");
      return 0;
    }
    s.insert(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != -1) continue;
    for (int j = 1; j <= n; ++j) {
      if (!s.count(j)) {
        a[i] = j;
        s.insert(j);
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  } cout << endl;
  return 0;
}