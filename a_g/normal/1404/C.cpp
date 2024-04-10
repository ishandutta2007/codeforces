#include <bits/stdc++.h>
using namespace std;

class fenwick {
  public:
    vector<int> arr;
    int n;
    fenwick (int n): n(n) {
      arr.resize(n+2);
    }
    void add (int index, int val) {
      index++;
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    int prefsum(int index) {
      int sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
    
    int bsearch(int val) {
      int sum = 0;
      int index = 0;
      for (int p = 20; p >= 0; p--) {
        int exp = 1 << p;
        if (index + exp <= n && sum + arr[index + exp] >= val) {
          index += exp;
          sum += arr[index];
        }
      }
      return index;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  fenwick b(n);
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    a[i] = i+1-val;
  }

  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    queries[n-1-y].push_back({x, i});
  }

  vector<int> answers(q);

  for (int r = 0; r < n; r++) {
    int lmax = 0;
    if (a[r] >= 0) {
      int lmax;
      if (b.prefsum(r+1) >= a[r]) {
        lmax = r+1;
      }
      else if (b.prefsum(1) < a[r]) {
        lmax = 0;
      }
      else {
        lmax = b.bsearch(a[r]);
      }
      b.add(0, 1);
      b.add(lmax, -1);
    }
    for (pair<int, int> query: queries[r]) {
      answers[query.second] = b.prefsum(query.first+1);
    }
  }

  for (int ans: answers) cout << ans << '\n';
}