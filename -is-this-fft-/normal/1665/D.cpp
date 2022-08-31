#include <iostream>

using namespace std;

typedef long long ll;

ll ask (int a, int b) {
  cout << "? " << a << " " << b << endl;

  ll resp;
  cin >> resp;
  return resp;
}

void report (int x) {
  cout << "! " << x << endl;
}

void solve () {
  int x = 0;
  for (int i = 0; i < 29; i++) {
    int mod = 1 << (i + 1);
    ll resp = ask(mod - x, 2 * mod - x);
    if (resp % mod != 0) {
      x |= 1 << i;
    }
  }

  // special for 29
  int pw = 1 << 29;
  int mod = 1 << 30;
  ll resp = ask(pw - x, 3 * pw - x);
  if (resp % mod == 0) {
    x |= 1 << 29;
  }
  
  report(x);
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}