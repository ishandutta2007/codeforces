#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

#define mx first
#define lazy second

const int MAXN = 100005;
const int offset = 1 << 17;

int N;
int num[MAXN];
pii t[2 * offset];

pii merge(pii l, pii r) {
  return pii(max(l.mx, r.mx), l.lazy + r.lazy);
}

void prop(int x) {
  t[x].mx += t[x].lazy;
  if (x < offset) {
    t[2 * x].lazy += t[x].lazy;
    t[2 * x + 1].lazy += t[x].lazy;
  }
  t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    t[x].mx += val;
    if (x < offset) {
      t[2 * x].lazy += val;
      t[2 * x + 1].lazy += val;
    }
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
  t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void update(int from, int to, int val) {
  update(1, 0, offset, from, to, val);
}

int query(int x, int lo, int hi) {
  if (hi - lo == 1)
    return lo;
  int mid = (lo + hi) / 2;
  prop(2 * x);
  prop(2 * x + 1);
  if (t[2 * x + 1].mx > 0)
    return query(2 * x + 1, mid, hi);
  return query(2 * x, lo, mid);
}

int main() {
  scanf("%d", &N);
  
  t[offset].mx = 1;
  for (int i = offset - 1; i >= 0; i--)
    t[i] = merge(t[2 * i], t[2 * i + 1]);
    
  num[0] = -1;
  for (int i = 0; i < N; i++) {
    int pos, type;
    scanf("%d%d", &pos, &type);
    if (type) {
      scanf("%d", num + pos);
      update(1, pos + 1, 1);
    }
    else
      update(1, pos + 1, -1);
    printf("%d\n", num[query(1, 0, offset)]);
  }
  
  return 0;
}