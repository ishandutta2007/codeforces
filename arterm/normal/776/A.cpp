#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  set<string> cur;

  string a, b;

  cin >> a >> b;
  cout << a << " " << b << endl;
  cur.insert(a);
  cur.insert(b);

  int n;
  cin >> n;
  while (n--) {
    string t, s;
    cin >> t >> s;
    cur.erase(t);
    cur.insert(s);
    for (auto x : cur)
      cout << x << " ";
    cout << endl;
  }

}