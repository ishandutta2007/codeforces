#include <iostream>

using namespace std;

typedef long long ll;

ll N, M;

ll find (ll length, ll idx) { // finds B[idx]
  if (length == 1) return 0;
  if (idx < (length + 1) / 2) {
    return 2 * find((length + 1) / 2, idx);
  } else {
    return 2 * find(length / 2, idx - (length + 1) / 2) + 1;
  }
}

const int MAX_LG = 60;

ll n_suff (ll suff, int len, ll v) { // # of ll-s with given suffix and <= u
  int add = suff <= (v % (1LL << len));
  return (v >> len) + add;
}

ll sum_n (ll n) { // 0 + 1 + 2 + ... + n - 1
  if (n % 2 == 0) {
    return (((n / 2) % M) * ((n - 1) % M)) % M;
  } else {
    return ((((n - 1) / 2) % M) * (n % M)) % M;
  }
}

ll pow2 [MAX_LG + 1];

ll sum_le (ll x, ll v) { // sum of ll-s <= x (by reversed binary value) and <= u (by value)
  ll cnt = 0;
  ll sum = 0;

  if (x <= v) {
    sum += x;
    sum %= M;
    
    cnt++;
    cnt %= M;
  }
  
  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (x & 1LL << i) {
      ll suff = x % (1LL << i);
      ll ns = n_suff(suff, i + 1, v);
      cnt += ns;
      cnt %= M;
      
      sum += ((ns % M) * (suff % M)) % M;
      sum %= M;
      
      sum += (sum_n(ns) * pow2[i + 1]) % M;
      sum %= M;
    }
  }

  return (sum + cnt) % M;
}

ll query_up (ll r, ll v) {
  if (r < 0) return 0;
  if (v < 0) return 0;
  return sum_le(find(N, r), min(v, N - 1));
}

ll query (ll l, ll r, ll u, ll v) {
  return (query_up(r, v) + M - query_up(l - 1, v) + M - query_up(r, u - 1) + query_up(l - 1, u - 1)) % M;
}

int main () {
  ios::sync_with_stdio(false);
  
  int queryc;
  cin >> N >> queryc >> M;

  pow2[0] = 1;
  for (int i = 1; i <= MAX_LG; i++) {
    pow2[i] = (pow2[i - 1] * 2) % M;
  }
  
  for (int i = 0; i < queryc; i++) {
    ll l, r, u, v;
    cin >> l >> r >> u >> v;
    l--;
    r--;
    u--;
    v--;
    
    cout << query(l, r, u, v) << '\n';
  }
}