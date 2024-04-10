#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXM = 55;
const int MOD = 998244353;

int N, M;
ll a[MAXN];
int choose[MAXM][MAXM];
vector <int> lft, other;
vector <ll> im, ker;

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%lld", a + i);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int pot2(int ex) {
  int res = 1, base = 2;
  if (ex < 0) {
    base = (MOD + 1) / 2;
    ex = -ex;
  }
  while (ex--)
    res = mul(res, base);
  return res;
}

void gen_subspace(int pos, ll mask, const vector <ll> &basis, vector <int> &by_bitcount) {
  if (pos == basis.size()) {
    by_bitcount[__builtin_popcountll(mask)]++;
    return;
  }
  gen_subspace(pos + 1, mask, basis, by_bitcount);
  gen_subspace(pos + 1, mask ^ basis[pos], basis, by_bitcount);
}

vector <int> calc_counts(vector <ll> basis) {
  vector <int> res(M + 1);
  gen_subspace(0, 0, basis, res);
  return res;
}

void compute_image() {
  for (int j = 0; j < M; j++) {
    int rnk = im.size();
    for (int i = rnk; i < N; i++)
      if (a[i] >> j & 1ll) {
        swap(a[rnk], a[i]);
        break;
      }
    if (a[rnk] >> j & 1ll) {
      lft.push_back(j);
      im.push_back(a[rnk]);
      for (int i = rnk + 1; i < N; i++)
        if (a[i] >> j & 1ll)
          a[i] ^= a[rnk];
    }
    else
      other.push_back(j);
  }
}

void compute_kernel() {
  for (int k = 0; k < other.size(); k++) {
    ll tmp = 1ll << other[k];
    for (int i = (int)im.size() - 1; i >= 0; i--)
      for (int j = lft[i] + 1; j < M; j++)
        if ((tmp & im[i]) >> j & 1ll)
          tmp ^= 1ll << lft[i];
    ker.push_back(tmp);
  }
}

void compute_choose() {
  choose[0][0] = 1;
  for (int i = 1; i <= M; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++)
      choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
  }
}

void solve() {
  compute_image();
  compute_kernel();
  compute_choose();
  if (im.size() <= M / 2) {
    int coef = pot2(N - (int)im.size());
    vector <int> ans = calc_counts(im);
    for (int i = 0; i <= M; i++)
      printf("%d ", mul(ans[i], coef));
  }
  else {
    int coef = pot2(N - M);
    vector <int> orth_comp = calc_counts(ker);
    for (int i = 0; i <= M; i++) {
      int ans = 0;
      for (int k = 0; k <= i; k++)
        for (int j = k; j <= M - i + k; j++) {
          int tmp = mul(mul(choose[j][k], choose[M - j][i - k]), orth_comp[j]);
          ans = add(ans, k % 2 ? -tmp : tmp);
        }
      printf("%d ", mul(ans, coef));
    }
  }
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}