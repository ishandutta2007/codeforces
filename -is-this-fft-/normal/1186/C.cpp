#include <iostream>
#include <string>

using namespace std;

int main () {
  string a, b;
  cin >> a >> b;

  int n = (int) a.size();
  int k = (int) b.size();

  int par = 0, ans = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] == '1') par++;
    if (b[i] == '1') par++;
  }
  if (par % 2 == 0) ans++;

  for (int i = k; i < n; i++) {
    if (a[i] == '1') par++;
    if (a[i - k] == '1') par--;
    if (par % 2 == 0) ans++;
  }

  cout << ans << endl;
}