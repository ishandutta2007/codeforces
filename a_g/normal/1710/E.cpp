#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int& x: a) cin >> x;
  for (int& x: b) cin >> x;
  int a0 = a[0];
  int b0 = b[0];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int x = lower_bound(a.begin(), a.end(), a0) - a.begin();
  int y = lower_bound(b.begin(), b.end(), b0) - b.begin();

  vector<int> h(n+1), w(m+1);
  auto check = [&] (int k) {
    long long cur = 1LL*m*n;
    for (int i = n-1; i >= 0; i--) {
      h[i] = h[i+1];
      while (h[i] < m && a[i]+b[h[i]] <= k) h[i]++;
      cur -= h[i];
    }
    for (int i = m-1; i >= 0; i--) {
      w[i] = w[i+1];
      while (w[i] < n && b[i]+a[w[i]] <= k) w[i]++;
    }
    long long mis1 = cur, mis2 = cur-1;
    int j = 0;
    for (int i = 0; i <= n; i++) {
      while (j < m && min(i, w[j]) > min(n-i, n-w[j])) {
        cur += min(i, w[j]) - min(n-i, n-w[j]);
        j++;
      }
      mis1 = max(mis1, cur);
      mis2 = max(mis2, cur-((x>=i)&&(y>=j)));
      if (j < m) {
        mis2 = max(mis2, cur+min(i, w[j])-min(n-i, n-w[j])-((x>=i)&&(y>=j+1)));
      }
      if (i < n) {
        cur += min(j, h[i])-min(m-j, m-h[i]);
      }
    }
    return mis1 != mis2+1;
  };

  int low = 0;
  int high = a0+b0;

  while (high-low > 1) {
    int mid = (low+high)/2;
    if (check(mid)) high = mid;
    else low = mid;
  }
  cout << high << '\n';
}