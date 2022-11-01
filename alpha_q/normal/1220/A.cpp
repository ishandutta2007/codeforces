#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];
int n, cnt[6969];

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  int yo = 'n' - 'a';
  while (cnt[yo]) {
    printf("1 ");
    --cnt[yo], --cnt['o' - 'a'], --cnt['e' - 'a'];
  }
  yo = 'z' - 'a';
  while (cnt[yo]) {
    printf("0 ");
    --cnt[yo], --cnt['e' - 'a'], --cnt['r' - 'a'], --cnt['o' - 'a'];
  }
  puts("");
  return 0;
}