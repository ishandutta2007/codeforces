#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map<int, int> cntx, cnty;
map<pair<int, int>, int> cntp;

void read() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    cntx[x]++;
    cnty[y]++;
    cntp[make_pair(x, y)]++;
  }
}

ll c2(ll x) {
  return x * (x - 1) / 2;
}

void kill() {
  ll ans = 0;
  for (auto t : cntx)
    ans += c2(t.second);
  for (auto t : cnty)
    ans += c2(t.second);
  for (auto t : cntp)
    ans -= c2(t.second);
  cout << ans << endl;
}


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}