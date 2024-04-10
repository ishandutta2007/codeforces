#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

const int maxn = 2e5;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  
  vector<int> m(n);
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    cin >> k[i];
  }
  pii best = {0, 1};
  set<int> bestset;
  for (int p = 1; p <= 20; p++) {
    vector<int> val(maxn);
    for (int i = 0; i < n; i++) {
      val[m[i]-1] += min(k[i], p);
    }
    vector<pii> valx(maxn);
    for (int i = 0; i < maxn; i++) {
      valx[i] = {val[i], i};
    }
    sort(valx.begin(), valx.end(), greater<pii>());
    int total = 0;
    for (int i = 0; i < p; i++) {
      total += valx[i].first;
    }
    if (best.first*p < best.second*total) {
      best = {total, p};
      bestset.clear();
      for (int i = 0; i < p; i++) bestset.insert(valx[i].second+1);
    }
  }
  cout << bestset.size() << endl;
  for (int i: bestset) cout << i << ' ';
  cout << endl;
}