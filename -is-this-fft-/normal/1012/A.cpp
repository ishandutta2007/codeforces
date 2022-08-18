#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long llong;

int main () {
  int length;
  cin >> length;

  vector<llong> nums (2 * length);
  for (int i = 0; i < 2 * length; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  llong ans = (nums[length - 1] - nums[0]) * (nums[2 * length - 1] - nums[length]);
  for (int i = 1; i + length < 2 * length; i++) {
    ans = min(ans, (nums[length + i - 1] - nums[i]) * (nums[2 * length - 1] - nums[0]));
  }

  cout << ans << endl;
}