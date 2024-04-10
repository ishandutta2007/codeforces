#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;
const int INF = 1 << 20;

int dp [MAX_N][MAX_N]; // segs filled, evens left

int cost (int le, int re, bool es, bool os) {
  if (le == 2 && re == 2) {
    if (es && os) {
      return 1;
    } else {
      return 0;
    }
  } else if (le == 2 || re == 2) {
    if (re == 2) swap(le, re);
    if (re == 0 && !os) return 0;
    if (re == 1 && !es) return 0;
    return 1;
  } else if (le != re) {
    return 1;
  } else if (le == 0) {
    if (os) return 2;
    else return 0;
  } else if (le == 1) {
    if (es) return 2;
    else return 0;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int el = n / 2;
  int totl = n;

  int last = 2, curl = 0;
  vector<vector<int>> segs;
  int cplx = 0;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;

    if (u == 0) {
      curl++;
    } else {
      if (curl != 0) {
        segs.push_back({curl, last, u % 2});
      } else {
        if (last != 2 && last != u % 2) {
          cplx++;
        }
      }
      curl = 0;
      last = u % 2;

      if (u % 2 == 0) el--;
      totl--;
    }
  }

  if (curl != 0) {
    segs.push_back({curl, last, 2});
  }

  /*
  for (auto v : segs) {
    for (int u : v) {
      cout << u << " ";
    }
    cout << endl;
  }
  */

  int segc = (int) segs.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = INF;
    }
  }

  dp[0][el] = cplx;
  for (int i = 1; i <= segc; i++) {
    for (int j = 0; j <= totl; j++) {
      int ec = j;
      int oc = totl - j;
      for (int k = 0; k <= segs[i - 1][0]; k++) {
        int eg = k;
        int og = segs[i - 1][0] - k;
        if (eg <= ec && og <= oc) {
          int c = cost(segs[i - 1][1], segs[i - 1][2], eg >= 1, og >= 1);
          dp[i][ec - eg] = min(dp[i][ec - eg], dp[i - 1][ec] + c);
        }
      }
    }

    totl -= segs[i - 1][0];
  }
  cout << dp[segc][0] << endl;
}