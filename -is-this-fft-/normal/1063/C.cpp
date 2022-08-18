#include <iostream>
#include <string>

using namespace std;

int inv;
bool query (int x, int y) {
  cout << x << " " << y << endl;

  string res;
  cin >> res;

  return (res[0] == 'b') ^ inv;
}

int main () {
  int n;
  cin >> n;

  inv = query(0, 1);

  if (n == 1) {
    cout << "1 0 1 1" << endl;
    return 0;
  }

  int ans = 0;
  for (int k = 1 << (n - 2); k != 0; k /= 2) {
    int res = query(ans + k, 1);
    if (res == 0) ans += k;
  }
  cout << ans + 1 << " " << 2 << " " << ans << " " << 0 << endl;
}