/*
start thinking:
BULB:
result of thinking: Pure.

30min(), .

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
#define maxq 1000005
int n, q, a[maxn], st[18][maxn], pos[maxn];
ll ans[maxq];

int qmaxa(int l, int r) {
  int i = 31 - __builtin_clz(r - l + 1);
  return max(st[i][l], st[i][r - (1 << i) + 1]);
}

struct Event {
  // fl = 0(), z = ; fl = 1(), z = id.
  int fl, x, y, z;
  bool operator<(const Event &b) const {
    if (x == b.x)
      return fl < b.fl;
    return x > b.x;
  }
};
vector<Event> events;
void addEvent(int fl, int x, int y, int z) {
  if (1 <= x && x <= y && y <= n)
    events.push_back({fl, x, y, z});
}

void build(int l, int r) {
  if (l >= r)
    return;
  int mid = pos[qmaxa(l, r)];
  vector<P> foo;
  for (int i = 1; i * i < a[mid]; i++) {
    if (a[mid] % i)
      continue;
    int j = a[mid] / i;
    if (pos[i] < l || pos[i] > r || pos[j] < l || pos[j] > r)
      continue;
    foo.push_back({min({pos[i], pos[j], mid}), max({pos[i], pos[j], mid})});
  }
  sort(foo.begin(), foo.end(), greater<P>());
  int mini = r + 1;
  for (auto i : foo) {
    if (i.second >= mini)
      continue;
    addEvent(0, i.first, i.second, 1);
    addEvent(0, i.first, mini, -1);
    mini = i.second;
  }
  addEvent(0, l - 1, mini, -1);
  addEvent(0, l - 1, r + 1, 1);

  // cout << "build " << l << " " << r << endl;
  // for (auto i : events) {
  //   cout << i.fl << " " << i.x << " " << i.y << " " << i.z << endl;
  // }
  // system("pause");

  build(l, mid - 1);
  build(mid + 1, r);
}

ll bit1[maxn], bitx[maxn], bity[maxn], bitxy[maxn];
void add(ll* bit, int pos, ll x) {
  for (int i = pos; i <= n; i += i & -i)
    bit[i] += x;
}
ll qsum(ll* bit, int pos) {
  ll res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i];
  return res;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    pos[st[0][i] = a[i]] = i;
  }
  for (int i = 1; i <= 17; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  build(1, n);
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    events.push_back({1, x, y, i});
  }
  sort(events.begin(), events.end());

  // for (auto i : events) {
  //   cout << i.fl << " " << i.x << " " << i.y << " " << i.z << endl;
  // }
  // system("pause");

  for (auto i : events) {
    if (i.fl == 0) {
      add(bit1, i.y, -i.z);
      add(bitx, i.y, i.z * i.x);
      add(bity, i.y, i.z * i.y);
      add(bitxy, i.y, -1ll * i.z * i.x * i.y);
    } else {
      ans[i.z] = ll(i.x - 1) * (i.y + 1) * qsum(bit1, i.y)
                  + (i.x - 1) * qsum(bity, i.y)
                  + (i.y + 1) * qsum(bitx, i.y)
                  + qsum(bitxy, i.y);
    }
  }
  for (int i = 1; i <= q; i++)
    printf("%lld\n", ans[i]);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}