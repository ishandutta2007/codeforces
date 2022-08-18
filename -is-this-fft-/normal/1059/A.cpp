#include <iostream>

using namespace std;

int main () {
  int n, l, a;
  cin >> n >> l >> a;

  int curt = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int ti, li;
    cin >> ti >> li;

    ans += (ti - curt) / a;
    curt = ti + li;
  }

  ans += (l - curt) / a;
  cout << ans << endl;
}