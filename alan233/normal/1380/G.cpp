// Author: wlzhouzhuan
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

const int N=300005;
const int mod = 998244353;

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

int a[N],sum[N],n;

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1]+a[i])%mod;
    }
    int invn=qpow(n);
    for(int k=1;k<=n;k++){
        int ans=0,go=(n-k-1)/k+1;
        int mo=(n-1)%k+1;
        for(int i=1,j=mo;i<=n-k;i+=k,j+=k){
            j=min(j,n-k);
            int pre=1ll*(sum[j]+mod-sum[i-1])*(go-(i-1)/k)%mod;
            ans=(ans+pre)%mod;
        }
        go--;
        for(int i=mo+1,j=k;i<=n-k;i+=k,j+=k){
            j=min(j,n-k);
            int pre=1ll*(sum[j]+mod-sum[i-1])*(go-(i-1)/k)%mod;
            ans=(ans+pre)%mod;
        }
//        printf("%d ",ans);
        printf("%d ",1ll*ans*invn%mod);
    }
}