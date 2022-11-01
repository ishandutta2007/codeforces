#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int a[N], pref[N], suf[N];
int pos1[N], pos2[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pref[i] = suf[i] = a[i];
    pos1[i] = pos2[i] = i;
  }
  for (int i = 1; i < n; ++i) {
    if (pref[i] > pref[i - 1]) {
      pref[i] = pref[i - 1];
      pos1[i] = pos1[i - 1];
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (suf[i] > suf[i + 1]) {
      suf[i] = suf[i + 1];
      pos2[i] = pos2[i + 1];
    }
  }

  for (int i = 1; i + 1 < n; ++i) {
    if (pref[i - 1] < a[i] && a[i] > suf[i + 1]) {
      cout << "YES\n" << pos1[i - 1] + 1 << " " << i + 1 << " " << pos2[i + 1] + 1 << "\n"; 
      return;
    }
  }
  cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}