#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,m,mx[maxn*4];
int a[maxn];
ll tr[maxn*4];
void build(int l,int r,int root) {
	if (l==r) { tr[root]=mx[root]=a[l]; return; }
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	tr[root]=tr[root*2]+tr[root*2+1];
	mx[root]=max(mx[root*2],mx[root*2+1]);
}
void modify(int L,int R,int l,int r,int root,int delta) {
	if (mx[root]<delta) return;
	if (l==r) { tr[root]%=delta; mx[root]%=delta; return; }
	int mid=(l+r)/2;
	if (L<=mid) modify(L,R,l,mid,root*2,delta);
	if (mid<R) modify(L,R,mid+1,r,root*2+1,delta);
	tr[root]=tr[root*2]+tr[root*2+1];
	mx[root]=max(mx[root*2],mx[root*2+1]);
}
void update(int x,int l,int r,int root,int delta) {
	if (l==r) {
		tr[root]=mx[root]=delta;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) update(x,l,mid,root*2,delta);
	else update(x,mid+1,r,root*2+1,delta);
	tr[root]=tr[root*2]+tr[root*2+1];
	mx[root]=max(mx[root*2],mx[root*2+1]);
}
ll query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)/2; ll res=0;
	if (L<=mid) res+=query(L,R,l,mid,root*2);
	if (mid<R) res+=query(L,R,mid+1,r,root*2+1);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	build(1,n,1);
	int op,x,y,z;
	while (m--) {
		read(op); read(x); read(y);
		if (op==1) printf("%lld\n",query(x,y,1,n,1));
		else if (op==2) read(z),modify(x,y,1,n,1,z);
		else update(x,1,n,1,y);
	}
	return 0;
}