#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

bool chk(vector <int> a) {
  if (*min_element(all(a)) == -1) return false;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i - 1] > a[i]) return false;
    a[i] -= a[i - 1];
  }
  return a.back() == 0;
}

void solve() {
  int n;
  cin >> n;
  vector <int> a(n + 2, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector <int> pre(n + 2, 0), suf(n + 2, 0);
  for (int i = 0; i < n + 2; ++i) {
    if (!i) pre[i] = a[i];
    else {
      if (pre[i - 1] == -1) pre[i] = -1;
      else if (pre[i - 1] > a[i]) pre[i] = -1;
      else pre[i] = a[i] - pre[i - 1];
    }
  }
  if (pre[n + 1] == 0) {
    cout << "YES\n";
    return;
  }
  for (int i = n + 1; i >= 0; --i) {
    if (i == n + 1) suf[i] = a[i];
    else {
      if (suf[i + 1] == -1) suf[i] = -1;
      else if (suf[i + 1] > a[i]) suf[i] = -1;
      else suf[i] = a[i] - suf[i + 1];
    }
  }
  for (int i = 1; i < n; ++i) {
    if (chk({pre[i - 1], a[i + 1], a[i], suf[i + 2]})) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}