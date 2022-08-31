#include <iostream>
#include <algorithm>

typedef long long llong;

const int MAX_LEN = 100005;

using namespace std;

llong diff [MAX_LEN];

int main () {
  int length;
  cin >> length;

  llong lastval;
  cin >> lastval;
  
  for (int i = 0; i < length - 1; i++) {
    llong cur;
    cin >> cur;

    diff[i] = abs(cur - lastval);
    lastval = cur;
  }

  llong ans = 0;
  for (int k = 0; k < 2; k++) {
    llong curmin = 0, curval = 0;
    for (int i = 0; i < length - 1; i++) {
      if (i % 2 == k) {
        curval += diff[i];
      } else {
        curval -= diff[i];
      }

      ans = max(ans, curval - curmin);
      curmin = min(curmin, curval);
    }
  }

  cout << ans << endl;
}