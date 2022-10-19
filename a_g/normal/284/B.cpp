#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c = count(s.begin(), s.end(), 'I');
  if (c == 0) {
    cout << count(s.begin(), s.end(), 'A') << endl;
  }
  else if (c == 1) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}