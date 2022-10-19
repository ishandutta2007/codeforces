#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
vector<int> indices[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      indices[a[i]].push_back(i);
    }
    vector<int> Lmax(n, -1), Rmax(n, n), Lmin(n, -1), Rmin(n, n);
    stack<int> stk;

    for (int i = 0; i < n; i++) {
      while (!stk.empty() && a[stk.top()] < a[i]) {
        Rmax[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) stk.pop();

    for (int i = 0; i < n; i++) {
      while (!stk.empty() && a[stk.top()] > a[i]) {
        Rmin[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    
    for (int i = n-1; i >= 0; i--) {
      while (!stk.empty() && a[stk.top()] <= a[i]) {
        Lmax[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) stk.pop();

    for (int i = n-1; i >= 0; i--) {
      while (!stk.empty() && a[stk.top()] > a[i]) {
        Lmin[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) stk.pop();

    long long ans = 0;
    for (int x = 1; x < N; x++) {
      if (!indices[x].size()) continue;
      for (int y = x; y < N; y += x) {
        for (int i: indices[y]) {
          auto it = lower_bound(indices[x].begin(), indices[x].end(), i);
          if (it != indices[x].begin()) {
            int j = *prev(it);
            ans += 1LL*max(0, min(i, j)-max(Lmax[i], Lmin[j]))
              *max(0, min(Rmax[i], Rmin[j])-max(i, j));
          }
          if (it != indices[x].end()) {
            int j = *it;
            ans += 1LL*max(0, min(i, j)-max(Lmax[i], Lmin[j]))
              *max(0, min(Rmax[i], Rmin[j])-max(i, j));
          }
          if (it != indices[x].begin() && it != indices[x].end()) {
            int jl = *prev(it);
            int jr = *it;
            ans -= 1LL*max(0, jl-max(Lmax[i], Lmin[jr]))
              *max(0, min(Rmax[i], Rmin[jl])-jr);
          }
        }
      }
    }

    cout << ans << '\n';
    for (int i = 0; i < N; i++) {
      indices[i].clear();
    }
  }
}