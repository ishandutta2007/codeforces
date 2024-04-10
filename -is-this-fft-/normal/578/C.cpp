#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 2e5 + 5;

int n;
int arr [MAX_N];
ld cur [MAX_N];
ld pref [MAX_N];

ld weakness (ld x) {
  for (int i = 1; i <= n; i++) {
    cur[i] = (ld) arr[i] - x;
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + cur[i];
  }

  ld mn = 0;
  ld mx = 0;
  ld ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, pref[i] - mn);
    ans = max(ans, mx - pref[i]);
    mx = max(mx, pref[i]);
    mn = min(mn, pref[i]);
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  
  ld l = -1e4;
  ld r = 1e4;
  ld ans;
  for (int i = 0; i < 100; i++) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    
    ld w1 = weakness(m1);
    ld w2 = weakness(m2);
    
    if (w1 > w2) {
      l = m1;
    } else {
      r = m2;
    }

    ans = w1;
  }
  cout << fixed << setprecision(12) << ans << endl;
}