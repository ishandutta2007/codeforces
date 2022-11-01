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

  bool solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int cnt_a = count(s.begin(), s.end(), 'A');
    int cnt_b = count(s.begin(), s.end(), 'B');
    if (cnt_a != a + c + d || cnt_b != b + c + d) {
      return 0;
    }

    int n = s.size();

    int last = 0;
    vector<pair<int, int>> seg;
    for (int i = 0; i < n; ++i) {
      if (s[i] == s[i + 1]) {
        seg.push_back({last, i});
        last = i + 1;
      }
    }
    seg.push_back({last, n - 1});

    vector<int> ab, ba;
    int cnt_any = 0;
    for (auto [l, r] : seg) {
      // cout << l << " " << r<< endl;
      if ((r - l + 1) % 2 == 0) {
        if (s[l] == 'A') {
          ab.push_back(r - l + 1);
        } else {
          ba.push_back(r - l + 1);
        }
      } else {
        cnt_any += (r - l + 1) / 2;
      }
    }

    //cout << "any: " << cnt_any << endl;

    sort(ab.begin(), ab.end(), greater<int>());
    sort(ba.begin(), ba.end(), greater<int>());

    //for (auto e : ab) cout << e << " ";cout << endl;
    //for (auto e : ba) cout << e << " ";cout << endl;

    proc(c, ab);
    proc(d, ba);
    
    for (auto e : ab) {
      cnt_any += ((e - 1) / 2);
    }
    for (auto e : ba) {
      cnt_any += ((e - 1) / 2);
    }

    if (c + d <= cnt_any) {
      return true;
    }
    return false;

  }

private:
  void proc(int& c, vector<int>& ab) {
    while (c && !ab.empty()) {
      c--;
      ab.back() -= 2;
      if (ab.back() <= 1) {
        ab.pop_back();
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    bool ok = Solver{}.solve();
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}