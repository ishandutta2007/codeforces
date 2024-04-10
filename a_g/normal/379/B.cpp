#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    while (x--) {
      cout << (n ? "RLP" : "LRP");
    }
    if (n) cout << 'R';
  }
  cout << '\n';
}