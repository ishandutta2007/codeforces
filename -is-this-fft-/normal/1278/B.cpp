#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_SQ = 1e5;

ll tria [MAX_SQ];

void solve () {
  int a, b;
  cin >> a >> b;

  int x = b - a;
  if (x < 0) x = -x;

  for (int i = 0; i < MAX_SQ; i++) {
    if (x % 2 == tria[i] % 2 && x <= tria[i]) {
      cout << i << '\n';
      return;
    }
  }
}

int main () {
  tria[0] = 0;
  for (int i = 1; i < MAX_SQ; i++) {
    tria[i] = tria[i - 1] + i;
  }
  
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}