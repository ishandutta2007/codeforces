#include <iostream>

using namespace std;

typedef long long ll;

const int BLOCK = 500;
const int MAX_N = BLOCK * BLOCK;

ll dist [MAX_N];
ll height [MAX_N];
ll pref [MAX_N];

const ll INF = 1LL << 60;

ll opt [BLOCK];
ll bestl [BLOCK];
ll bestr [BLOCK];
void calc_opt (int idx) {
  ll pmax = -INF;
  bestr[idx] = -INF;
  for (int i = idx * BLOCK; i < (idx + 1) * BLOCK; i++) {
    bestr[idx] = max(bestr[idx], pref[i] + height[i]);
    if (i != idx * BLOCK) {
      opt[idx] = max(opt[idx], pref[i] + height[i] + pmax);
    }
    pmax = max(pmax, height[i] - pref[i]);
  }
  bestl[idx] = pmax;
}

ll solve (int l, int r) {
  ll pmax = -INF;
  ll ans = 0;

  while (l <= r) {
    if (l % BLOCK == 0 && l + BLOCK < r) {
      ans = max(ans, opt[l / BLOCK]);
      ans = max(ans, bestr[l / BLOCK] + pmax);
      pmax = max(pmax, bestl[l /  BLOCK]);
      l += BLOCK;
    } else {
      ans = max(ans, pmax + pref[l] + height[l]);
      pmax = max(pmax, height[l] - pref[l]);
      l++;
    }
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < n; i++) {
    cin >> dist[i];
    dist[n + i] = dist[i];
  }
  
  for (int i = 0; i < n; i++) {
    cin >> height[i];
    height[i] *= 2;
    height[n + i] = height[i];
  }

  pref[0] = 0;
  for (int i = 1; i < 2 * n; i++) {
    pref[i] = pref[i - 1] + dist[i - 1];
  }

  for (int i = 0; i < 2 * n; i += BLOCK) {
    calc_opt(i / BLOCK);
  }
  
  for (int i = 0; i < qc; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    
    if (b < a) {
      int l = b + 1;
      int r = a - 1;
      cout << solve(l, r) << '\n';
    } else {
      a += n;
      int l = b + 1;
      int r = a - 1;
      cout << solve(l, r) << '\n';
    }
  }
}