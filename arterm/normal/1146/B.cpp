#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int cnt = 0;
  for (char c : s)
    if (c != 'a')
      ++cnt;

  cnt /= 2;

  string t = s.substr(0, s.length() - cnt);

  string h = t;

  for (char c : t)
    if (c != 'a')
      h.push_back(c);

  if (h == s) {
    cout << t << "\n";
  } else {
    cout << ":(\n";
  }
}