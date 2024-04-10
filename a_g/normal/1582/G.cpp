#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6+5;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> lpf(maxn, 0);
  for (int i = 2; i < maxn; i++) {
    if (!lpf[i]) {
      for (int j = i; j < maxn; j += i) {
        lpf[j] = i;
      }
    }
  }
  map<int, vector<int>> contribs;
  ll ans = 0;
  vector<int> good;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    int j = i;
    vector<int> pfact;
    while (a[i] > 1) {
      int p = lpf[a[i]];
      pfact.push_back(p);
      a[i] /= p;
    }
    good.push_back(i);
    if (c == '*') {
      for (int p: pfact) {
        contribs[p].push_back(i);
      }
    }
    else {
      for (int p: pfact) {
        if (contribs[p].size()) {
          j = min(j, contribs[p].back());
          contribs[p].pop_back();
        }
        else {
          j = -1;
        }
      }
    }
    while (good.size() > 0 && good.back() > j) good.pop_back();
    ans += good.size();
  }
  cout << ans << endl;
}