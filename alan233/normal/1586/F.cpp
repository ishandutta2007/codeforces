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

const int N=1005;
int n,k;
int a[N][N],c;
void calc(int l,int r,int d,int w){
  for(int i=l;i<=r;i+=d)
    for(int p=i;p<i+d;p++)
      if(i<=n)for(int j=i+d;j<=r;j++)
        if(j<=n)a[p][j]=w;
}
void dfs(int d,int w){
  if(d>=n)return;
  ckmax(c,w);
  for(int i=1;i<=n;i+=d*k){
    calc(i,i+d*k-1,d,w);
  }
  dfs(d*k,w+1);
}
int main(){
  n=read(),k=read();
  dfs(1,1);
  printf("%d\n",c);
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      printf("%d ",a[i][j]);
  puts("");
  return 0; 
}