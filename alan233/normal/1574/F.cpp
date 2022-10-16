#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
#define poly vector<int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N = 300005;
const int mod = 998244353;
const int G = 3;
const int Gi = 332748118;
 
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}
 
namespace Poly {
  poly r, W;
  int lim, L;
  void getR(int n) {
    lim = 1, L = 0;
    while (lim <= n) lim <<= 1, L++;
    r.resize(lim), W.resize(lim);
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << L - 1);
  }
  void reverse(poly &a) {
    for (int i = 0, j = a.size() - 1; i < j; i++, j--) swap(a[i], a[j]);
  }
  void wf(poly &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) a[i] = 1ll * (i + 1) * a[i + 1] % mod;
    a[n - 1] = 0;
  }
  void jf(poly &a) {
    int n = a.size() - 1;
    for (int i = n - 1; i >= 1; i--) a[i] = 1ll * a[i - 1] * qpow(i) % mod;
    a[0] = 0;
  }
  void NTT(poly &a, int opt) {
    for (int i = 0; i < lim; i++) if (i < r[i]) swap(a[i], a[r[i]]);
    for (int mid = 1; mid < lim; mid <<= 1) {
      int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
      W[0] = 1;
      for (int k = 1; k < mid; k++) W[k] = 1ll * W[k - 1] * Wn % mod;
      for (int j = 0; j < lim; j += mid << 1) {
        for (int k = 0; k < mid; k++) {
          int x = a[j + k], y = 1ll * a[j + k + mid] * W[k] % mod;
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
    getR(len), a.resize(lim), b.resize(lim);
    NTT(a, 1), NTT(b, 1);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
    NTT(a, -1), a.resize(len);
    return a;
  }
  poly mul(poly a, poly b) {
    return a * b;
  }
  poly Inv(poly a) {
    if (a.size() == 1) return {qpow(a[0])};
    int n = a.size();
    poly ha = a; ha.resize(n + 1 >> 1);
    poly b = Inv(ha);
    getR(2 * n), a.resize(lim), b.resize(lim);
    NTT(a, 1), NTT(b, 1);
    for (int i = 0; i < lim; i++) b[i] = 1ll * b[i] * (mod + 2 - 1ll * a[i] * b[i] % mod) % mod;
    NTT(b, -1), b.resize(n);
    return b;
  }
  poly Ln(poly a) {
    poly ta = a; wf(ta);
    int n = a.size();
    a = ta * Inv(a); jf(a);
    a.resize(n);
    return a;
  }
  poly Exp(poly a) {
    if (a.size() == 1) return {1};
    int n = a.size();
    poly ta = a; ta.resize(n + 1 >> 1);
    poly b = Exp(ta); b.resize(n);
    poly tb = Ln(b);
    for (int i = 0; i < n; i++) tb[i] = (mod + a[i] - tb[i]) % mod;
    tb[0]++;
    b = b * tb;
    b.resize(n);
    return b;
  }
  poly Pow(poly a, int b, int c) {
    poly ta(a.size());
    int pos = 0, mul;
    while (pos < a.size() && !a[pos]) pos++;
    if (pos == a.size()) return a;
    for (int i = 0; i + pos < a.size(); i++) ta[i] = a[i + pos];
    mul = ta[0];
    for (int i = 0; i < ta.size(); i++) ta[i] = 1ll * ta[i] * qpow(mul) % mod;
    assert(ta[0] == 1);
    ta = Ln(ta);
    for (int i = 0; i < ta.size(); i++) ta[i] = 1ll * ta[i] * b % mod;
    ta = Exp(ta);
    mul = qpow(mul, c);
    for (int i = 0; i < ta.size(); i++) ta[i] = 1ll * ta[i] * mul % mod;
    if (1ll * pos * b >= ta.size()) {
      for (int i = 0; i < ta.size(); i++) ta[i] = 0;
    } else {
      for (int i = ta.size() - 1; i >= pos * b; i--) ta[i] = ta[i - pos * b];
      for (int i = pos * b - 1; i >= 0; i--) ta[i] = 0;
    }
    return ta;
  }
}
using namespace Poly;

inline void Add(int &a,int b){a+=(a+b>=mod)?b-mod:b;}
int fa[N],sz[N],to[N],a[N],n,m,k,pre[N],tag[N];
int find_fa(int x){return fa[x]==x?x:fa[x]=find_fa(fa[x]);}
inline void merge(int x,int y){
	int fy=find_fa(y),fx=find_fa(x);
	if(fy==fx){tag[fx]=1;return;}
	fa[fy]=fx;
	sz[fx]+=sz[fy];
	tag[fx]|=tag[fy];
}
poly g;
int buc[N],tot,f[N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)fa[i]=i,sz[i]=1;
	for(int i=1,c;i<=n;++i){
		scanf("%d",&c);
		for(int j=1;j<=c;++j){
			scanf("%d",&a[j]);
			if(j==1)continue;
			if((pre[a[j]]&&pre[a[j]]!=a[j-1])||(to[a[j-1]]&&to[a[j-1]]!=a[j])){
				merge(a[j-1],a[j]);
				tag[find_fa(a[j])]=1;
			}else if(!to[a[j-1]]){
				to[a[j-1]]=a[j];
				pre[a[j]]=a[j-1];
				merge(a[j-1],a[j]);
			}
		}
	}
	g.resize(m+1);
	for(int i=1;i<=k;++i){
		if(find_fa(i)!=i||tag[i])continue;
		++g[sz[i]];
	}
	g[0]=1;
	rep(i,1,m)g[i]=(mod-g[i])%mod;
	g=Inv(g);
	print(g[m],'\n');
	return 0;
}