#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 4e5;

int n, cnt[500];
char s[maxn + 1];
string ss[maxn];

int main(void) {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]];
  }
  int cnt_odd = 0, cnt_pair = 0;
  for (int i = 0; i < 500; ++i) {
    if (cnt[i] & 1) {
      ++cnt_odd;
    }
    cnt_pair += cnt[i] >> 1;
  }
  if (cnt_odd == 0) {
    puts("1");
    for (int i = 0; i < 500; ++i) {
      for (int j = 0; j < cnt[i] >> 1; ++j) {
        putchar(i);
      }
    }
    for (int i = 499; i >= 0; --i) {
      for (int j = 0; j < cnt[i] >> 1; ++j) {
        putchar(i);
      }
    }
    putchar('\n');
    return 0;
  }

  while (cnt_pair % cnt_odd != 0) {
    cnt_odd += 2;
    --cnt_pair;
  }

  int k = cnt_odd;
  for (int i = 0; i < 500; ++i) {
    if (cnt[i] & 1) {
      ss[--cnt_odd] = (char)i;
      --cnt[i];
    }
  }
  for (int i = 0; i < 500; ++i) {
    while (cnt_odd && cnt[i]) {
      ss[--cnt_odd] = (char)i;
      --cnt[i];
    }
  }
  int cur = 0;
  for (int i = 0; i < 500; ++i) {
    while (cnt[i]) {
      ss[cur] += (char)i;
      cnt[i] -= 2;
      ++cur;
      if (cur == k) {
        cur = 0;
      }
    }
  }

  printf("%d\n", k);
  for (int i = 0; i < k; ++i) {
    for (int j = ss[i].length() - 1; j >= 0; --j) {
      putchar(ss[i][j]);
    }
    for (int j = 1; j < ss[i].length(); ++j) {
      putchar(ss[i][j]);
    }
    putchar(' ');
  }
  putchar('\n');
  return 0;
}