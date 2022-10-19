#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define get dsalfhadshf

const int M = 3030;
const ll inf = 1e18;

int a[M];
int n;

vector<pair<int, ll>> cur;

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

ll get(int at, int k) {
  int x = upper_bound(cur.begin(), cur.end(), make_pair(at, inf)) - cur.begin();

  if (x == 0)
    return cur[0].second + 1ll * k * (cur[0].first - at);

  if (x == (int) cur.size())
    return cur.back().second;

  auto A = cur[x - 1];
  auto B = cur[x];

  ll dy = B.second - A.second;
  ll dx = B.first - A.first;
  assert(dy % dx == 0);
  ll coeff = dy / dx;
  return A.second + coeff * (at - A.first);
}

ll mabs(ll x) {
  return x > 0 ? x : -x;
}

void kill() {
  cur.push_back(make_pair(a[0], 0ll));

  for (int i = 1; i < n; ++i) {
    vector<int> points;
    vector<pair<int, ll>> nxt;

    points.push_back(a[i]);
    for (auto t : cur)
      points.push_back(t.first + 1);

    sort(points.begin(), points.end());

    ll curmin = inf;

    for (int x : points) {
      curmin = min(curmin, get(x - 1, i));
      nxt.push_back(make_pair(x, curmin + mabs(x - a[i])));
    }

    cur = nxt;
  }

  ll ans = inf;
  for (auto t : cur)
    ans = min(ans, t.second);

  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}