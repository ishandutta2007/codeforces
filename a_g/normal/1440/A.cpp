#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    cout << a*min(c0, c1+h) + b*min(c1, c0+h) << '\n';
  }
}