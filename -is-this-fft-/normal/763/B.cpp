#include <iostream>
#include <algorithm>

using namespace std;

int main () {
  int rectcnt;
  cin >> rectcnt;

  cout << "YES" << '\n';
  for (int i = 0; i < rectcnt; i++) {
    int ux, uy, lx, ly;
    cin >> ux >> uy >> lx >> ly;
    
    int ans = 0;
    if (abs(ux) % 2) {
      ans++;
    }

    if (abs(uy) % 2) {
      ans += 2;
    }

    ans++;
    cout << ans << '\n';
  }
}