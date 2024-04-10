#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> pil;

const int MAX = 3e5 + 5;
const pil ZERO = {0, 0};

pil operator +(const pil &p, const pil &q) {
  return pil(p.first + q.first, p.second + q.second);
}

pil operator -(const pil &p, const pil &q) {
  return pil(p.first - q.first, p.second - q.second);
}

void operator +=(pil &p, const pil &q) {
  p = p + q;
}

pil operator -(const pil &p) {
  return pil(-p.first, -p.second);
}

class Fenwick {
  pil fen[MAX];
public:
  Fenwick() {
    fill(fen, fen + MAX, ZERO);
  }
  void updatePoint(int x, pil val) {
    for (x++; x < MAX; x += x & -x)
      fen[x] += val;
  }
  pil queryPoint(int x) const {
    pil res = ZERO;
    for (x++; x; x -= x & -x)
      res += fen[x];
    return res;
  }
  void updateRange(int from, int to, pil val) {
    updatePoint(from, val);
    updatePoint(min(to, MAX - 1), -val);
  }
  pil queryRange(int from, int to) const {
    return queryPoint(min(to, MAX - 1) - 1) - queryPoint(from - 1);
  }
};

int main() {
  int N;
  scanf("%d", &N);
  ll ans = 0;
  Fenwick LR, RL;
  while (N--) {
    int x;
    scanf("%d", &x);
    pil tmp = RL.queryPoint(x);
    ans += (ll)tmp.first * x - tmp.second;
    for (int i = 0; i < MAX; i += x) {
      tmp = LR.queryRange(i, i + x);
      ans += tmp.second - (ll)tmp.first * i;
      RL.updateRange(i, i + x, pil(1, i));
    }
    LR.updatePoint(x, pil(1, x));
    printf("%lld ", ans);
  }
  puts("");
  return 0;
}