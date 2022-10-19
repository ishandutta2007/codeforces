#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];
int cnt[MAXN], sum[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
}

bool solve() {
  for (int i = 1; i <= N; i++)
    cnt[i] = sum[i] = 0;
  int ptr = N;
  for (int i = N; i; i--)
    for (; ptr && b[ptr] == a[i]; ptr--)
      cnt[i]++;
  if (ptr)
    return false;
  for (int i = 1; i <= N; i++)
    if ((sum[a[i]] += cnt[i] - 1) > 0)
      return false;
  return true;
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