#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<char> z;
    for (char c: s) {
      if ((c-'0')&1) z.push_back(c);
    }
    if (z.size() <= 1) {
      cout << "-1\n";
      continue;
    }
    cout << z[0] << z[1] << '\n';
  }
}