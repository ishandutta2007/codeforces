// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
int T,n,m;
ll a[maxn],b[maxn];
ll f[maxn],g[maxn];
ll S(int bd) { return (ll)bd*(bd+1)/2; }
ll S2(int bd) { return S(bd/2)*2; }
vector<int> ans;
bool solve(ll d1,ll d2,int bd,int st) {
	ll delta=d1+d2;
	int c1=(bd+1)/2,c0=bd/2;
	if (delta>c1||delta<-c0) return 0;
	d2+=S2(bd);
	delta+=c0;
	if (S(delta)<=d2&&d2<=S(bd)-S(bd-delta)) {
		ans.clear();
		for (int i=bd;i>=1;i--) {
			bool chose=0;
			if (d2>S(i-1)-S(i-1-delta)) {
				d2-=i,delta--,chose=1;
			}
			if (chose^(i&1)^1) ans.push_back(bd-i+1);
		}
		assert(d2==0&&delta==0);
		for (int i=bd+1;i<=n;i++) if (f[i]+1==g[i-st+1]) ans.push_back(i);
		printf("%d\n",(int)ans.size());
		for (int &x : ans) printf("%d ",x); puts("");
		return 1;
	}
	return 0;
}
const int mod=998244353;
int tot[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
bool chk(int x) {
	for (int i=x+2;i<=x+m-1;i++) if (f[i]!=g[i-x+1]&&f[i]+1!=g[i-x+1]) return 0;
	return 1;
}
int G[maxn],F[maxn];
int s[maxn];
void add(int l,int r,int x) {
	if (l>r) return;
	l=max(l,0);
	update(s[l],x),update(s[r+1],mod-x);
}
#define SZ(x) ((int)x.size())
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> poly;
const int max_len=1<<20,N=max_len+5;
int _inv_[N];
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>inline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
void print(const poly &a){
	for(auto it:a) printf("%d ",it);
	printf("\n");
}
inline poly operator << (poly a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator <<= (poly &a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator >> (const poly &a,uint b){return b>=a.size()?poly():poly{a.begin()+b,a.end()};}
inline poly operator >>= (poly &a,uint b){return a=b>=a.size()?poly():poly{a.begin()+b,a.end()};}
poly operator += (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i)add(a[i],b[i]);
	return a;
}
inline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i)sub(a[i],b[i]);
	return a;
}
inline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
ull Omgs[N];
int r[N];
const ull Omg=ksm(3,(mod-1)/max_len);
int getlen(int len){
	int limit=1;while(limit<len)limit<<=1;
	for(int i=0;i<limit;++i)r[i]=(r[i>>1]>>1)|(i&1?limit>>1:0);
	return limit;
}
void setup(){
	_inv_[0]=_inv_[1]=1;for(int i=2;i<N;++i)_inv_[i]=1ULL*_inv_[mod%i]*(mod-mod/i)%mod;
	Omgs[max_len>>1]=1;
	for(int i=(max_len>>1)+1;i<max_len;++i)Omgs[i]=Omgs[i-1]*Omg%mod;
	for(int i=(max_len>>1)-1;i>0;--i)Omgs[i]=Omgs[i<<1];
}
void dft(ull *A,int limit){
	for(int i=0;i<limit;++i)if(i<r[i])std::swap(A[i],A[r[i]]);
	for(int len=1;len<limit;len<<=1){
		for(int i=0;i<limit;++i)A[i]%=mod;
		for(int i=0;i<limit;i+=len<<1){
			ull *p=A+i,*q=A+i+len,*w=Omgs+len;
			for(int _=0;_<len;++_,++p,++q,++w){ull tmp=*q**w%mod;*q=*p+mod-tmp,*p+=tmp;}
		}
	}
	for(int i=0;i<limit;++i)A[i]%=mod;
}
void idft(ull *A,int limit){
	std::reverse(A+1,A+limit),dft(A,limit);
	ull inv=mod-(mod-1)/limit;for(int i=0;i<limit;++i) A[i]=inv*A[i]%mod;
}
ull _f[N],_g[N],_tp[N];
poly operator * (const poly &a,const poly &b){
	uint len=a.size()+b.size()-1;
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size();++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	int limit=getlen(len);
	memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
	dft(_f,limit),dft(_g,limit);
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
void solve(int m,int n) {
	for (int i=0;i<=n+1;i++) s[i]=0;
	for (int j=1;j<=m;j++) add(0,n-j,((ll)G[j]*G[j]-G[j])%mod);
	for (int i=1;i<=n;i++) add(i-m,i-1,((ll)F[i]*F[i]+F[i])%mod);
	
	poly A(m+1),B(n+1);
	for (int j=1;j<=m;j++) A[m-j]=G[j];
	for (int i=1;i<=n;i++) B[i]=F[i];
	A=A*B;
	for (int i=1;i<=n;i++) update(tot[i],mod-2*A[i+m]%mod);
	/*
	for (int j=1;j<=m;j++) for (int i=j;i<=n;i++) {
		update(tot[i-j],mod-(ll)2*G[j]*f[i]%mod);
	}
	*/
	for (int i=1;i<=n;i++) update(s[i],s[i-1]),update(tot[i],s[i]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); setup();
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		read(m);
		for (int i=1;i<=m;i++) read(b[i]);
		
		for (int i=2;i<=n;i++) f[i]=a[i-2]+2*a[i-1]+a[i];
		for (int i=2;i<=m;i++) g[i]=b[i-2]+2*b[i-1]+b[i];
		
		for (int i=0;i<=n;i++) tot[i]=0;
		
		
		if (m>2) {
			for (int j=1;j<=m-2;j++) G[j]=(g[j+2]%mod+mod)%mod;
			for (int i=1;i<=n;i++) F[i]=(f[i]%mod+mod)%mod;
			solve(m-2,n);
		}
		
		bool flag=0;
		for (int i=1;i+m-1<=n;i++) if (tot[i+1]==0&&chk(i)&&solve(b[1]-a[i],b[2]-a[i+1],i+1,i)) {
		//	printf("i=%d\n",i);
			flag=1;
			break;
		}
		if (!flag) puts("-1");
		
	}
	return 0;
}