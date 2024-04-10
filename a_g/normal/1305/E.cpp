#include <bits/stdc++.h>
using namespace std;

int c[5000*5000];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> ans(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int x = (i ? ans[i-1]+1 : 1);
    while (c[x]+cur > m) x++;
    cur += c[x];
    for (int j = 0; j < i; j++) {
      c[ans[j]+x]++;
    }
    ans[i] = x;
  }
  if (cur != m) {
    cout << "-1\n";
  }
  else {
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}