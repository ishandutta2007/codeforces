#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen(".in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int cnt = 0;
  for (char c : s)
    if (c == 'a')
      ++cnt;

  cout << min(2 * cnt - 1, (int) s.length()) << "\n";

}