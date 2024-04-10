#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

char s[N];
int n, cnt[69];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    int cur = s[i] - 'a', ann = 0;
    for (int j = 0; j < cur; ++j) {
      if (cnt[j]) {
        ann = 1; break;
      }
    }
    puts(ann ? "Ann" : "Mike");
    ++cnt[cur];
  }
  return 0;
}