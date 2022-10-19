#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long s;
    cin >> n >> s;
    cout << s/(1LL*n*n) << '\n';
  }
}