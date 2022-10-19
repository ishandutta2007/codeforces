#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N, K;
char s[MAXN];

void load() {
  scanf("%d%d%s", &N, &K, s);
}

bool solve() {
  vector <int> which(K, 0);
  for (int i = 0; i < N; i++)
    if (s[i] != '?') {
      int tmp = s[i] == '0' ? 1 : -1;
      int &ref = which[i % K];
      if (ref && ref != tmp)
        return false;
      ref = tmp;
    }
  int sum = 0, other = 0;
  for (int i = 0; i < K; i++)
    if (which[i])
      sum += which[i];
    else
      other++;
  return abs(sum) <= other;
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