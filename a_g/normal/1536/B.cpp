#include <bits/stdc++.h>
using namespace std;

string f(int n) {
  if (n < 26) return string(1, 'a'+n);
  return f(n/26-1) + (char)('a'+ n % 26);
}

int g(string s) {
  int n = s.size();
  if (n == 1) return s[0]-'a';
  return s[n-1] - 'a' + 26*(g(s.substr(0, n-1))+1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> found(1e5, 0);
    for (int i = 0; i < n; i++) {
      for (int d = 1; d <= min(3, n-i); d++) {
        string t = s.substr(i, d);
        found[g(t)] = 1;
      }
    }
    for (int i = 0; i < 1e5; i++) {
      if (!found[i]) {
        cout << f(i) << endl;
        break;
      }
    }
  }
}