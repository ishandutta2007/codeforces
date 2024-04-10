#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxm=(1e6)+10;
const int maxn=(3e5)+10;
const int N=(1e6);
int n,m,q,a[maxn],b[maxn];
int tr[maxm*4],lazy[maxm*4];
void pushdown(int root) {
	if (!lazy[root]) return;
	tr[root*2]+=lazy[root];
	tr[root*2+1]+=lazy[root];
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void update(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) {
		tr[root]+=delta;
		lazy[root]+=delta;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) update(L,R,l,mid,root*2,delta);
	if (mid<R) update(L,R,mid+1,r,root*2+1,delta);
	tr[root]=max(tr[root*2],tr[root*2+1]);
}
int query(int l,int r,int root) {
	if (l==r) return l;
	pushdown(root);
	int mid=(l+r)/2;
	if (tr[root*2+1]>0) return query(mid+1,r,root*2+1);
	return query(l,mid,root*2);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		update(1,a[i],1,N,1,1);
	}
	for (int i=1;i<=m;i++) {
		read(b[i]);
		update(1,b[i],1,N,1,-1);
	}
	read(q);
	int op,x,y;
	while (q--) {
		read(op); read(x); read(y);
		if (op==1) {
			update(1,a[x],1,N,1,-1);
			a[x]=y;
			update(1,a[x],1,N,1,1);
		} else {
			update(1,b[x],1,N,1,1);
			b[x]=y;
			update(1,b[x],1,N,1,-1);
		}
		if (tr[1]<=0) printf("-1\n");
		else printf("%d\n",query(1,N,1));
	}
	return 0;
}