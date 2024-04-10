// Author: wlzhouzhuan
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

const int N=400005;

int pr[N/8],mu[N],len;
bool vis[N];
int fac[N],ifac[N];
inline void init(int n){
	mu[1]=1;
	rep(i,2,n){
		if(!vis[i])pr[++len]=i,mu[i]=-1;
		for(int j=1;j<=len&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0)break;
			mu[pr[j]*i]=-mu[i];
		}
	}
	fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}

int n,k;

int main(){
	init(2e5);
	cin>>n>>k;
	if(n==1||k==1)return puts("1"),0;
	int ans=0;
	for(int cut=1;cut<=n;cut++){
		int coef=0,m=(n-1)/cut;
		poly f(m+1),g(m+1);
		rep(i,0,m){
			if(i&1)f[i]=(mod-ifac[i])%mod;
			else f[i]=ifac[i];
		}
		rep(i,0,m){
			if(i==0)g[i]=0;
			else if(i==1)g[i]=m;
			else g[i]=1ll*(qpow(i,m+1)+mod-i)*qpow(i-1)%mod;
			// for(int k=m;k>=1;k--)
			// 	g[i]=(g[i]+qpow(i,k))%mod;
			g[i]=1ll*g[i]*ifac[i]%mod;
		}
		f=f*g;
		// printf("When cut=%d\n",cut);
		// rep(i,0,min(m,k))
		// 	printf("f[%d]=%5d,",i,f[i]);
		// puts("");
		rep(i,0,min(m,k))
			coef=(coef+1ll*f[i]*(min(i+1,k)-1))%mod;
		// printf("coef=%d\n",coef);
		int cut2=cut,summu=mu[cut];
		while(cut2<n&&(n-1)/cut==(n-1)/(cut2+1)){
			summu=(summu+mu[++cut2])%mod;
		}
		ans=(ans+1ll*summu*coef)%mod;
		cut=cut2;
	}
	
/*
	for(int rem=1;rem<n;rem++){
		for(int cut=1;cut<=n;cut++)if((n-rem)%cut==0){
			int m=(n-rem)/cut;
			poly f(m+1),g(m+1);
			rep(i,0,m){
				if(i&1)f[i]=(mod-ifac[i])%mod;
				else f[i]=ifac[i];
			}
			rep(i,0,m){
				g[i]=1ll*qpow(i,m)*ifac[i]%mod;
			}
			f=f*g;
			int coef=0;
			rep(i,0,min(m,k)){
				coef=(coef+1ll*f[i]*(min(i+1,k)-1))%mod;
			}
			ans=(ans+1ll*mu[cut]*coef)%mod;
		}
	}
*/
	print((ans+mod)%mod,'\n');
	return 0;
}

/*
int a[111],ans;
int n,k;

void dfs(int u,int mx){
	if(u==n+1){
		int g=0;
		for(int i=1,j;i<=n;i++){
			j=i;
			while(j<n&&a[i]==a[j+1])j++;
			if(j<n)g=__gcd(g,j-i+1);
			i=j;
		}
		if(g==1)ans++;
		return;
	}
	for(int i=1;i<=k&&i<=mx+1;i++){
		a[u]=i;
		dfs(u+1,max(mx,i));
	}
}

int main(){
	cin>>n>>k;
	dfs(1,0);	
	cout<<ans;
}
*/