#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  string solve() {
    string s;
    cin >> s;
    for (int i = (int)s.size() - 1; i >= 1; --i) {
      int c1 = s[i] - '0';
      int c2 = s[i - 1] - '0';
      if (c1 + c2 >= 10) {
        string ans = s.substr(0, i - 1);
        ans += (char)('1');
        ans += (char)((c1 + c2) % 10 + '0');
        ans += s.substr(i + 1, (int)s.size() - (i + 1));
        return ans;
      }
    }

    string ans = "";
    ans += (char)((int)s[0] + s[1] - '0');
    ans += s.substr(2, (int)s.size() - 2);
    return ans;
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << Solver{}.solve() << "\n";
  }
}