#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

int main() {
  cin >> a >> b >> c;
  long long add = min(a, b);
  long long ans = 2LL * (c + add);
  a -= add, b -= add;
  if (a or b) ++ans;
  cout << ans << endl;
  return 0;
}