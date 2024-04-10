#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

vector<int> transform (vector<int>& a) {
  vector<int> counts(n);
  for (int i: a) counts[i-1]++;
  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = counts[a[i]-1];
  return result;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> b(1, a);
    vector<int> prev = a;
    while (1) {
      vector<int> next = transform(prev);
      if (prev == next) break;
      b.push_back(next);
      prev = next;
    }
    int s = b.size();
    int q;
    cin >> q;
    while (q--) {
      int x, k;
      cin >> x >> k;
      cout << b[min(s-1, k)][x-1] << endl;
    }
  }
}