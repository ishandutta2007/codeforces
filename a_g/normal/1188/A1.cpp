#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> degs(n);
  n--;
  while(n--) {
    int u, v;
    cin >> u >> v;
    degs[u-1]++, degs[v-1]++;
  }
  for (int i: degs) {
    if (i == 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}