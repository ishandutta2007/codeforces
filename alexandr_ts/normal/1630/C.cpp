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

  void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mx(n + 1, -INF);
    vector<int> mn(n + 1, INF);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mx[a[i]] = max(mx[a[i]], i);
      mn[a[i]] = min(mn[a[i]], i);
    }
    vector<pair<int, int>> segs;
    for (int i = 1; i <= n; ++i) {
      if (mn[i] < mx[i]) {
        segs.push_back({mn[i], mx[i]});
      }
    }
    sort(segs.begin(), segs.end());
    vector<pair<int, int>> cur_segs;
    int max_r = -1;
    int ans = 0;
    for (auto s : segs) {
      if (s.first > max_r) {
        if (!cur_segs.empty()) {
          ans += calc(cur_segs);
          cur_segs.clear();
        }
      }
      cur_segs.push_back(s);
      max_r = max(max_r, s.second);
    }
    if (!cur_segs.empty()) {
      ans += calc(cur_segs);
    }
    cout << ans << endl;
  }

private:
  int calc(const vector<pair<int, int>>& segs) {
    //for (auto s : segs) cout << s.first << " " << s.second << endl; cout << endl;
    int l = segs[0].first;
    int r = segs.back().second;
    for (auto s : segs) {
       r = max(r, s.second);
    }
    int ans = 1;

    int best_next = 0;
    int last = 0;
    for (int i = 1; i < (int)segs.size(); ++i) {
      if (segs[i].first > segs[last].second) {
        if (best_next != last) {
          ans++;
        }
        last = best_next;
        best_next = i;
      } else {
        if (segs[i].second > segs[best_next].second) {
          best_next = i;
        }
      }
    }
    if (segs[last].second < r) {
      ans++;
    }
    int answer = r - l + 1 - (ans + 1);
    // cout << answer << endl;
    return answer;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}