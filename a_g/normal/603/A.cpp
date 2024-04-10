#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int k = 0;
  int groups = 0;
  char prev = s[0];
  int size = 0;
  for (char c: s) {
    if (c == prev) {
      size++;
    }
    else {
      k += size-1;
      groups++;
      prev = c;
      size = 1;
    }
  }
  groups++;
  k += size-1;
  cout << groups + min(k, 2) << endl;
}