#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

int n, pre[1010], suf[1010];
char str[1010];

int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  bool flgl = 0, flg0 = 1;
  rep(i, 1, n) {
    if (str[i] == ')') {
      if (flgl) flg0 = 0;
    } else {
      flgl = 1;
    }
    pre[i] = pre[i - 1] + (str[i] == '(');
  }
  if (flg0) {
    return puts("0"), 0;
  }
  per(i, n, 1) suf[i] = suf[i + 1] + (str[i] == ')');
  int pos=0;
  rep(i,1,n)if(pre[i]&&pre[i]==suf[i+1]){
    pos=i;
  }
  puts("1");
  vector <int> vec;
  rep(i,1,pos)if(str[i]=='(')vec.push_back(i);
  rep(i,pos+1,n)if(str[i]==')')vec.push_back(i);
  printf("%d\n", (int) vec.size());
  for (int x : vec) printf("%d ", x);
  return 0;
}