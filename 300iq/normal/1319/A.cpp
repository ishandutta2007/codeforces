#include <bits/stdc++.h>

using namespace std;

void stress() {

}

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return (x != 1);
}

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  int n;
  cin >> n;
  int x = 0, y = 0;
  vector <int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    if (r[i]) x++;
  }
  vector <int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i]) y++;
  }
  vector <int> mda;
  for (int i = 0; i < n; i++) {
    if (r[i] && !b[i]) {
      mda.push_back(i);
    }
  }
  if (mda.empty()) {
    cout << -1 << endl;
  } else {
    int need = (x - y);
    if (need > 0) {
      cout << 1 << endl;
      return 0;
    }
    int ok = (-need + 1 + (int) mda.size() - 1) / (int) mda.size();
    cout << 1 + ok << endl;
  }
}