#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e7+2;
vector<int> sqf(maxn, 0);

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int i = 1; i < maxn; i++) {
    if (!sqf[i]) {
      for (int j = 1; i*j*j < maxn; j++) {
        sqf[i*j*j]=i;
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = sqf[a[i]];
    }
    int segs = 1;
    unordered_set<int> used;
    for (int i = 0; i < n; i++) {
      if (used.count(a[i])) {
        segs++;
        used.clear();
      }
      used.insert(a[i]);
    }
    cout << segs << endl;
  }
}