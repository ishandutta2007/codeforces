#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int inf = 1e9;

int n, m;
int v;
vector<int> e, s;

void read() {
  cin >> n >> m;
  int cl, ce;
  cin >> cl >> ce;
  cin >> v;
  for (int i = 0; i < cl; ++i) {
    int x;
    cin >> x;
    s.push_back(x);
  }
  for (int i = 0; i < ce; ++i) {
    int x;
    cin >> x;
    e.push_back(x);
  }
}

vector<int> get_neighbors(const vector<int> &a, int x) {
  vector<int> ans;
  int i = lower_bound(all(a), x) - a.begin();
  if (i < (int) a.size())
    ans.push_back(a[i]);
  if (i > 0)
    ans.push_back(a[i - 1]);
  return ans;
}

void kill() {
  int q;
  cin >> q;
  while (q--) {
    int l, d, r, u;
    cin >> d >> l >> u >> r;
    if (l > r)
      swap(l, r);
    if (d > u)
      swap(d, u);

    int dist = u - d;

    int ans = inf;

    if (dist == 0) {
      ans = min(ans, r - l);
    }


    for (int st : get_neighbors(s, l)) {
      ans = min(ans, dist + abs(l - st) + abs(r - st));
    }


    for (int el : get_neighbors(e, l)) {
      ans = min(ans, ((dist + v - 1) / v) + abs(l - el) + abs(r - el));
    }

    cout << ans << endl;
  }
}


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}