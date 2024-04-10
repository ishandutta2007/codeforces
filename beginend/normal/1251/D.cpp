#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;
const int inf=1e9;

int n,lef[N],rig[N],sz,idl[N];
LL s;

bool cmpl(int x,int y)
{
	return lef[x]<lef[y];
}

bool check(int p)
{
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (lef[idl[mid]]<p) l=mid+1;
		else r=mid-1;
	}
	int ned=l-1-n/2;LL cs=(LL)p*ned;
	for (int i=n;i>=1;i--)
		if (rig[idl[i]]>=p&&lef[idl[i]]<p&&ned) cs-=lef[idl[i]],ned--;
	if (ned) return 0;
	else return cs<=s;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		sz=0;
		scanf("%d%lld",&n,&s);
		for (int i=1;i<=n;i++) scanf("%d%d",&lef[i],&rig[i]),idl[i]=i,s-=lef[i];
		std::sort(idl+1,idl+n+1,cmpl);
		int pos=(n+1)/2,l=lef[idl[pos]]+1,r=inf;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",l-1);
	}
	return 0;
}