#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ll long long
using namespace std;

const ll MOD = 998244353;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int deadrows = 0;
  int deadcolumns = 0;
  int freerows = n;
  int freecolumns = m;
  //vector<set<pair<int, int>>> rowentries(n);
  //vector<set<pair<int, int>>> columnentries(m);
  set<vector<int>> entries;
  vector<vector<int>> rowvals(n, {0, 0});
  vector<vector<int>> columnvals(m, {0, 0});
  vector<int> checkers = {0, 0};
  int maxn = 1000001;
  vector<ll> powers(maxn);
  powers[0] = 1;
  for (int i = 1; i < maxn; i++) {
    powers[i] = (2*powers[i-1]) % MOD;
  }

  while (k--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    for (int k = 0; k < 2; k++) {
      if (entries.find({x, y, k}) != entries.end()) {
        checkers[(x+y+k)%2]--;
        entries.erase({x, y, k});
        rowvals[x][(y+k) % 2]--;
        if (rowvals[x][(y+k) % 2] == 0) {
          if (rowvals[x][(y+k+1) %2]) {
            deadrows--;
          }
          else {
            freerows++;
          }
        }
        columnvals[y][(x+k) % 2]--;
        if (columnvals[y][(x+k) % 2] == 0) {
          if (columnvals[y][(x+k+1) %2]) {
            deadcolumns--;
          }
          else {
            freecolumns++;
          }
        }
      }
    }
    if (z != -1) {
      checkers[(x+y+z)%2]++;
      entries.insert({x, y, z});
      if (rowvals[x][(y+z)%2] == 0) {
        if (rowvals[x][(y+z+1) %2]) {
          deadrows++;
        }
        else {
          freerows--;
        }
      }
      rowvals[x][(y+z)%2]++;
      if (columnvals[y][(x+z)%2] == 0) {
        if (columnvals[y][(x+z+1) %2]) {
          deadcolumns++;
        }
        else {
          freecolumns--;
        }
      }
      columnvals[y][(x+z)%2]++;
    }

    ll ans = 0;
    if (!deadrows) {
      ans += powers[freerows];
    }
    if (!deadcolumns) {
      ans += powers[freecolumns];
    }
    //cout << deadrows << " " << deadcolumns << endl;
    //cout << freerows << " " << freecolumns << " " << checkers[0] << " " << checkers[1] << endl;
    for (int i: checkers) {
      if (!i) ans--;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
  }
}