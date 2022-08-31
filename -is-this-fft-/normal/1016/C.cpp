#include <iostream>

using namespace std;

typedef long long llong;

const int MAX_W = 300005;

llong rate [MAX_W][2];
llong cumrate [MAX_W][2];

llong cumrange (int l, int r, int k) {
  if (l == 0) {
    return cumrate[r][k];
  } else {
    return cumrate[r][k] - cumrate[l - 1][k];
  }
}

int main () {
  int length;
  cin >> length;

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < length; i++) {
      cin >> rate[i][k];
    }
  }

  for (int k = 0; k < 2; k++) {
    cumrate[0][k] = rate[0][k];
    for (int i = 1; i < length; i++) {
      cumrate[i][k] = cumrate[i - 1][k] + rate[i][k];
    }
  }

  llong ans = 0, evensum = 0, oddsum = 0, prefsum = 0;
  for (int i = 0; i < length; i++) {
    if (i % 2 == 0) {
      if (i == 0) {
        for (int j = 0; j < length; j++) {
          evensum += j * rate[j][0];
        }

        for (int j = length; j < 2 * length; j++) {
          evensum += j * rate[2 * length - j - 1][1];
        }
      } else {
        evensum -= 2 * (i - 2) * rate[i - 2][0];
        evensum -= (2 * (i - 2) + 1) * rate[i - 1][0];
        evensum -= (2 * length - 1) * rate[i - 2][1];
        evensum -= (2 * length - 2) * rate[i - 1][1];

        evensum += 2 * cumrange(i, length - 1, 0);
        evensum += 2 * cumrange(i, length - 1, 1);
      }
    } else {
      if (i == 1) {
        for (int j = 1; j < length; j++) {
          oddsum += (j + 1) * rate[j][1];
        }

        for (int j = length - 1; j >= 1; j--) {
          oddsum += (2 * length - j) * rate[j][0];
        }
      } else {
        oddsum -= 2 * (i - 2) * rate[i - 2][1];
        oddsum -= (2 * (i - 2) + 1) * rate[i - 1][1];
        oddsum -= (2 * length - 1) * rate[i - 2][0];
        oddsum -= (2 * length - 2) * rate[i - 1][0];

        oddsum += 2 * cumrange(i, length - 1, 0);
        oddsum += 2 * cumrange(i, length - 1, 1);
      }
    }

    if (i != 0) {
      if (i % 2 == 0) {
        prefsum += (2 * i - 2) * rate[i - 1][1];
        prefsum += (2 * i - 1) * rate[i - 1][0];
      } else {
        prefsum += (2 * i - 2) * rate[i - 1][0];
        prefsum += (2 * i - 1) * rate[i - 1][1];
      }
    }

    if (i % 2 == 0) {
      ans = max(ans, prefsum + evensum);
    } else {
      ans = max(ans, prefsum + oddsum);
    }
  }

  cout << ans << endl;
}