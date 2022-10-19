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
const ll INF=9e18;
const int maxn=(2e5)+10;
int T,n,fa[maxn];
ll a[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
struct node {
	ll mn; int pos;
	friend bool operator == (node A,node B) {
		return A.mn==B.mn&&A.pos==B.pos;
	}
} d[maxn],m1,m2,tmp,mx1,mx2,e[maxn],tmp2;
ll solve() {
	ll ans=0,k=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	int cnt=n;
	while (cnt>1) {
		for (int i=1;i<=n;i++) d[i].mn=INF;
		for (int i=1;i<=n;i++) {
			int x=find(i);
			if (a[i]<d[x].mn) d[x].mn=a[i],d[x].pos=i;
		}
		m1.mn=m2.mn=INF;
		m1.pos=m2.pos=0;
		for (int i=1;i<=n;i++) if (find(i)==i) {
			if (d[i].mn<m1.mn) m2=m1,m1=d[i];
			else if (d[i].mn<m2.mn) m2=d[i];
		}
		for (int i=1;i<=n;i++) {
			int x=find(i);
			if (d[x]==m1) tmp=m2; else tmp=m1;
			int j=tmp.pos;
			if (find(j)!=find(i)) {
				ans+=a[j]*a[i];
				k+=a[j]+a[i];
			//	printf("merge %d %d %lld %lld\n",i,j,ans,k);
				cnt--;
				fa[find(j)]=find(i);
			}
		}
	}
	if (k>0) return INF;
	return 0;
}
__int128 solve1(ll t,int flag=0) {
	for (int i=1;i<=n;i++) a[i]+=t;
	__int128 ans=0,ans2=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	int cnt=n;
	while (cnt>1) {
		for (int i=1;i<=n;i++) d[i].mn=INF,e[i].mn=-INF;
		for (int i=1;i<=n;i++) {
			int x=find(i);
			if (a[i]<d[x].mn) d[x].mn=a[i],d[x].pos=i;
			if (a[i]>e[x].mn) e[x].mn=a[i],e[x].pos=i;
		}
		m1.mn=m2.mn=INF;
		mx1.mn=mx2.mn=-INF;
		m1.pos=m2.pos=0;
		mx1.pos=mx2.pos=0;
		for (int i=1;i<=n;i++) if (find(i)==i) {
			if (d[i].mn<m1.mn) m2=m1,m1=d[i];
			else if (d[i].mn<m2.mn) m2=d[i];
			if (e[i].mn>mx1.mn) mx2=mx1,mx1=e[i];
			else if (e[i].mn>mx2.mn) mx2=e[i];
		}
		int X,Y;
		for (int x=1;x<=n;x++) if (find(x)==x) {
			int i=d[x].pos;
			if (d[x]==m1) tmp=m2; else tmp=m1;
			if (e[x]==mx1) tmp2=mx2; else tmp2=mx1;
			if (a[i]>0) {
				if (tmp.mn>tmp2.mn) swap(tmp,tmp2);
			} else if (tmp.mn<tmp2.mn) swap(tmp,tmp2);
			int j=tmp.pos; X=-1,Y=-1; __int128 now;
			if (find(j)!=find(i)) now=(a[j]-t)*(a[i]-t)+t*(a[i]+a[j]-t*2),X=i,Y=j;
			i=e[x].pos;
			if (d[x]==m1) tmp=m2; else tmp=m1;
			if (e[x]==mx1) tmp2=mx2; else tmp2=mx1;
			if (a[i]>0) {
				if (tmp.mn>tmp2.mn) swap(tmp,tmp2);
			} else if (tmp.mn<tmp2.mn) swap(tmp,tmp2);
			j=tmp.pos;
			if (find(j)!=find(i)) {
				ll T=(a[j]-t)*(a[i]-t)+t*(a[i]+a[j]-t*2);
				if (X==-1||T<now) now=T,X=i,Y=j;
			}
			if (X!=-1) {
				ans+=now;
			//	printf("%lld\n",x*y+t*(x+y));
			//	printf("merge %d %d %lld\n",X,Y,ans);
				cnt--;
				ans2+=a[X]+a[Y]-t*2;
				fa[find(X)]=find(Y);
			}
		}
	}
	for (int i=1;i<=n;i++) a[i]-=t;
	if (flag) return ans2;
	return ans;
}
ll calc() {
	ll l=1,r=1e13,mid,res=0;
	while (l<=r) {
		mid=(l+r)>>1;
		if (solve1(mid)>=solve1(mid-1)) res=mid,l=mid+1;
		else r=mid-1;
	}
	return solve1(res);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		ll ans=solve();
		if (ans!=INF) {
			for (int i=1;i<=n;i++) a[i]*=-1;
			ans=max(ans,solve());
			for (int i=1;i<=n;i++) a[i]*=-1;
		}
		if (ans==INF) puts("INF");
		else {
			if (solve1(0,1)<0) {
				for (int i=1;i<=n;i++) a[i]*=-1;
			}
			ans=calc();
			//for (int i=1;i<=n;i++) a[i]*=-1;
			//ans=max(ans,calc());
			writeln(ans);
		}
	}
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