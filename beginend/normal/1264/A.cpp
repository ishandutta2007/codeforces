#include<bits/stdc++.h>

const int N=400005;

int n,a[N],pos[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int tot=0;
		for (int i=1;i<=n/2;i++)
			if (a[i]>a[i+1]) pos[++tot]=i;
		int r=2,ans=0;
		for (int i=2;i<tot;i++)
			if (std::min(pos[tot]-pos[i],pos[i]-pos[1])>pos[1]) {ans=pos[i];break;}
		if (!ans) printf("%d %d %d\n",0,0,0);
		else printf("%d %d %d\n",pos[1],ans-pos[1],pos[tot]-ans);
	}
	return 0;
}