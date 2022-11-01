#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n,a[N],b[N],a1[N],a2[N],a3[N],t[N],u[N],v[N];

bool cmp1(int x,int y) {return a[x]<a[y];}
bool cmp2(int x,int y) {return b[x]<b[y];}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),u[i]=i;
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),v[i]=i;
	std::sort(u+1,u+n+1,cmp1);
	std::sort(v+1,v+n+1,cmp2);
	LL k=0;
	for (int i=1;i<=n;i++)
	{
		t[i]=b[v[i]]-a[u[i]];k+=t[i];
		if (k<0) {puts("NO");return 0;}
	}
	if (k!=0) {puts("NO");return 0;}
	puts("YES");
	int p=1,q=1;
	while (t[p]<=0&&p<=n) p++;
	while (t[q]>=0&&q<=n) q++;
	int tot=0;
	while (p<=n)
	{
		int d=std::min(t[p],-t[q]);
		t[p]-=d;t[q]+=d;
		tot++;
		a1[tot]=u[p];a2[tot]=u[q];a3[tot]=d;
		while (t[p]<=0&&p<=n) p++;
		while (t[q]>=0&&q<=n) q++;
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d %d %d\n",a1[i],a2[i],a3[i]);
	return 0;
}