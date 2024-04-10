#include <bits/stdc++.h>
using namespace std;

const int B = 62;

struct state {
  int parity;
  int other_parity;
  int carry_bit;
  bool less_than;
};

const bool operator < (const state& a, const state& b) {
  return 
    make_tuple(a.parity, a.other_parity, a.carry_bit, a.less_than) <
    make_tuple(b.parity, b.other_parity, b.carry_bit, b.less_than);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    map<state, long long> dp;
    dp[state{0, 0, 0, 0}] += 1;
    for (int i = 0; i < B; i++) {
      map<state, long long> newdp;
      int nb = (n>>i)&1;
      int mb = (m>>i)&1;
      for (auto& [s, cnt]: dp) {
        for (int b: {0, 1}) {
          state new_s;
          new_s.parity = s.parity^b;
          new_s.other_parity = s.other_parity^s.carry_bit^b^nb;
          new_s.carry_bit = (s.carry_bit+nb+b)>>1;
          new_s.less_than = (b < mb || b == mb && s.less_than);
          newdp[new_s] += cnt;
        }
      }
      dp = newdp;
    }
    long long ans = 0;
    for (auto& [s, cnt]: dp) {
      if (s.less_than && s.carry_bit == 0 && s.parity != s.other_parity) ans += cnt;
    }
    cout << ans << '\n';
  }
}