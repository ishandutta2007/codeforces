#include<bits/stdc++.h>

typedef long long LL;

const int N=1005;

int n,a1[N],a2[N],s1,s2,id[N],ans[N];
LL area[N];

bool cmp(int x,int y)
{
	return area[x]<area[y];
}

LL ask(int op,int x,int y,int z)
{
	printf("%d %d %d %d\n",op,x,y,z);
	fflush(stdout);
	LL ans;
	scanf("%lld",&ans);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=3;i<=n;i++)
		if (ask(2,1,2,i)==1) a1[++s1]=i;
		else a2[++s2]=i;
	ans[1]=1;ans[s2+2]=2;
	for (int i=1;i<=s1;i++) area[i]=ask(1,1,2,a1[i]),id[i]=i;
	std::sort(id+1,id+s1+1,cmp);
	int l=s2+3,r=n;
	for (int i=1;i<s1;i++)
		if (ask(2,1,a1[id[s1]],a1[id[i]])==1) ans[r--]=a1[id[i]];
		else ans[l++]=a1[id[i]];
	if (s1) ans[r--]=a1[id[s1]];
	for (int i=1;i<=s2;i++) area[i]=ask(1,1,2,a2[i]),id[i]=i;
	std::sort(id+1,id+s2+1,cmp);
	l=2,r=s2+1;
	for (int i=1;i<s2;i++)
		if (ask(2,1,a2[id[s2]],a2[id[i]])==1) ans[r--]=a2[id[i]];
		else ans[l++]=a2[id[i]];
	if (s2) ans[r--]=a2[id[s2]];
	printf("%d ",0);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}