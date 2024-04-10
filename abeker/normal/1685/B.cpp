#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int A, B, C, D;
char s[MAXN];

void load() {
  scanf("%d%d%d%d%s", &A, &B, &C, &D, s);
}

void process(vector <int> &v) {
  sort(v.begin(), v.end());
  v.insert(v.begin(), 0);
  for (int i = 1; i < v.size(); i++)
    v[i] += v[i - 1];
}

bool solve() {
  int N = strlen(s);
  assert(N == A + B + 2 * C + 2 * D);
  int as = count(s, s + N, 'A');
  int bs = count(s, s + N, 'B');
  if (as != A + C + D || bs != B + C + D)
    return false;
  s[N] = s[N - 1];
  int st = -1, sum = 0;
  vector <int> ab, ba;
  for (int i = 0; i < N; i++) {
    if (s[i] != s[i + 1] && st == -1)
      st = i;
    if (s[i] == s[i + 1] && st != -1) {
      int half = (i - st) / 2;
      sum += half;
      if ((i - st) % 2)
        (s[st] == 'A' ? ab : ba).push_back(half + 1);
      st = -1;
    }
  }
  process(ab);
  process(ba);
  int rest = C + D - sum;
  if (rest <= 0)
    return true;
  for (int i = 0; i <= rest; i++)
    if (i < ab.size() && rest - i < ba.size() && ab[i] <= C && ba[rest - i] <= D)
      return true;
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}