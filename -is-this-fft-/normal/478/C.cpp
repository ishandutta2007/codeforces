#include <iostream>
#include <algorithm>

using namespace std;

typedef long long llong;

llong cnt [3];

int main () {
  for (int i = 0; i < 3; i++) {
    cin >> cnt[i];
  }

  llong sum = cnt[0] + cnt[1] + cnt[2];
  sort(cnt, cnt + 3);
  while (sum % 3 != 0) {
    cnt[2]--;
    sum--;
    sort(cnt, cnt + 3);
  }

  if (sum * 2 / 3 >= cnt[2]) {
    cout << sum / 3 << endl;
  } else {
    cout << (sum - cnt[2]) << endl;
  }
}