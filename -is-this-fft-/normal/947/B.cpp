#include <iostream>

typedef long long llong;

using namespace std;

const int MAX_DAY = 100005;

llong volume [MAX_DAY], temp [MAX_DAY];
llong temp_pref [MAX_DAY];
llong res [MAX_DAY], dies [MAX_DAY];

llong temp_dist (int l, int r) {
  return temp_pref[r] - temp_pref[l - 1];
}

int main () {
  llong dayc;
  cin >> dayc;

  for (llong i = 1; i <= dayc; i++) {
    cin >> volume[i];
  }

  for (llong i = 1; i <= dayc; i++) {
    cin >> temp[i];
  }

  for (llong i = 1; i <= dayc + 2; i++) {
    temp_pref[i] = temp_pref[i - 1] + temp[i];
  }

  for (llong i = 1; i <= dayc; i++) {
    llong last = i;
    if (temp[i] < volume[i]) {
      for (llong k = 1 << 17; k != 0; k /= 2) {
        if (k + last <= dayc) {
          if (temp_dist(i, k + last) <= volume[i]) {
            last += k;
          }
        }
      }
      last++;
    }

    dies[last]++;
    res[last] += volume[i] - temp_dist(i, last - 1);
  }

  llong alive = 0;
  for (llong i = 1; i <= dayc; i++) {
    alive++;
    alive -= dies[i];
    cout << alive * temp[i] + res[i] << " ";
  }
  cout << endl;
}