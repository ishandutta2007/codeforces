#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  int c0 = 0;
  while(c0 * (c0 - 1) / 2 < a00)
    c0++;
  if(c0 * (c0 - 1) / 2 != a00) {
    cout << "Impossible\n";
    return 0;
  }
  int c1 = 0;
  while(c1 * (c1 - 1) / 2 < a11)
    c1++;
  if(c1 * (c1 - 1) / 2 != a11) {
    cout << "Impossible\n";
    return 0;
  }
  if(a00 == 0) {
    if(a01 == 0 && a10 == 0) {
      if(a11 == 0) {
        cout << 0 << '\n';
        return 0;
      }
      for(int i = 0; i < c1; i++)
        cout << 1;
      cout << '\n';
      return 0;
    }
    c0 = 1;
  }
  if(a11 == 0) {
    if(a01 == 0 && a10 == 0) {
      for(int i = 0; i < c0; i++)
        cout << 0;
      cout << '\n';
      return 0;
    }
    c1 = 1;
  }
  long long s = c0 * c1;
  if(s != a01 + a10) {
    cout << "Impossible\n";
    return 0;
  }
  while(a10 >= c0) {
    cout << 1;
    c1--;
    a10 -= c0;
  }
  for(int i = 0; i < c0 - a10; i++)
    cout << 0;
  if(c1) {
    cout << 1;
    c1--;
  }
  for(int i = 0; i < a10; i++)
    cout << 0;
  for(int i = 0; i < c1; i++)
    cout << 1;
  cout << '\n';
  return 0;
}