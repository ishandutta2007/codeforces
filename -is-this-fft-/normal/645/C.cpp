#include <iostream>
#include <string>
#include <algorithm>

const int MAX_HOTEL = 100005;

using namespace std;

int zero_at [MAX_HOTEL];
int closest [MAX_HOTEL]; /* Closest '0' to a given pos */

int main () {
  int roomc, cowc;
  cin >> roomc >> cowc;
  
  string hotel;
  cin >> hotel;

  int zeroc = 0;
  for (int i = 0; i < hotel.size(); i++) {
    if (hotel[i] == '0') {
      zero_at[zeroc] = i;
      zeroc++;
    }
  }
  zero_at[zeroc] = 100000000;

  int cur = 0;
  for (int i = 0; i < hotel.size(); i++) {
    if (abs(i - zero_at[cur]) < abs(i - zero_at[cur + 1])) {
      closest[i] = cur;
    } else {
      closest[i] = cur + 1;
      cur++;
    }
  }

  int ans = 100000000;
  for (int i = 0; i < zeroc - cowc; i++) {
    int left = zero_at[i];
    int right = zero_at[i + cowc];
    if ((right - left) % 2 == 1) {
      int close = (left + right) / 2;
      ans = min(ans, max(zero_at[closest[close]] - left, 
			 right - zero_at[closest[close]]));
    } else {
      int closel = (left + right) / 2;
      int closer = closel + 1;
      ans = min(ans, max(zero_at[closest[closel]] - left,
			 right - zero_at[closest[closel]]));
      ans = min(ans, max(zero_at[closest[closer]] - left,
			 right - zero_at[closest[closer]]));
    }
  }

  cout << ans << endl;
}