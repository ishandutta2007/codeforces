#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;



int nxt(int val, int n) {
  val++;
  if (val >= n) val -= n;
  return val;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x: a) {
    cin >> x;
  }

  vector<int> killed(n, 0);
  vector<int> answer;
  map<int, int> m;
  vector<int> nxt(n);
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    nxt[i] = j;
    if (__gcd(a[i], a[j]) == 1) {
      m[i] = j;
    }
  }
  while (!m.empty()) {
    map<int, int> new_m;
    for (auto [from, to]: m) {
      if (killed[from]) continue;
      killed[to] = true;
      answer.push_back(to);
      int init_to = to;
      while (to != from && killed[to]) {
        to = nxt[to];
      }
      nxt[init_to] = to;
      if (__gcd(a[from], a[to]) == 1) {
        new_m[from] = to;
      }
    }
    m = new_m;
  }
  cout << answer.size() << " ";
  for (auto x: answer) {
    cout << x + 1 << " ";
  }
  cout << "\n";
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