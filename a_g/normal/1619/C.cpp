#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve() {
  ll a, s;
  cin >> a >> s;
  string b = "";
  while (a | s) {
    int x = a % 10;
    int y = s % 10;
    if (x > y) {
      if ((s/10)%10 != 1) return "-1";
      b.push_back('0'+10+y-x);
      s /= 100;
      a /= 10;
    }
    else {
      b.push_back('0'+y-x);
      s /= 10;
      a /= 10;
    }
  }
  while (b.size() && b.back() == '0') b.pop_back();
  reverse(b.begin(), b.end());
  return b;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << '\n';
  }
}