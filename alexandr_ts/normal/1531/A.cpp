#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void solve() {
  string col = "blue";
  bool lock = false;
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s == "lock") {
      lock = true;
    } else if (s == "unlock") {
      lock = false;
    } else if (!lock) {
      col = s;
    }
  }
  cout << col << endl;

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}