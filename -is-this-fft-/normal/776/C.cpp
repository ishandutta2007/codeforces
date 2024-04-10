#include <iostream>
#include <set>
#include <map>
#include <algorithm>

typedef long long llong;

const int MAX_LEN = 100005;
const llong MAX_PW = 100000000000005LL;

using namespace std;

llong arr [MAX_LEN], cum [MAX_LEN];

int main () {
  llong length, base;
  cin >> length >> base;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  cum[0] = arr[0];
  for (int i = 1; i < length; i++) {
    cum[i] = arr[i] + cum[i - 1];
  }

  map<llong, int> lefts;
  lefts[0] = 1;

  llong ans = 0;
  for (int i = 0; i < length; i++) {
    for (llong j = 1; abs(j) <= MAX_PW; j *= base) {
      if (lefts.find(cum[i] - j) != lefts.end()) {
        ans += lefts[cum[i] - j];
      }

      if (j * base == 1) {
        break;
      }
    }
   
    if (lefts.find(cum[i]) == lefts.end()) {
      lefts[cum[i]] = 1;
    } else {
      lefts[cum[i]]++;
    }
  }

  cout << ans << endl;
}