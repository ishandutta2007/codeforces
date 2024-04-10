#include <iostream>
#include <vector>
#include <deque>

typedef long long llong;

using namespace std;

int main () {
  deque<llong> bits;
  
  llong initial;
  cin >> initial;

  if (initial == 0) {
    cout << 0 << endl;
  } else if (initial == 1) {
    cout << 1 << endl;
  } else {
    while (initial > 1) {
      bits.push_front(initial % 2);
      initial /= 2;
    }

    llong l, r;
    cin >> l >> r;


    llong ans = 0;
    for (llong i = l; i <= r; i++) {
      if (i % 2 == 1) {
        ans++;
      } else {
        llong index = 0;
        for (llong j = i / 2; j % 2 != 1; j /= 2) {
          index++;
        }
        ans += bits[index];
      }
    }

    cout << ans << endl;
  }
}