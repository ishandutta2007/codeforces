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

  string s;
  cin >> s;

  int cur = 0;
  vector<int> ans;

  int n = s.length();
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'a' + (cur % 2)) {
      cur++;
      ans.push_back(1);
    } else {
      ans.push_back(0);
    }
  }

  reverse(all(ans));
  for (int x : ans)
    cout << x << " ";
  cout << "\n";

}