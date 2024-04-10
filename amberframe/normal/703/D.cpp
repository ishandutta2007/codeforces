#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1000005;
map<int,int> hash;
int sum[maxn],n,m,s[maxn],a[maxn],ans[maxn];
void insert(int x,int v) {for (int i=x;i<=n;i+=i&-i) sum[i]^=v;}
int query(int x) {int res=0;for (int i=x;i;i-=i&-i) res^=sum[i];return res;}
struct node {
	int l,r,id;
	bool operator<(const node &v) const {
		return l<v.l;
	}
}q[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("sum.in","r",stdin);
		freopen("sum.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		hash[a[i]]=n+1;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++) {
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	for (int p=n,i=m;i>=1;i--) {
		while (p>=q[i].l) {
			insert(p,a[p]);
			insert(hash[a[p]],a[p]);
			hash[a[p]]=p;--p;
		}
		ans[q[i].id]=s[q[i].r]^s[q[i].l-1]^query(q[i].r);
	}
	for (int i=1;i<=m;i++) 
		printf("%d\n",ans[i]);
	return 0;
}