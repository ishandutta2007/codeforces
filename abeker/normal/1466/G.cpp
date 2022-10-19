#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> pii;
 
const int MAXN = 1e5 + 5;
const int MAXM = 1e2 + 5;
const int MAXL = 2e6 + 5;
const int MOD = 1e9 + 7;
 
int N, Q;
char w[MAXL];
char s[MAXM], t[MAXN];
int sum[MAXN][30];
int pot_two[MAXL];
int pot_inv[MAXL];
 
void load() {
  scanf("%d%d%s%s", &N, &Q, s, t);
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
  return (long long)x * y % MOD;
}
 
int get_sum(int ltr, int a, int b) {
  if (a >= b)
    return 0;
  return add(sum[b - 1][ltr], a ? -sum[a - 1][ltr] : 0);
}

vector <int> prefix_function(string x) {
  int n = x.size();
  vector <int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j && x[i] != x[j])
      j = pi[j - 1];
    if (x[i] == x[j])
      j++;
    pi[i] = j;
  }
  return pi;
}
 
int calc(int k, string word) {
  int idx = 0;
  string curr = s;
  for (; curr.size() < word.size(); idx++)
    curr = curr + t[idx] + curr;
  if (k < idx)
    return 0;
  vector <int> pi1 = prefix_function(word + '*' + curr);
  vector <int> pi2 = prefix_function(curr + '*' + word);
  int res = 0;
  int len = word.size(), tot = curr.size();
  for (int i = len + 1; i < len + tot + 1; i++)
    res += pi1[i] == len;
  res = mul(res, pot_inv[idx]);
  vector <int> good(len + 2);
  for (int match = len + tot + 1; match; ) {
    match = pi1[match - 1];
    good[match + 1]++;
  }
  for (int match = len + tot + 1; match; ) {
    match = pi2[match - 1];
    good[len - match]++;
  } 
  for (int i = 0; i < len; i++)
    if (good[i + 1] == 2) 
      res = add(res, get_sum(word[i] - 'a', idx, k));
  return mul(res, pot_two[k]);
}

void solve() {
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < 26; j++)
      sum[i][j] = add(i ? sum[i - 1][j] : 0, j == t[i] - 'a' ? pot_inv[i + 1] : 0);
  while (Q--) {
    int k;
    scanf("%d%s", &k, w);
    printf("%d\n", calc(k, w));
  }
}
 
void init() {
  pot_two[0] = pot_inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    pot_two[i] = mul(pot_two[i - 1], 2);
    pot_inv[i] = mul(pot_inv[i - 1], (MOD + 1) / 2);
  }
}
 
int main() {
  init();
  load();
  solve();
  return 0;
}