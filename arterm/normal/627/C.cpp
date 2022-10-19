#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;

ll n, d, m;
map<ll, ll> cost;
set<int> events;
ll q[M];
ll qs = 0, qf = 0;

void read() {
  cin >> d >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, p;
    cin >> x >> p;

    events.insert(x);
    if (x + n < d) {
      events.insert(x + n);
    }

    cost[x] = p;
  }

  cost[0] = 0;
  events.insert(n);
  events.insert(d);
}


void kill() {
  ll ans = 0, last = 0;
  bool noans = false;
  q[qf++] = 0;
  
  for (ll cur : events) {
    while (qs < qf && q[qs] < cur - n)
      ++qs;

    ll len = cur - last;

    if (qs == qf) {
      noans = true;
      break;
    }

    ans += len * cost[q[qs]];
    last = cur;

    if (cost.count(cur)) {
      while (qs < qf && cost[q[qf - 1]] >= cost[cur])
        --qf;
      q[qf++] = cur;
    }
 }

  if (!noans) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}