#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;

int p[M];
ll s[M];
ll mx = 0;
int n, a[M], b[M];
bool u[M];

void ini() {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    s[i] = 0;
  }
}

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y)
    return;
  p[y] = x;
  s[x] += s[y];
  mx = max(mx, s[x]);
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    --b[i];
  }
}


void kill() {
  ini();
  vector<ll> ans;
  for (int i = n - 1; i >= 0; --i) {
    ans.push_back(mx);

    int x = b[i];
    u[x] = true;
    mx = max<ll>(mx, a[x]);
    s[x] = a[x];

    if (x + 1 < n && u[x + 1])
      uni(x, x + 1);
    if (x > 0 && u[x - 1])
      uni(x, x - 1);
  }

  reverse(ans.begin(), ans.end());
  for (ll x : ans)
    cout << x << "\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}