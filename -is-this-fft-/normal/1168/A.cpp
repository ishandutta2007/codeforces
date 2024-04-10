#include <iostream>
#include <vector>

using namespace std;

const int maxn = 300005;

int next_after (int after, int cur, int steps, int m) {
  if (steps >= m - 1) {
    return after;
  }
  if (after >= m) {
    return maxn;
  }
  
  if (cur + steps >= m) {
    if (after <= (cur + steps) % m) {
      return after;
    } else if (after < cur) {
      return cur;
    } else {
      return after;
    }
  } else {
    if (after < cur) {
      return cur;
    } else if (cur <= after && after <= cur + steps) {
      return after;
    } else {
      return maxn;
    }
  }
}

bool try_steps (int steps, int m, const vector<int> &arr) {
  int cur = 0;
  for (int i = 0; i < (int) arr.size(); i++) {
    cur = next_after(cur, arr[i], steps, m);
  }
  return cur < m;
}

int main () {
  int length, m;
  cin >> length >> m;
  
  vector<int> arr (length);
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  if (try_steps(0, m, arr)) {
    cout << 0 << endl;
    return 0;
  }
  
  int ans = 0;
  for (int k = 1 << 18; k != 0; k /= 2) {
    if (!try_steps(ans + k, m, arr)) {
      ans += k;
    }
  }

  cout << ans + 1 << endl;
}