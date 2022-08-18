#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 5;
const int MAX_N = 2e5 + 5;
const int MAX_W = 20;

string arr [MAX_N];
int iarr [MAX_N];

int wt [MAX_N];
// wt[t] is w(t, t + 1)

int cumwt [MAX_N];

int dp [MAX_N];
// dp[t] is best way to construct s.t. one path ends at t, other at t + 1

int best_suff [MAX_W + 1][1 << MAX_W];
int age [MAX_W + 1][1 << MAX_W];
void refresh_best_suff (int k, int mask, int cur_age) {
  best_suff[k][mask] += cumwt[cur_age] - cumwt[age[k][mask]];
  age[k][mask] = cur_age;
}

void set_best_suff (int k, int mask, int cur_age, int val) {
  refresh_best_suff(k, mask, cur_age);
  best_suff[k][mask] = min(best_suff[k][mask], val);
}

int get_best_suff (int k, int mask, int cur_age) {
  refresh_best_suff(k, mask, cur_age);
  return best_suff[k][mask];
}

int width;

int prefix (int u, int k) { // removing the first k elements
  return u >> k;
}

int suffix (int u, int k) { // removing the last k elements
  return u % (1 << (width - k));
}

int calc_w (int u, int v) {
  // >> takes suffix
  // % width takes prefix
  for (int i = 0; i < width; i++) {
    if (suffix(u, i) == prefix(v, i)) {
      return i;
    }
  }
  return width;
}

void set_dp (int u, int val) {
  dp[u] = val;
  for (int i = 0; i <= width; i++) {
    set_best_suff(i, suffix(iarr[u], i), u, val);
  }
}

int calc_dp (int u) {
  int ans = cumwt[u - 1] + 2 * width;
  //  cout << iarr[u + 1] << endl;
  for (int i = 0; i <= width; i++) {
    //    cout << i << ": " << get_best_suff(i, prefix(iarr[u + 1], i), u - 1) << " " << prefix(iarr[u], i)
    //       << endl;
    ans = min(ans, get_best_suff(i, prefix(iarr[u + 1], i), u - 1) + i);
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_W + 1; i++) {
    for (int j = 0; j < 1 << MAX_W; j++) {
      best_suff[i][j] = INF;
    }
  }
  
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  width = arr[1].size();

  if (length == 1) {
    cout << width << endl;
    return 0;
  }
  
  for (int i = 1; i <= length; i++) {
    for (char c : arr[i]) {
      iarr[i] *= 2;
      iarr[i] += c - '0';
    }
  }

  for (int i = 1; i < length; i++) {
    wt[i] = calc_w(iarr[i], iarr[i + 1]);
  }

  for (int i = 1; i < length; i++) {
    cumwt[i] = cumwt[i - 1] + wt[i];
  }

  set_dp(1, 2 * width);
  //cout << dp[1] << endl;
  for (int i = 2; i < length; i++) {
    set_dp(i, calc_dp(i));
    // cout << dp[i] << endl;
  }

  int ans = cumwt[length - 1] + width;
  for (int i = 1; i < length; i++) {
    ans = min(ans, dp[i] + cumwt[length - 1] - cumwt[i]);
  }
  cout << ans << endl;
}