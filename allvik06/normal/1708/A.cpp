
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;
#define int long long
signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
      cin >> t;
        while (t--) {
            int n;
	      cin >> n;
		  int x;
		  cin >> x;
		  bool ok = true;
		  for (int i = 1; i < n; ++i) {
		  	int y;
			  cin >> y;
			  if (y % x != 0) ok = false;
		  }
		  if (ok) cout << "YES\n";
		  else cout << "NO\n";
        }
    }
}

/*
=
 */