#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
  int n, r;
  cin >> n >> r;
  int v = 1<<n;
  vector<int> a(v);
  for (int i = 0; i < v; i++) cin >> a[i];
  ll s = accumulate(a.begin(), a.end(), 0LL);
  cout << (double)s/v << '\n';
  for (int i = 0; i < r; i++) {
    int z, g;
    cin >> z >> g;
    s += g - a[z];
    a[z] = g;
    cout << (double)s/v << '\n';
  }
}