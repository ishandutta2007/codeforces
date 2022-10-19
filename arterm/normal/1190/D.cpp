#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

int n;
pair<int, int> p[M];
int xs[M];
int f[M];

void add(int at, int val) {
  for (int i = at; i < M; i |= (i + 1)) {
    f[i] += val;
  }
}

int sum(int r) {
  int ans = 0;
  for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
    ans += f[i];
  }
  return ans;
}

int sum(int l, int r) {
  if (l >= r) {
    return 0;
  }
  return sum(r) - sum(l);
}

int get(int at) {
  return sum(at, at + 1);
}

#define set adslkfjsdf

void set(int at) {
  if (get(at) == 0)
    add(at, 1);
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].second >> p[i].first;
    xs[i] = p[i].second;
  }

  sort(xs, xs + n);
  for (int i = 0; i < n; ++i) {
    p[i].second = lower_bound(xs, xs + n, p[i].second) - xs;
  }
}

ll c2(ll x) {
  return x * (x + 1) / 2;
}

#define prev dakfldsf

void kill() {
  sort(p, p + n, greater<pair<int, int>>());

  ll ans = 0;

  int i = 0;
  while (i < n) {
    int j = i;

    int prev = M;
    
    while (j < n && p[j].first == p[i].first) {
      //cerr << p[j].second << " " << p[j].first << "\n";
      int x = p[j].second;
      set(x);
      ans -= c2(sum(x + 1, prev));
      prev = x;
      ++j;
    }


    ans -= c2(sum(0, prev));

    ans += c2(sum(0, M));

    i = j;
  }

  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);
  
  read();
  kill();
}