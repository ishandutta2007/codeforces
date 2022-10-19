#include <bits/stdc++.h>
using namespace std;

int solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N);
  for (auto &it : a)
    scanf("%d", &it);
  vector <int> cnt(N + 1);
  for (auto it : a)
    cnt[it]++;
  if (*max_element(cnt.begin(), cnt.end()) > (N + 1) / 2)
    return -1;
  cnt = vector <int> (N + 1);
  cnt[a[0]]++;
  cnt[a[N - 1]]++;
  int blocks = 1;
  for (int i = 1; i < N ; i++)
    if (a[i] == a[i - 1]) {
      cnt[a[i - 1]]++;
      cnt[a[i]]++;
      blocks++;
    }
  return max(*max_element(cnt.begin(), cnt.end()) - 1, blocks) - 1; 
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}