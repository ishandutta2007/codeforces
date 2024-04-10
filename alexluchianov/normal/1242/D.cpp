#include <iostream>
#include <vector>
#include <set>

using ll = long long ;

ll gauss(ll from, ll to) {
  return (to - from + 1) * (to + from) / 2;
}

ll extract(ll group, ll k) {
  if(group == 0) {
    return k * (k + 1) / 2;
  } else {
    ll prev = (group) / k;
    ll step = group - prev * k;
    ll pos = extract(prev, k);
    step++;
    ll start = (step - 1) * k + 1, stop = step * k;
    if(pos <= start)
      start++;
    if(pos <= stop)
      stop++;
    start = start + prev * (k * k + 1);
    stop = stop + prev * (k * k + 1);
    pos = pos + prev * (k * k + 1);
    ll result = gauss(start, stop);

    if(start <= pos && pos <= stop) {
      result -= pos;
    }
    return (result - 1) % (k * k + 1) + 1;
  }
}

ll solve(ll n, ll k) {
  ll group = (n - 1) / (1LL * k * k + 1);
  ll pos = extract(group, k);
  ll diff = group * (k * k + 1);

  if(diff + pos == n) {
    return (1 + group) * (k + 1);
  } else if(diff + pos < n) {
    return n + group * (k - 1) + (n - 2 - diff) / k - 1;
  } else {
     if(group == 0) {
       return n + ((n - 1) / k);
    } else
      return n + group * (k - 1) + (n - diff - 1) / k;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    ll n, k;
    std::cin >> n >> k;
    std::cout << solve(n, k) << '\n';
  }
  return 0;
}