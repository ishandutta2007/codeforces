#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    while (s.size() && s.back() == '1') {
      s.pop_back();
      k++;
      n--;
    }
    int i = 0;
    while (i < n && s[i] == '0') i++;
    if (i == n) {
      cout << s;
    }
    else {
      cout << string(i+1, '0');
    }
    cout << string(k, '1');
    cout << '\n';
  }
}