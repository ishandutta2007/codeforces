#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 1000100;

#define get dslakjflsdfk

int f[M];

void add(int at, int x) {
  for (int i = at; i < M; i |= (i + 1))
    f[i] += x;
}

int get(int r) {
  int ans = 0;
  for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
    ans += f[i];
  return ans;
}

int get(int l, int r) {
  return get(r) - get(l);
}

int n, k;

int sub(int x, int y) {
  x -= y;
  if (x < 0)
    x += n;
  return x;
};


int sum(int l, int k) {
  if (l + k <= n)
    return get(l, l + k);
  else
    return get(l, n) + get(0, l + k - n);
}



int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  cin >> n >> k;

  k = min(k, n - k);

  int cur = 0;
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    int t = sum((cur + 1) % n, k - 1) + sum(sub(cur, k - 1), k - 1);
    ans += t + 1;
    //cerr << "t = " << t << endl;
    add(cur, 1);
    cur = (cur + k) % n;
    cout << ans << " ";
  }

  cout << endl;
}