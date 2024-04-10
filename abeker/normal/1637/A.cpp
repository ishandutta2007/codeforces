#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N);
  for (auto &it : a)
    scanf("%d", &it);
  vector <int> pref(N), suff(N);
  pref[0] = a[0];
  for (int i = 1; i < N; i++)
    pref[i] = max(pref[i - 1], a[i]);
  suff[N - 1] = a[N - 1];
  for (int i = N - 2; i >= 0; i--)
    suff[i] = min(suff[i + 1], a[i]);
  for (int i = 1; i < N; i++)
    if (pref[i - 1] > suff[i])
      return true;
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "YES" : "NO");
  return 0;
}