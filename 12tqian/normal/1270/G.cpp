#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ll long long
using namespace std;
set<int> visited;
vector<int> path;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  ll T, n, k;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1) {
      cin >> k;
      cout << 1 << '\n' << 1 << '\n';
    }
    else {
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        cin >> k;
        a[i] = i - k;
      }
      visited.clear();
      path.clear();
      int state = 0;
	  int times = 0;
      while (visited.find(state) == visited.end()) {
        path.push_back(state);
        visited.insert(state);
        state = a[state];
		++times;
		assert(times <= 2e6);
      }
      int index = find(path.begin(), path.end(), state) - path.begin();
      cout << path.size() - index << '\n';
      for (int i = index; i < path.size(); i++) {
        cout << path[i] + 1 << " ";
      }
      cout << '\n';
    }
  }
}