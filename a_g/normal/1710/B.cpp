#include <bits/stdc++.h>
using namespace std;

// max(0, p-|x-j|) = (|x-(j-p)|+|x-(j+p)|)/2-abs(x-j)
// idea: check the condition only for the peaks
// e.g. in example 1, f(3) = 10 so the condition to be good is p >= |x-3|+4

long long query(vector<int>& a, vector<long long>& as, int x) {
  // return sum(abs(x-a)) for a in x
  int n = a.size();
  int z = lower_bound(a.begin(), a.end(), x)-a.begin();
  return 1LL*z*x-as[z]+(as[n]-as[z]-1LL*(n-z)*x);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> add, sub;
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      add.push_back(a[i].first-a[i].second);
      add.push_back(a[i].first+a[i].second);
      sub.push_back(a[i].first);
    }
    sort(add.begin(), add.end());
    sort(sub.begin(), sub.end());
    vector<long long> adds(2*n+1), subs(n+1);
    for (int i = 0; i < 2*n; i++) {
      adds[i+1] = adds[i]+add[i];
    }
    for (int i = 0; i < n; i++) {
      subs[i+1] = subs[i]+sub[i];
    }
    long long l = -1e18; // p >= l-x
    long long r = -1e18; // p >= x+r
    for (int i = 0; i < n; i++) {
      long long rain = query(add, adds, a[i].first)/2-query(sub, subs, a[i].first);
      if (rain > m) {
        l = max(l, rain-m+a[i].first);
        r = max(r, rain-m-a[i].first);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << (a[i].second >= l-a[i].first && a[i].second >= a[i].first+r);
    }
    cout << '\n';
  }
}