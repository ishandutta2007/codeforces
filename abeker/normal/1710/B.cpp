#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

struct Event {
  ll rain;
  int pos, type;
  Event(int pos, int type, ll rain) : pos(pos), type(type), rain(rain) {}
  bool operator <(const Event &rhs) const {
    if (pos != rhs.pos)
      return pos < rhs.pos;
    return type < rhs.type;
  }
};

class Fenwick {
  vector <ll> v;
  vector <int> fen;
public:
  Fenwick(vector <ll> _v) : v(_v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    fen.resize(v.size() + 1);
  }
  int compress(ll val) const {
    return lower_bound(v.begin(), v.end(), val) - v.begin() + 1;
  }
  void update(ll val) {
    for (int x = compress(val); x < fen.size(); x += x & -x)
      fen[x]++;
  }
  int query(ll val) const {
    int res = 0;
    for (int x = compress(val); x; x -= x & -x)
      res += fen[x];
    return res;
  }
};

int N, M;
int x[MAXN], p[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d%d", x + i, p + i);
}

void solve() {
  vector <Event> events;
  vector <ll> lft, rig;
  for (int i = 0; i < N; i++) {
    events.emplace_back(x[i] - p[i], -2 * (i + 1), p[i] - x[i]);
    events.emplace_back(x[i], 2 * (i + 1), p[i] - x[i]);
    events.emplace_back(x[i] + 1, -2 * i - 1, p[i] + x[i]);
    events.emplace_back(x[i] + p[i], 2 * i + 1, p[i] + x[i]);
    for (auto diff : {-p[i], 0, 1, p[i]})
      events.emplace_back(x[i] + diff, 0, 0);
    lft.push_back(p[i] - x[i]);
    rig.push_back(p[i] + x[i]);
  }
  sort(events.begin(), events.end());
  ll sum = 0;
  int diff = 0, crit = 0;
  for (auto &it : events)
    if (it.type) {
      int delta = it.type % 2 ? -1 : 1;
      int coef = it.type < 0 ? 1 : -1;
      diff += coef * delta;
      sum += coef * it.rain;
    }
    else {
      it.rain = (ll)diff * it.pos + sum;
      if (it.rain > M) {
        lft.push_back(it.rain - it.pos - M);
        rig.push_back(it.rain + it.pos - M);
        crit++;
      }
    }
  vector <int> cnt(N);
  Fenwick L(lft), R(rig);
  for (auto it : events)
    if (it.type) {
      int curr = it.type % 2 ? R.query(it.rain) : L.query(it.rain);
      cnt[(abs(it.type) - 1) / 2] += it.type < 0 ? -curr : curr;
    }
    else if (it.rain > M) {
      L.update(it.rain - it.pos - M);
      R.update(it.rain + it.pos - M);
    }
  for (int i = 0; i < N; i++) 
    printf("%d", cnt[i] == crit);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}