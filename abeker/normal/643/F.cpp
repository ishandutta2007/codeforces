#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef unsigned long long ll;
typedef pair <ll, int> pii;

const int MAXP = 135;
const ll MOD = 1ull << 32;

int N, P, Q;
pii choose[MAXP];
ll val[MAXP];

void load() {
  cin >> N >> P >> Q;
}

inline ll add(ll x, ll y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  return x;
}

inline ll mul(ll x, ll y) {
  return x * y % MOD;
}

pii operator *(pii x, pii y) {
  return pii(mul(x.first, y.first), x.second + y.second);
}

pii inv(pii x) {
  ll tmp = 1;
  for (int i = 0; i < 31; i++) {
    tmp = mul(tmp, x.first);
    x.first = mul(x.first, x.first);
  }
  return pii(tmp, -x.second);
}

pii get(ll x) {
  int v2 = 0;
  for (; !(x % 2); x /= 2)
    v2++;
  return pii(x, v2);
}

ll eval(pii x) {
  assert(x.second >= 0);
  if (x.second >= 32)
    return 0;
  while (x.second--)
    x.first = mul(x.first, 2);
  return x.first;
}

ll solve() {
  P = min(P, N - 1);
  choose[0] = pii(1, 0);
  val[0] = 1;
  for (int i = 1; i <= P; i++) {
    choose[i] = choose[i - 1] * get(N - i + 1) * inv(get(i));
    val[i] = eval(choose[i]);
  }
  
  ll sol = 0;
  for (int i = 1; i <= Q; i++) {
    ll tmp = 0, prod = 1;
    for (int j = 0; j <= P; j++) {
      tmp = add(tmp, mul(val[j], prod));
      prod = mul(prod, i);
    }
    sol ^= mul(i, tmp);
  }
  
  return sol;
}

int main() {
  load();
  cout << solve() << endl;
  return 0;
}