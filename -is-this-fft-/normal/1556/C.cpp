#include <iostream>

using namespace std;

typedef long long ll;

struct Seq {
  ll l, r;

  Seq (ll _l = 0, ll _r = 0) : l(_l), r(_r) {}
};

Seq merge (Seq p, Seq q) {
  return Seq(p.l + max(0LL, q.l - p.r), q.r + max(0LL, p.r - q.l));
}

const int MAX_N = 1e3 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = 0;
  for (int i = 0; i < n; i += 2) {
    Seq cur (0, 0);
    for (int j = i + 1; j < n; j += 2) {
      ll lopt = max(0LL, arr[i] - cur.l + 1);
      ll ropt = max(0LL, arr[j] - cur.r + 1);
      ans += min(lopt, ropt);
      if (j == i + 1) {
        ans--;
      }

      cur = merge(cur, Seq(arr[j], 0));
      cur = merge(cur, Seq(0, arr[j + 1]));
    }
  }

  cout << ans << endl;
}