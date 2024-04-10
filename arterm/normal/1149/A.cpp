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

  int n;
  int a = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1)
      ++a;
    else
      ++b;
  }

  if (b > 0) {
    cout << "2 ";
    --b;
  }

  bool after = false;

  if (a % 2 == 0 && a > 0) {
    --a;
    after = true;
  }

  for (int i = 0; i < a; ++i)
    cout << "1 ";
  for (int i = 0; i < b; ++i)
    cout << "2 ";
  if (after)
    cout << "1 ";
  cout << "\n";
}