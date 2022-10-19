#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

int N, K;
int x[MAXN], r[MAXN], f[MAXN];
vector <pii> F, R;
int fen[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) 
    scanf("%d%d%d", x + i, r + i, f + i);
}

void update(int x) {
  for (x++; x < MAXN; x += x & -x)
    fen[x]++;
}

int get(int x) {
  int res = 0;
  for (x++; x; x -= x & -x)
    res += fen[x];
  return res;
}

int get(int lo, int hi) {
  if (lo > hi)
    return 0;
  return get(hi) - get(lo - 1);
}

int lb(pii p) {
  return lower_bound(F.begin(), F.end(), p) - F.begin();
}

int ub(pii p) {
  return upper_bound(F.begin(), F.end(), p) - F.begin();
}

ll solve() {
  for (int i = 0; i < N; i++) {
    F.push_back(pii(f[i], x[i]));
    R.push_back(pii(r[i], i));
  }
  
  sort(F.begin(), F.end());
  sort(R.begin(), R.end(), greater <pii> ());  
     
  ll sol = 0;
  for (int i = 0; i < R.size(); i++) {
    int id = R[i].second;
    for (int j = -K; j <= K; j++) 
      sol += get(lb(pii(f[id] + j, x[id] - r[id])), ub(pii(f[id] + j, x[id] + r[id])) - 1);
    update(lb(pii(f[id], x[id])));
  }
  
  return sol;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}