#include <iostream>
#include <algorithm>
#include <time.h>
#include <set>

using namespace std;

typedef long long ll;
int mod;

struct modint {
  int val;

  modint () {
    val = 0;
  }

  modint (int _val) {
    val = (_val % mod);
  }
};

modint operator+ (modint p, modint q) {
  return modint(p.val + q.val);
}

const int maxn = 105;

modint dp [maxn * maxn][maxn];
modint ncr [maxn][maxn];
int arr [maxn], cnt [maxn];

int main () {
  srand(time(NULL));
  for (int i = 0; i < 30; i++) {
    mod *= 2;
    mod += rand() % 2;
  }

  ncr[0][0] = modint(1);
  for (int i = 1; i < maxn; i++) {
    ncr[i][0] = modint(1);
    for (int j = 1; j < maxn; j++) {
      ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    }
  }

  int length;
  cin >> length;

  int arr_sum = 0;
  set<int> vals;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
    arr_sum += arr[i];
    vals.insert(arr[i]);
  }

  bool special = false;
  if ((int) vals.size() == 2) {
    special = true;
  }
  
  sort(arr, arr + length);

  dp[0][0] = modint(1);
  for (int k = 0; k < length; k++) {
    for (int i = maxn * maxn - 1; i >= arr[k]; i--) {
      for (int j = 1; j <= length; j++) {
        dp[i][j] = dp[i][j] + dp[i - arr[k]][j - 1];
      }
    }
  }

  int cur_cnt = 1, ans = 0;
  for (int k = 0; k < length; k++) {
    if (k == 0 || arr[k] != arr[k - 1]) {
      cur_cnt = 1;
    } else {
      cur_cnt++;
    }

    if (dp[cur_cnt * arr[k]][cur_cnt].val == ncr[cnt[arr[k]]][cur_cnt].val) {
      if (cur_cnt == cnt[arr[k]] && special) {
        ans = max(ans, length);
      }
      ans = max(ans, cur_cnt);
    }

    if (dp[arr_sum - cur_cnt * arr[k]][length - cur_cnt].val
        == ncr[cnt[arr[k]]][cur_cnt].val) {
      ans = max(ans, cur_cnt);
    }
  }

  cout << ans << endl;
}