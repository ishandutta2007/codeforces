#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<int> t;
  vector<int> st;

  int x = 1;
  for (char c : s) {
    if (c == '(') {
      t.push_back(x);
      st.push_back(x);
      ++x;
    } else {
      assert(!st.empty());
      t.push_back(-st.back());
      st.pop_back();
    }
  }

  int td = (n - k) / 2;
  string ans;
  for (int x : t)
    if (abs(x) > td) {
      if (x > 0)
        ans.push_back('(');
      else
        ans.push_back(')');
    }
  cout << ans << "\n";

}