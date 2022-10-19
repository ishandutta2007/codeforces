#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int A = 66;

int n;
vector<ll> x[A];

int bit(ll mask, int k) {
  return (mask >> k) & 1;
}

int lv(ll mask) {
  int k = 0;
  while (mask) {
    mask >>= 1;
    ++k;
  }
  return k - 1;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    x[lv(a)].push_back(a);
  }
}

void kill() {
  vector<ll> cur;
  
  for (int k = 60; k >= 0; --k) {
    vector<ll> nx;
    ll s = 0;

    auto add = [&](ll x) {
      nx.push_back(x);
      s ^= x;
    };

    int i = 0, j = 0;
    while (true) {
      if (j < (int) x[k].size() && bit(s, k) == 0) {
        add(x[k][j++]);
      } else if (i < (int) cur.size()) {
        add(cur[i++]);
      } else {
        break;
      }
    }

    assert(i == (int) cur.size());
    if (j < (int) x[k].size()) {
      cout << "No\n";
      return;
    }

    cur = nx;
  }

  cout << "Yes\n"; // vote YES
  for (ll x : cur)
    cout << x << " ";
  cout << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}