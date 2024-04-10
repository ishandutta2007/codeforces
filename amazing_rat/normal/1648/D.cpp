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
const ll INF=1e18;
const int maxn=(5e5)+10;
int n,m,lg[maxn];
ll a[maxn],b[maxn],c[maxn];
ll s1[maxn][21],s2[maxn][21],ans=-INF;
namespace Seg {
	ll tr[maxn*4];
	void build() { for (int i=1;i<=n*4;i++) tr[i]=-INF; }
	void add(int x,int l,int r,int root,ll delta) {
		tr[root]=max(tr[root],delta);
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta);
		else add(x,mid+1,r,root<<1|1,delta);
	}
	ll query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1; ll res=-INF;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=max(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
};
ll premx,res;
namespace Seg2 {
	ll m1[maxn*4],m2[maxn*4],tr[maxn*4];
	void build(int l,int r,int root) {
		if (l==r) { m1[root]=s1[l][0],m2[root]=s2[l][0],tr[root]=m1[root]+m2[root]; return; }
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		m1[root]=max(m1[root<<1],m1[root<<1|1]);
		m2[root]=max(m2[root<<1],m2[root<<1|1]);
		tr[root]=max(max(tr[root<<1],tr[root<<1|1]),m1[root<<1]+m2[root<<1|1]);
	}
	void query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) {
			res=max(res,tr[root]);
			res=max(res,premx+m2[root]);
			premx=max(premx,m1[root]);
			return;
		}
		int mid=(l+r)>>1;
		if (L<=mid) query(L,R,l,mid,root<<1);
		if (mid<R) query(L,R,mid+1,r,root<<1|1);
	}
};
namespace Seg3 {
	ll m1[maxn*4],m2[maxn*4],tr[maxn*4];
	void build() { for (int i=1;i<=n*4;i++) m1[i]=m2[i]=tr[i]=-INF; }
	void add(int x,int l,int r,int root,ll delta,int op) {
		if (l==r) {
			if (op==1) m1[root]=max(m1[root],delta);
			else m2[root]=max(m2[root],delta);
			tr[root]=m1[root]+m2[root];
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta,op);
		else add(x,mid+1,r,root<<1|1,delta,op);
		m1[root]=max(m1[root<<1],m1[root<<1|1]);
		m2[root]=max(m2[root<<1],m2[root<<1|1]);
		tr[root]=max(max(tr[root<<1],tr[root<<1|1]),m1[root<<1]+m2[root<<1|1]);
	}
	void query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) {
			res=max(res,tr[root]);
			res=max(res,premx+m2[root]);
			premx=max(premx,m1[root]);
			return;
		}
		int mid=(l+r)>>1;
		if (L<=mid) query(L,R,l,mid,root<<1);
		if (mid<R) query(L,R,mid+1,r,root<<1|1);
	}
};
namespace Seg4 {
	ll m1[maxn*4],m2[maxn*4],tr[maxn*4];
	void build() { for (int i=1;i<=n*4;i++) m1[i]=m2[i]=tr[i]=-INF; }
	void add(int x,int l,int r,int root,ll delta,int op) {
		if (l==r) {
			if (op==1) m1[root]=max(m1[root],delta);
			else m2[root]=max(m2[root],delta);
			tr[root]=m1[root]+m2[root];
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta,op);
		else add(x,mid+1,r,root<<1|1,delta,op);
		m1[root]=max(m1[root<<1],m1[root<<1|1]);
		m2[root]=max(m2[root<<1],m2[root<<1|1]);
		tr[root]=max(max(tr[root<<1],tr[root<<1|1]),m1[root<<1]+m2[root<<1|1]);
	}
	void query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) {
			res=max(res,tr[root]);
			res=max(res,premx+m2[root]);
			premx=max(premx,m1[root]);
			return;
		}
		int mid=(l+r)>>1;
		if (L<=mid) query(L,R,l,mid,root<<1);
		if (mid<R) query(L,R,mid+1,r,root<<1|1);
	}
};
struct node { int l,r,w; } d[maxn];
bool cmp(node A,node B) { return (A.l==B.l?A.r<B.r:A.l<B.l); }
ll query1(int l,int r) {
	int j=lg[r-l+1];
	return max(s1[l][j],s1[r-(1<<j)+1][j]);
}
ll query2(int l,int r) {
	int j=lg[r-l+1];
	return max(s2[l][j],s2[r-(1<<j)+1][j]);
}
ll dp[maxn];
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
	for (int i=1;i<=n;i++) read(b[i]),b[i]+=b[i-1];
	for (int i=1;i<=n;i++) read(c[i]),c[i]+=c[i-1];
	Seg::build();
	for (int i=1;i<=m;i++) read(d[i].l),read(d[i].r),read(d[i].w);
	sort(d+1,d+m+1,cmp);
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;i++) s1[i][0]=-b[i-1]+a[i],s2[i][0]=b[i]-c[i-1];
	for (int i=1;i<=20;i++) for (int j=1;j+(1<<i)-1<=n;j++)
		s1[j][i]=max(s1[j][i-1],s1[j+(1<<(i-1))][i-1]),
		s2[j][i]=max(s2[j][i-1],s2[j+(1<<(i-1))][i-1]);
	Seg2::build(1,n,1);
	/*for (int i=1;i<=m;i++) printf("i=%d, %d %d %d\n",i,d[i].l,d[i].r,d[i].w);
	for (int i=1;i<=n;i++) printf("%lld ",a[i]); puts("");
	for (int i=1;i<=n;i++) printf("%lld ",b[i]); puts("");
	for (int i=1;i<=n;i++) printf("%lld ",c[i]); puts("");
	for (int i=1;i<=n;i++) printf("%lld ",s2[i][0]); puts("");
	for (int i=1;i<=n+1;i++) mx[i]=-INF;*/
	
	Seg3::build(); Seg4::build();
	for (int i=1;i<=m;i++) {
		ll tmp=query1(d[i].l,d[i].r)-d[i].w;
		Seg3::add(d[i].r,1,n,1,tmp,1);
		Seg4::add(d[i].r,1,n,1,tmp,1);
		//printf("%lld %lld\n",d[i].r,tmp);
	}
	//11 + 
	for (int i=1;i<=n;i++) Seg4::add(i,1,n,1,s2[i][0],2);
	
	for (int i=m;i>=1;i--) {
		premx=-INF,res=-INF;
		Seg3::query(max(1,d[i].l-1),min(d[i].r+1,n),1,n,1);
		ans=max(ans,res-d[i].w);
		
		//if (i==11) printf("%d %lld %lld\n",i,ans,res);
		premx=-INF,res=-INF;
		Seg4::query(max(1,d[i].l-1),d[i].r,1,n,1);
		ans=max(ans,res-d[i].w);
	//	if (i==11) printf("?%lld\n",res-d[i].w);
		
		dp[i]=Seg::query(d[i].l,min(d[i].r+1,n),1,n,1);
		dp[i]=max(dp[i],query2(d[i].l,d[i].r));
		Seg::add(d[i].l,1,n,1,dp[i]-d[i].w);
		
		//printf("> l=%d,dp=%lld\n",d[i].l,dp[i]-d[i].w);
		
		Seg3::add(d[i].l,1,n,1,dp[i]-d[i].w,2);
		
		//if (i>=6) printf("%d %lld %lld\n",i,dp[i][0],ans+c[n]);
		
		premx=-INF;
		res=-INF;
		Seg2::query(d[i].l,d[i].r,1,n,1);
		ans=max(ans,res-d[i].w);
		
	}
	printf("%lld\n",ans+c[n]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/