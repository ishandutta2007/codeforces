#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> pos(n), c(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    pos[x] = i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    c[(pos[x]-i+n)%n]++;
  }
  cout << *max_element(c.begin(), c.end()) << '\n';
}