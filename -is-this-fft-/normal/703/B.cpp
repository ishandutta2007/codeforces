#include <iostream>

typedef long long llong;

const int MAX_CITY = 100005;

using namespace std;

bool capital [MAX_CITY];
llong beauty [MAX_CITY];

int main () {
  ios::sync_with_stdio(false);

  int cityc, capc;
  cin >> cityc >> capc;
  
  llong bsum = 0;
  for (int i = 0; i < cityc; i++) {
    cin >> beauty[i];
    bsum += beauty[i];
  }

  llong capsum = 0, ans = 0;
  for (int i = 0; i < capc; i++) {
    int cur;
    cin >> cur;
    cur--;
    capital[cur] = true;

    ans += beauty[cur] * (bsum - beauty[cur]);
    ans -= beauty[cur] * capsum;
    capsum += beauty[cur];
  }

  for (int i = 0; i < cityc; i++) {
    if (!capital[i] && !capital[(i + 1) % cityc]) {
      ans += beauty[i] * beauty[(i + 1) % cityc];
    }
  }

  cout << ans << endl;
}