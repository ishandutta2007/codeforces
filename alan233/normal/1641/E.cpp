// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

#define poly vector<int>
#define SZ(a) int(a.size())
 
const int mod = 998244353;
const int G = 3, Gi = 332748118;
void uad(int &x,int y){
	if((x+=y)>=mod)x-=mod;
}
int add(int x, int y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
int sub(int x, int y) {
  if ((x -= y) < 0) x += mod;
  return x; 
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Poly {
vector<int> Rev, W;
int lim, L;
void getR(int len) {
  lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  Rev.resize(lim), W.resize(lim), W[0] = 1;
  for (int i = 0; i < lim; i++) Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L - 1);
}
void wf(poly &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) a[i] = 1ll * (i + 1) * a[i + 1] % mod;
  a[n - 1] = 0;
}
void jf(poly &a) {
  int n = a.size();
  for (int i = n - 1; i >= 1; i--) a[i] = 1ll * a[i - 1] * qpow(i) % mod;
  a[0] = 0;
}
void NTT(poly &a, int opt) {
  for (int i = 0; i < lim; i++) if (i < Rev[i]) swap(a[i], a[Rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int k = 1; k < mid; k++) W[k] = 1ll * W[k - 1] * Wn % mod;
    for (int j = 0; j < lim; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = 1ll * W[k] * a[j + k + mid] % mod;
        a[j + k] = add(x, y);
        a[j + k + mid] = sub(x, y);
      }
    }
  }
  if (opt == -1) {
    int linv = qpow(lim);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
  }
}
poly operator * (poly a, poly b) {
  int len = a.size() + b.size() - 1;
  if(len<=200){
	  poly c(len);
	  for(int i=0;i<SZ(a);i++)
	  	for(int j=0;j<SZ(b);j++)
		  	uad(c[i+j],1ull*a[i]*b[j]%mod);
	return c;
  }
  getR(len);
  a.resize(lim), b.resize(lim);
  NTT(a, 1), NTT(b, 1);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  NTT(a, -1);
  a.resize(len);
  return a;
}
poly Inv(poly a) {
  if (SZ(a) == 1) return vector<int> (1, qpow(a[0]));
  int len = a.size();
  poly ta = a; ta.resize((len + 1) / 2);
  poly tb = Inv(ta);
  getR(2 * len), a.resize(lim), tb.resize(lim);
  NTT(a, 1), NTT(tb, 1);
  for (int i = 0; i < lim; i++) tb[i] = 1ll * tb[i] * (mod + 2 - 1ll * a[i] * tb[i] % mod) % mod;
  NTT(tb, -1);
  tb.resize(len);
  return tb;
}
poly Ln(poly a) {
  poly ta = a; wf(ta);
  int len = a.size();
  a = ta * Inv(a), jf(a);
  a.resize(len);
  return a;
}
poly Exp(poly a) {
  if (SZ(a) == 1) return vector<int> (1, 1);
  int len = a.size();
  poly ta = a; ta.resize((len + 1) / 2);
  poly tb = Exp(ta); tb.resize(len);
  poly Lnb = Ln(tb);
  assert(Lnb.size() == len);
  for (int i = 0; i < len; i++) Lnb[i] = (a[i] - Lnb[i] + mod) % mod;
  Lnb[0] = (Lnb[0] + 1) % mod;
  tb = tb * Lnb;
  tb.resize(len);
  return tb;
}
}
using namespace Poly;

const int N=500005;

int pw[N],pre[N];
int a[N],b[N],n,m;

poly ff(n+1),gg(n+1),H;

void cdq(int l,int r){
	if(l==r){
		uad(H[l+l],1ll*ff[l]*gg[l]%mod);
		return;
	}
	int mid=l+r>>1;
	poly f(mid-l+1),g(r-mid);
	rep(i,l,mid)f[i-l]=ff[i];
	rep(i,mid+1,r)g[i-mid-1]=gg[i];
	f=f*g;
	rep(i,0,r-l-1)uad(H[i+l+mid+1],f[i]);
	cdq(l,mid),cdq(mid+1,r);
}

int main(){
	n=read(),m=read();
	pw[0]=1;
	rep(i,1,n)a[i]=read(),pw[i]=2*pw[i-1]%mod;
	rep(i,1,m)b[i]=read(),pre[b[i]]++;
	rep(i,1,4*n)pre[i]+=pre[i-1];
	ff.resize(4*n+1),gg.resize(4*n+1),H.resize(8*n+1);
	rep(i,0,n)ff[i]=1;
	rep(i,1,3*n)ff[i+n]=pw[pre[i-1]];
	rep(i,0,n)gg[i]=pw[m];
	rep(i,1,3*n)gg[i+n]=pw[m-pre[i]];
	cdq(0,4*n);
/*
	printf("special case\n");
	rep(j,0,n-1){
		printf("%d %d\n",ff[1+n-j],gg[n+1+j]);
	}
	puts("----");
*/
	// rep(i,0,4*n)
	// 	rep(j,i,4*n)
	// 		uad(H[i+j],1ll*ff[i]*gg[j]%mod);
	int ans=0;
	rep(i,1,n){
		int coef=H[2*i+2*n];
		// printf("when i=%d,coef=%d\n",i,coef);
		ans=(ans+1ll*(coef+mod-(n+i+1))*a[i])%mod;
	}
	print(1ll*ans*qpow(pw[m]-1)%mod,'\n');
	return 0;
}