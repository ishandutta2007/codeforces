#include <iostream>
#include <set>

using namespace std;

int apply (int x) {
  return x + (x % 10);
}

int norm (int x) {
  if (x % 10 == 5) {
    return apply(x);
  }

  if (x % 10 == 0) {
    return x;
  }

  while (x % 10 != 2) {
    x = apply(x);
  }

  x /= 10;
  if (x % 2 == 0) return 1;
  else return 2;
}

void solve () {
  int n;
  cin >> n;

  set<int> seen;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    seen.insert(norm(x));
  }

  if ((int) seen.size() == 1) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}