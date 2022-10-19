#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long k;
  cin >> k;
  vector<int> c(10, 1);
  long long z = 1;
  int i = 0;
  while (z < k) {
    z = z*(c[i]+1)/c[i];
    c[i]++;
    i = (i+1)%10;
  }
  for (int i = 0; i < 10; i++) {
    cout << string(c[i], "codeforces"[i]);
  }
  cout << '\n';
}