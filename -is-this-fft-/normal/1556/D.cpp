#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include <algorithm>

using namespace std;

int get_or (int u, int v) {
  u++; v++;
  cout << "or " << u << " " << v << endl;
  int ans;
  cin >> ans;
  return ans;
}

int get_and (int u, int v) {
  u++; v++;
  cout << "and " << u << " " << v << endl;
  int ans;
  cin >> ans;
  return ans;  
}

void report (int ans) {
  cout << "finish " << ans << endl;
  exit(0);
}

const int MAX_N = 1e4 + 5;
const int MAX_B = 30;

int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, K;
  cin >> n >> K;

  int aab = get_and(0, 1);
  int aob = get_or(0, 1);
  int aac = get_and(0, 2);
  int aoc = get_or(0, 2);
  int bac = get_and(1, 2);
  int boc = get_or(1, 2);

  for (int k = 0; k < MAX_B; k++) {
    vector<int> cur =
      {!!(aab & 1 << k),
       !!(aob & 1 << k),
       !!(aac & 1 << k),
       !!(aoc & 1 << k),
       !!(bac & 1 << k),
       !!(boc & 1 << k)};
    if (cur == vector<int>{1, 1, 1, 1, 1, 1}) {
      ans[0] |= 1 << k;
      ans[1] |= 1 << k;
      ans[2] |= 1 << k;
    } else if (cur == vector<int>{1, 1, 0, 1, 0, 1}) {
      ans[0] |= 1 << k;
      ans[1] |= 1 << k;
    } else if (cur == vector<int>{0, 1, 1, 1, 0, 1}) {
      ans[0] |= 1 << k;
      ans[2] |= 1 << k;
    } else if (cur == vector<int>{0, 1, 0, 1, 0, 0}) {
      ans[0] |= 1 << k;
    } else if (cur == vector<int>{0, 1, 0, 1, 1, 1}) {
      ans[1] |= 1 << k;
      ans[2] |= 1 << k;
    } else if (cur == vector<int>{0, 1, 0, 0, 0, 1}) {
      ans[1] |= 1 << k;
    } else if (cur == vector<int>{0, 0, 0, 1, 0, 1}) {
      ans[2] |= 1 << k;
    } else if (cur == vector<int>{0, 0, 0, 0, 0, 0}) {
    } else {
      assert(false);
    }
  }

  for (int i = 3; i < n; i++) {
    int com = get_and(0, i);
    int uniq = get_or(0, i) & ~ans[0];
    ans[i] = com | uniq;
  }

  sort(ans, ans + n);

  report(ans[K - 1]);
}