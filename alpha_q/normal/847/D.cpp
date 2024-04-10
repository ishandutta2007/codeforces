#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200005;

int n;
ll t, a[N];
priority_queue <ll> pq;

int main() {
  scanf("%d %lld", &n, &t);
  --t;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    a[i] -= i, a[i] = max(a[i], 0LL);
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    --t, pq.push(a[i]);
    while (!pq.empty() and pq.top() > t) pq.pop();
    mx = max(mx, (int) pq.size()); 
  }
  printf("%d\n", mx);
  return 0;
}