#include <bits/stdc++.h> 

using namespace std;

const int N = 10010;

int n, m;
set <int> v;
int mark[N + N];

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &m);
  int flag = 0;
  for (int i = 1; i <= m; ++i) {
    v.clear();
    int k; scanf("%d", &k);
    while (k--) {
      int x; 
      scanf("%d", &x);
      v.insert(x);
    }
    int tmp = 1;
    for (int x : v) {
      if (v.count(-x)) {
        tmp = 0;
        break;
      }
    }
    if (tmp) {
      flag = 1;
      break;
    }
  }
  puts(flag ? "YES" : "NO");
  return 0;
}