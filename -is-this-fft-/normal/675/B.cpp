#include <iostream>

typedef long long llong;

const int INF = 1023456789;

using namespace std;

int main () {
  int maxv, a, b, c, d;
  cin >> maxv >> a >> b >> c >> d;

  llong ans = 0;
  for (int i = 1; i <= maxv; i++) {
    int cmin = 0;
    int cmax = INF;

    cmin = max(cmin, a + b + i + 1);
    cmax = min(cmax, a + b + i + maxv);

    cmin = max(cmin, a + c + i + 1);
    cmax = min(cmax, a + c + i + maxv);
    
    cmin = max(cmin, b + d + i + 1);
    cmax = min(cmax, b + d + i + maxv);

    cmin = max(cmin, c + d + i + 1);
    cmax = min(cmax, c + d + i + maxv);
    
    ans += max(-1, cmax - cmin) + 1;
  }

  cout << ans << endl;
}