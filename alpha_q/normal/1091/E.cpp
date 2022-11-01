#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 700010;
const ll INF = 1e18 + 5;

bitset <N> vis; int n;
priority_queue <ll> pq;
ll d[N], suf[N], suff[N], p[N], val[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", d + i);
  }

  sort(d + 1, d + n + 1);
  reverse(d + 1, d + n + 1);
  
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + d[i];
  }
  d[0] = n, d[n + 1] = 0;

  ll sum = 0, sz = 0; suf[n + 1] = 0;
  for (int i = n; i > 0; --i) {
    pq.push(d[i]), ++sz, sum += d[i];
    while (!pq.empty() and pq.top() > i) {
      sum -= pq.top(), pq.pop(), --sz;
    }
    suf[i] = sum + (n - i + 1 - sz) * i;
  }
  while (!pq.empty()) pq.pop();
  sum = 0, sz = 0; suff[n + 1] = 0;
  for (int i = n; i > 0; --i) {
    pq.push(d[i]), ++sz, sum += d[i];
    while (!pq.empty() and pq.top() >= i) {
      sum -= pq.top(), pq.pop(), --sz;
    }
    suff[i] = sum + (n - i + 1 - sz) * (i - 1);
  }

  val[n + 1] = INF;
  for (ll i = n; i > 0; --i) {
    val[i] = min(val[i + 1], i * (i + 1) + suf[i + 1] - p[i]);
  }
  
  ll mx = -INF;
  for (ll i = 0; i <= n; ++i) {
    ll yo = p[i] - suff[i + 1] - i * (i - 1);
    if (yo > i) break;
    mx = max(mx, yo);
    ll l = d[i + 1], r = d[i];
    int flag = 0;
    l = max(l, mx);
    r = min(r, i * (i + 1) + suf[i + 1] - p[i]);
    r = min(r, val[i + 1]);
    for (ll j = l; j <= r; ++j) vis[j] = 1;
  }
  
  int tot = 0;
  for (int i = 0; i <= n; ++i) {
    if (!vis[i]) continue;
    if ((i + p[n]) & 1) continue;
    printf("%d ", i); ++tot;
  }

  if (tot == 0) printf("-1");
  puts("");
  return 0;
}