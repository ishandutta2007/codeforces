#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
int lpf[N];

vector<int> prime_factors(int n) {
  vector<int> ans;
  while (n > 1) {
    int p = lpf[n];
    ans.push_back(p);
    while (n%p == 0) n /= p;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(lpf, lpf+N, 0);
  int id = 0;
  for (int i = 2; i < N; i++) {
    if (lpf[i] == i) {
      for (int j = 2*i; j < N; j+= i) {
        lpf[j] = i;
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> fact = prime_factors(n);
    int w = fact.size();
    vector<vector<long long>> sums(fact.size());
    vector<multiset<long long>> vals(fact.size());
    for (int i = 0; i < w; i++) {
      int p = fact[i];
      sums[i].resize(n/p, 0);
      for (long long x: sums[i]) vals[i].insert(x);
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < w; j++) {
        int p = fact[j];
        int res = i%(n/p);
        vals[j].erase(vals[j].find(sums[j][res]));
        sums[j][res] += a[i];
        vals[j].insert(sums[j][res]);
      }
    }

    auto print_ans = [&] () {
      long long ans = 0;
      for (int i = 0; i < w; i++) {
        ans = max(ans, (n/fact[i])*(*vals[i].rbegin()));
      }
      cout << ans << '\n';
    };

    print_ans();
    while (q--) {
      int pos, x;
      cin >> pos >> x;
      pos--;
      int diff = x-a[pos];
      for (int j = 0; j < w; j++) {
        int p = fact[j];
        int res = pos%(n/p);
        vals[j].erase(vals[j].find(sums[j][res]));
        sums[j][res] += diff;
        vals[j].insert(sums[j][res]);
      }
      a[pos] = x;
      print_ans();
    }
  }
}