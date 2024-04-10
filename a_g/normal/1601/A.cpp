#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5+5;
vector<vector<int>> divisors(maxn);

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      divisors[j].push_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> counts(32, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 32; i++) {
      for (int val: a) {
        counts[i] += (val>>i)&1;
      }
    }
    int g = 0;
    for (int c: counts) g = __gcd(g, c);
    if (g == 0) {
      for (int k = 1; k <= n; k++) cout << k << " ";
      cout << endl;
    }
    else {
      for (int k: divisors[g]) cout << k << " ";
      cout << endl;
    }
  }
}