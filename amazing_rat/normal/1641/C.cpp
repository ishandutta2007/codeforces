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
const int INF=1e9;
const int maxn=(2e5)+10;
int n,q,mk[maxn];
map<pair<int,int>,int> M;
set<pair<int,int> > s;
set<pair<int,int> > :: iterator it,it2;
vector<set<pair<int,int> > :: iterator> V;
int tr[maxn];
void ADD(int x,int delta) { for (;x<=n;x+=x&(-x)) tr[x]+=delta; }
int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
void add(int l,int r) { ADD(l,1),ADD(r+1,-1); }
int mn[maxn],mx[maxn];
int OP[maxn],X[maxn],remL[maxn],remR[maxn];
vector<int> g[maxn];
int L[maxn],R[maxn],tim[maxn];
struct node {
	int x,cnt;
	friend node operator + (node A,node B) {
		if (tim[A.x]==tim[B.x]) return (node){A.x,A.cnt+B.cnt};
		if (tim[A.x]<tim[B.x]) return B; return A;
	}
};
int sum[maxn],ans[maxn];
namespace Seg {
int tr[maxn*4],lazy[maxn*4];
node d[maxn*4];
void build() { for (int i=1;i<=n*4;i++) tr[i]=lazy[i]=INF; }
void puttag(int root,int delta) {
	tr[root]=min(tr[root],delta); lazy[root]=min(lazy[root],delta);
}
void pushdown(int root) {
	puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]); lazy[root]=INF;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	tr[root]=min(tr[root<<1],tr[root<<1|1]);
}
void dfs(int l,int r,int root) {
	if (l==r) { tim[l]=tr[root]; d[root]=(node){l,1}; return; }
	int mid=(l+r)>>1; pushdown(root);
	dfs(l,mid,root<<1),dfs(mid+1,r,root<<1|1);
	d[root]=(d[root<<1]+d[root<<1|1]);
}
node query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return d[root];
	int mid=(l+r)>>1;
	if (L<=mid&&mid<R) return query(L,R,l,mid,root<<1)+query(L,R,mid+1,r,root<<1|1);
	if (L<=mid) return query(L,R,l,mid,root<<1);
	return query(L,R,mid+1,r,root<<1|1);
}
};
int MX[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) mn[i]=n+1;
	Seg::build();
	for (int i=1;i<=q;i++) {
		int op,l,r,x;
		read(op); OP[i]=op;
		if (op==0) {
			read(l),read(r),read(x);
			if (!x) {
				add(l,r);
				Seg::add(l,r,1,n,1,i);
				int L=l,R=r;
				it=s.lower_bound(MP(l,-1));
				if (it!=s.begin()) {
					it2=it; it2--; if ((*it2).second>=l-1) it--;
				} V.clear();
				while (it!=s.end()) {
					if ((*it).first>r+1) break;
					L=min(L,(*it).first),R=max(R,(*it).second);
					V.push_back(it); it++;
				}
				for (auto it : V) s.erase(it);
				s.insert(MP(L,R));
				if (mn[L-1]<=R) mk[L-1]=1;
				if (mx[R+1]>=L) mk[R+1]=1;
			} else {
				if (l==r) mk[l]=1;
				else {
					L[i]=l,R[i]=r;
					mn[l]=min(mn[l],r),mx[r]=max(mx[r],l);
					it=s.lower_bound(MP(l+1,-1));
					if (it!=s.end()&&(*it).first==l+1&&(*it).second>=r) mk[l]=1;
					it=s.lower_bound(MP(r,-1));
					if (it!=s.begin()) {
						it--; if ((*it).second==r-1&&(*it).first<=l) mk[r]=1;
					}
				}
			}
		} else {
			read(x); X[i]=x;
			if (mk[x]) ans[i]=1;
			else if (query(x)) ans[i]=0;//,printf("i=%d\n",i);
			else {
				ans[i]=-1;
				it=s.lower_bound(MP(x,-1));
				if (it!=s.end()&&(*it).first==x+1&&it!=s.begin()) {
					it2=it; it2--;
					if ((*it2).second==x-1) {
						ans[i]=-2;
						remL[i]=(*it2).first,remR[i]=(*it).second;
						g[x].push_back(i);
					}
				}
			}
		}
	}
	Seg::dfs(1,n,1);
	//printf("> %d %d\n",remL[8],remR[8]);
	for (int x=1;x<=n;x++) { sum[x]=sum[x-1]; if (!query(x)) sum[x]++; MX[x]=q+1; }
	for (int i=1;i<=q;i++) if (OP[i]==0&&L[i]) {
		if (sum[R[i]]-sum[L[i]-1]>1) continue;
		node tmp=Seg::query(L[i],R[i],1,n,1);
		if (tmp.cnt>1) continue;
		int x=tmp.x;
		//printf("%d %d %d\n",L[i],R[i],x);
		int l=lower_bound(g[x].begin(),g[x].end(),i)-g[x].begin();
		int r=(int)g[x].size()-1,mid,res=-1;
		//printf("l=%d\n",l);
		while (l<=r) {
			mid=(l+r)>>1;
			if (L[i]>=remL[g[x][mid]]&&R[i]<=remR[g[x][mid]]) res=mid,r=mid-1;
			else l=mid+1;
		}
		if (res!=-1) MX[x]=min(MX[x],res);
	}
	for (int i=1;i<=q;i++) if (OP[i]==1&&ans[i]==-2) {
		int x=X[i];
		if (MX[x]<=i) ans[i]=1; else ans[i]=-1;
	}
	for (int i=1;i<=q;i++) if (OP[i]==1) {
		if (ans[i]==-1) puts("N/A");
		else if (ans[i]) puts("YES");
		else puts("NO");
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