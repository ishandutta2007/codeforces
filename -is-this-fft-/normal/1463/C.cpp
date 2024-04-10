#include <iostream>

using namespace std;

#define time ___time

const int MAX_N = 1e5 + 5;

typedef long long ll;

ll time [MAX_N], pos [MAX_N];

const ll INF = 1e18 + 5;

ll sgn (ll x) {
  if (x < 0) return -1;
  if (x == 0) return 0;
  return 1;
}

bool passes_through (ll x, ll tl, ll tr, ll st, ll sx, ll dir) {
  ll l = sx + dir * (tl - st);
  ll r = sx + dir * (tr - st);
  if (l > r) swap(l, r);
  return l <= x && x <= r;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> time[i] >> pos[i];
  }
  time[n] = INF;

  int ans = 0;
  ll start_time = -1, finish_time = -1, dir = 0, cur_pos = 0, nxt_pos = 0;
  for (int i = 0; i < n; i++) {
    if (finish_time <= time[i]) {
      cur_pos = nxt_pos;
      nxt_pos = pos[i];
      start_time = time[i];
      ll dist = abs(pos[i] - cur_pos);
      finish_time = start_time + dist;
      dir = sgn(pos[i] - cur_pos);
    }

    if (passes_through(pos[i], time[i], min(time[i + 1], finish_time), start_time, cur_pos, dir)) {
      ans++;
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}