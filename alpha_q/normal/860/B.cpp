#include <bits/stdc++.h>

using namespace std;

const int N = 70005;
const int K = 11;

int n;
char s[N][K];
set <string> tot;
unordered_map <string, int> cnt;

int main() {
  scanf("%d", &n);
  for (int it = 0; it < n; ++it) {
    scanf("%s", s[it] + 1);
    tot.clear();
    for (int i = 1; i <= 9; ++i) {
      string cur = "";
      for (int j = i; j <= 9; ++j) {
        cur += s[it][j];
        tot.insert(cur);
      }
    }
    for (string x : tot) {
    	++cnt[x];
    }
  }
  for (int it = 0; it < n; ++it) {
    int done = 0;
    for (int l = 1; l <= 9; ++l) {
      for (int i = 1; i <= 9 - l + 1; ++i) {
        int j = i + l - 1;
        string cur = "";
        for (int k = i; k <= j; ++k) {
        	cur += s[it][k];
        }
        if (cnt[cur] > 1) {
        	continue;
        }
        for (int k = i; k <= j; ++k) {
          putchar(s[it][k]);
        }
        puts("");
        done = 1;
        break;
      }
      if (done) break;
    }
  }
  return 0;
}