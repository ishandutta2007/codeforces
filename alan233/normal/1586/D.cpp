// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

int a[1000005],n;

int main(){
  n=read();
  a[n]=n;
  int x;
  rep(i,1,n-1){
    printf("? ");
    rep(j,1,n-1)printf("%d ",n);
    printf("%d\n",n-i);
    fflush(stdout);
    x=read();
    if(!x){
      a[n]=i;
      break;
    }
  }
  rep(i,1,n){
    if (i==a[n])continue;
    printf("? ");
    rep(j,1,n-1)printf("%d ",a[n]);
    printf("%d\n",i);
    fflush(stdout);
    x=read();
    a[x]=i;
  }
  printf("!");
  rep(i,1,n)printf(" %d",a[i]);
  puts("");
  fflush(stdout);
  return 0;
}