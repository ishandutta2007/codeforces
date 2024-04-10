// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

char a[15];
int pw[10], n;

int main() {
  pw[0] = 1; rep(i, 1, 9) pw[i] = 10 * pw[i - 1];
  int T = read();
  while (T--) {
    multiset<int> Set;
    scanf("%s", a + 1);
    int len = strlen(a + 1);
    scanf("%d", &n);
    for (int i = 1; i <= len; i++) {
      while (a[i] != '0') {
        Set.insert(pw[len - i]);
        a[i]--;
      }
    }
    
//    for (auto v: Set) printf("%d ", v);
//    puts("");
    
    while (Set.size() < n) {
      multiset<int>::iterator itR;
      int cut;
      for (multiset<int>::iterator it = Set.begin(); it != Set.end(); it++) {
        if (*it != 1) {
          cut = *it / 10;
          itR = it;
          break;
        }
      }
      Set.erase(itR);
      Set.insert(cut);
//      printf("split %d %d\n", cut, 9);
      int times = 9;
      while (Set.size() < n && times > 0) {
        if (Set.size() == n - 1) Set.insert(times * cut);
        else Set.insert(cut);
        times--;
      }
      
//      for (auto v: Set) printf("%d ", v);
//      puts("");
      
    }
    while (Set.size() > n) {
      int x = *Set.begin(); Set.erase(Set.begin());
      int y = *Set.begin(); Set.erase(Set.begin());
      Set.insert(x + y);
    }
    for (auto v: Set) printf("%d ", v);
    puts("");
  }
}