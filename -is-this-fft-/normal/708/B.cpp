#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

void failure () {
  cout << "Impossible" << endl;
  exit(0);
}

int pairc (int x) {
  return (x * (x - 1)) / 2;
}

const int MAX_A = 1e9 + 5;

int main () {
  ll a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;

  if (a00 + a01 + a10 + a11 == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  map<int, int> orig;
  for (int i = 1; pairc(i) < MAX_A; i++) {
    orig[pairc(i)] = i;
  }

  if ((a00 == 0 || a11 == 0) && a01 + a10 == 0) {
    ll pc;
    int ch;
    if (a00 > 0) {
      pc = a00;
      ch = 0;
    } else {
      pc = a11;
      ch = 1;
    }

    if (orig.count(pc) == 0) failure();
    int cnt = orig[pc];
    for (int i = 0; i < cnt; i++) {
      cout << ch;
    }
    cout << endl;
  } else {
    if (orig.count(a00) == 0) {
      failure();
    }
    if (orig.count(a11) == 0) {
      failure();
    }

    ll c0 = orig[a00], c1 = orig[a11];

    if (c0 * c1 != a01 + a10) {
      failure();
    }

    for (int i = 0; c0 > 0 || c1 > 0; i++) {
      if (c1 > 0 && a10 >= c0) {
        cout << 1;
        c1--;
        a10 -= c0;
      } else {
        cout << 0;
        c0--;
      }
    }
    cout << endl;
  }
}