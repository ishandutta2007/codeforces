#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (n&1 || n < 4) {
      cout << "-1\n";
      continue;
    }
    long long mb = n/6;
    if ((n-6*mb)%4 != 0) mb--;
    long long lb = 0;
    if (n%4 != 0) lb++;
    cout << mb+(n-6*mb)/4 << " " << lb+(n-6*lb)/4 << '\n';
  }
}