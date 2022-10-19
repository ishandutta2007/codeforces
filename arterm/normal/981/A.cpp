#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  auto is = [](string s) -> bool {
    for (int i = 0; i < (int) s.length(); ++i)
      if (s[i] != s[s.length() - 1 - i])
        return false;
    return true;
  };

  int ans = 0;
  for (int len = 1; len <= (int) s.length(); ++len)
    for (int i = 0; i + len <= (int) s.length(); ++i)
      if (!is(s.substr(i, len)))
        ans = len;

  cout << ans << endl;

}