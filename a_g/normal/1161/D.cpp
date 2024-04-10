#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1005;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  int ans = 0;
  for (int len = 1; len < n; len++) {
    // fix the length of a
    vector<pair<bitset<N>, int>> equations;
    vector<int> a_bit(n, -1), b_bit(n, -1);
    for (int i = 0; i < len; i++) {
      a_bit[i] = (n+1)/2+min(i, len-i-1);
    }
    for (int i = 0; i < n; i++) {
      b_bit[i] = min(i, n-i-1);
    }
    int k = *max_element(a_bit.begin(), a_bit.end())+2;
    for (int& x: a_bit) {
      if (x == -1) x = k-1;
    }
    dsu D(2*k);
    D.join(a_bit.back(), k-1);
    D.join(a_bit.back()+k, k-1+k);
    D.join(b_bit.back(), k-1);
    D.join(b_bit.back()+k, k-1+k);
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        D.join(b_bit[i], a_bit[i] + k*(s[i]=='1'));
        D.join(b_bit[i]+k, a_bit[i] + k*(s[i]=='0'));
      }
    }
    int term = 1;
    int c = 0;
    for (int i = 0; i < k; i++) {
      if (D.root(i) == D.root(i+k)) term = 0;
    }
    for (int i = 0; i < 2*k-1; i++) {
      if (D.root(i) == i) c++;
    }
    c = (c-1)/2;
    if (term) {
      while (c-- && term) {
        term = (2*term)%MOD;
      }
    }
    ans = (ans+term)%MOD;
  }
  cout << ans << '\n';
}