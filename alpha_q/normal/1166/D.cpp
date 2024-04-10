#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q; ll a, b, m;

int main() {
  cin >> q;
  while (q--) {
    cin >> a >> b >> m;
    if (a == b) {
      printf("1 %lld\n", a);
      continue;
    }
    if (m == 1) {
      ll sum = a;
      vector <ll> seq = {a};
      while (seq.back() < b) {
        seq.emplace_back(sum + 1);
        sum += seq.back();
      }
      if (seq.back() != b) {
        puts("-1");
        continue;
      }
      int sz = seq.size();
      printf("%d", sz);
      for (ll x : seq) printf(" %lld", x);
      puts(""); continue;
    }
    if (b - a <= m) {
      printf("2 %lld %lld\n", a, b);
      continue;
    }
    vector <ll> r;
    for (ll i = 49; i >= 2; --i) {
      if (b < 1LL << i) continue;
      ll yo = b - (1LL << i);
      if ((yo + (1LL << (i - 1))) / (1LL << (i - 1)) <= a - 1) continue;
      yo -= (1LL << (i - 1)) * (a - 1);
      for (ll j = i - 2; j >= 0; --j) {
        ll cur = min(m - 1, yo / (1LL << j));
        yo -= cur * (1LL << j);
        r.emplace_back(cur);
      }
      if (yo >= m) r.clear();
      else r.emplace_back(yo);
      break;
    }
    if (r.empty()) {
      puts("-1"); continue;
    }
    ll sum = a;
    vector <ll> seq = {a};
    for (int i = 0; i < r.size(); ++i) {
      seq.emplace_back(sum + r[i] + 1);
      sum += seq.back();
    }
    int sz = seq.size();
    printf("%d", sz);
    for (ll x : seq) printf(" %lld", x);
    puts("");
  }
  return 0;
}