#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=5005;

int n,q,lef[N],rig[N],a[N],s1[N],s2[N];

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&lef[i],&rig[i]);
		a[lef[i]]++;a[rig[i]+1]--;
	}
	int w=0;
	for (int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
		s1[i]=s1[i-1];
		s2[i]=s2[i-1];
		if (a[i]==1) s1[i]++;
		else if (a[i]==2) s2[i]++;
		if (a[i]) w++;
	}
	int mx=0;
	for (int i=1;i<q;i++)
		for (int j=i+1;j<=q;j++)
		{
			int v=w-s1[rig[i]]+s1[lef[i]-1]-s1[rig[j]]+s1[lef[j]-1];
			int p=std::max(lef[i],lef[j]),q=std::min(rig[i],rig[j]);
			if (p<=q) v-=s2[q]-s2[p-1];
			mx=std::max(mx,v);
		}
	printf("%d\n",mx);
	return 0;
}