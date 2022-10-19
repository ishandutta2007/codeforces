#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << (count(s.begin(), s.end(), 'N') == 1 ? "NO" : "YES") << '\n';
  }
}