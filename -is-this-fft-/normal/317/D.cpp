#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int grundy [] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5,
                       9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

int main () {
  int n;
  cin >> n;

  int xr = 0;
  set<int> inter;
  for (int i = 2; i * i <= n; i++) {
    bool add = !inter.count(i);
    int sz = 0;
    ll base = i;
    ll cur = base;
    do {
      sz++;
      inter.insert(cur);
      cur *= base;
    } while (cur <= n);

    if (add) {
      xr ^= grundy[sz];
    }
  }

  xr ^= (n - (int) inter.size()) % 2;
  if (xr != 0) {
    cout << "Vasya" << endl;
  } else {
    cout << "Petya" << endl;
  }
}