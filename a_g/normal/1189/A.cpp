#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (2*count(s.begin(), s.end(), '0') != n) {
    cout << "1\n" << s << '\n';
    return 0;
  }
  cout << "2\n" << s[0] << " " << s.substr(1) << '\n';
}