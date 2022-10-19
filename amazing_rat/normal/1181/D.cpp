#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=500010;
int n,m,q,a[maxn],mx;
vector<int> g[maxn];
ll s[maxn];
int rt[maxn],tr[maxn*30],tot;
int ls[maxn*30],rs[maxn*30];
void add(int x,int l,int r,int &root) {
	tot++;
	ls[tot]=ls[root];
	rs[tot]=rs[root];
	tr[tot]=tr[root]+1;
	root=tot;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(x,l,mid,ls[root]);
	else add(x,mid+1,r,rs[root]);
}
int query(int x,int l,int r,int root) {
	if (l==r) return l;
	int mid=(l+r)/2;
	if (tr[ls[root]]>=x) return query(x,l,mid,ls[root]);
	return query(x-tr[ls[root]],mid+1,r,rs[root]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(m); read(n); read(q);
	int x; ll k,tmp;
	int l,r,mid,res;
	for (int i=1;i<=m;i++) {
		read(x); a[x]++;
	}
	for (int i=1;i<=n;i++) {
		g[a[i]].push_back(i);
		mx=max(mx,a[i]);
	}
	tmp=0;
	for (int i=0;i<=mx;i++) {
		if (i) s[i]=s[i-1]+tmp; tmp+=g[i].size();
		if (i) rt[i]=rt[i-1];
		for (int j=0;j<g[i].size();j++)
			add(g[i][j],1,n,rt[i]);
	}
	//for (int i=0;i<=mx;i++) printf("%lld ",s[i]); printf("\n");
	while (q--) {
		read(k); k-=m;
		if (k>s[mx]) {
			k-=s[mx];
			if (k%n==0) printf("%d\n",n);
			else printf("%lld\n",k%n);
		} else {
			l=0,r=mx;
			while (l<=r) {
				mid=(l+r)/2;
				if (s[mid]>=k) res=mid,r=mid-1;
				else l=mid+1;
			}
			res--;
			//printf(" %d %lld\n",res,k-s[res]);
			printf("%d\n",query(k-s[res],1,n,rt[res]));
		}
	}
	return 0;
}