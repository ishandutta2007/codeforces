#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index (vector<int>& a, int val) {
  // Assuming a is sorted and val >= a[0], returns largest i with val >= a[i]
  int n = a.size();
  int low = 0;
  int high = n-1;
  while (high - low > 1) {
    int mid = (low+high)/2;
    if (a[mid] <= val) {
      low = mid;
    }
    else {
      high = mid;
    }
  }
  if (a[low+1] <= val) return low+1;
  return low;
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    //set<int> aset;
    vector<int> b(m);
    //set<int> bset;
    vector<vector<int>> anums(n-1);
    vector<vector<int>> bnums(m-1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      //aset.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      //bset.insert(b[i]);
    }
    while (k--) {
      int x, y;
      cin >> x >> y;
      int i = index(a, x);
      int j = index(b, y);
      if (a[i] != x) {
        anums[i].push_back(j);
      }
      if (b[j] != y) {
        //cout << x << " " << y << endl;
        bnums[j].push_back(i);
      }
    }
    ll ans = 0;
    for (vector<int> seq: anums) {
      ll total = 0;
      map<int, int> freqs;
      for (int j: seq) {
        freqs[j]++;
        total++;
      }
      ans += total*total;
      for (auto item: freqs) {
        ll freq = item.second;
        ans -= freq*freq;
      }
    }
    for (vector<int> seq: bnums) {
      ll total = 0;
      map<int, int> freqs;
      for (int j: seq) {
        freqs[j]++;
        total++;
      }
      ans += total*total;
      for (auto item: freqs) {
        ll freq = item.second;
        ans -= freq*freq;
      }
    }
    cout << ans/2 << endl;
  }
}