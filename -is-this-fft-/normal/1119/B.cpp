#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1003;

int arr [MAX_N];

bool canPut (int k, int height) {
  vector<int> bottles;
  for (int i = 0; i < k; i++) {
    bottles.push_back(arr[i]);
  }
  sort(bottles.begin(), bottles.end());

  ll ans = 0;
  for (int i = k - 1; i >= 0; i -= 2) {
    ans += bottles[i];
  }

  return (ans <= height);
}

int main () {
  int length, height;
  cin >> length >> height;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int k = 1 << 9; k != 0; k /= 2) {
    if (ans + k <= length && canPut(ans + k, height)) {
      ans += k;
    }
  }

  cout << ans << '\n';
}