#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 500005;
const ll INF = (ll)1e18;

int N, K;
ll a[MAXN], b[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%lld", a + i);
  for (int i = 0; i < N; i++)
    scanf("%lld", b + i);
}

pii get_opt(ll c) {
  for (int i = 0; i < N; i++) {
    a[i] -= c;
    b[i] -= c;
  }
  
  multiset <ll> S, B;
  ll res = 0;
  for (int i = 0; i < N; i++) {
    S.insert(a[i]);
    ll p = b[i] + (S.empty() ? INF : *S.begin());
    ll q = b[i] - (B.empty() ? -INF : *B.rbegin());
    if (p < 0 && p < q) {
      S.erase(S.begin());
      B.insert(b[i]);
      res += p;
    }
    else if (q < 0) {
      B.erase(--B.end());
      B.insert(b[i]);
      res += q;
    }
  }
  
  for (int i = 0; i < N; i++) {
    a[i] += c;
    b[i] += c;
  }
  
  return pii(res, B.size());
}

ll solve() {
  ll lo = 0, hi = (ll)1e12;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    pii tmp = get_opt(mid);
    if (tmp.second >= K)
      hi = mid;
    else
      lo = mid + 1;
  }
  pii sol = get_opt(lo);
  return sol.first + 2 * sol.second * lo; 
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}