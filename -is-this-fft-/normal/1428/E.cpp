#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll sq (ll x) {
  return x * x;
}

ll time_when_cut (ll len, int pcs) {
  ll small_len = len / pcs;
  ll big_len = 1 + len / pcs;
  ll big_c = len % pcs;
  ll small_c = pcs - big_c;

  return small_c * sq(small_len) + big_c * sq(big_len);
}

ll get_improv (ll len, ll pcs) {
  return time_when_cut(len, pcs) - time_when_cut(len, pcs + 1);
}

ll len [MAX_N];
int cur_pcs [MAX_N];
priority_queue<pair<ll, int>> PQ; // <improve, idx>

ll improve () {
  auto pr = PQ.top();
  PQ.pop();

  ll ans = pr.first;
  int idx = pr.second;
  cur_pcs[idx]++;
  PQ.push(make_pair(get_improv(len[idx], cur_pcs[idx]), idx));
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, K;
  cin >> n >> K;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> len[i];
    ans += sq(len[i]);
    cur_pcs[i] = 1;
    PQ.push(make_pair(get_improv(len[i], cur_pcs[i]), i));
  }

  for (int i = 0; i < K - n; i++) {
    ans -= improve();
  }
  cout << ans << endl;
}