#include<bits/stdc++.h>

const int N=200005;

int n,m,s[N*4],t[N*4],w[N*2];
struct data{int l,r;}a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		m=0;
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r),w[++m]=a[i].l,w[++m]=a[i].r;
		std::sort(w+1,w+m+1);
		m=std::unique(w+1,w+m+1)-w-1;
		for (int i=0;i<=m*2+1;i++) s[i]=t[i]=0;
		for (int i=1;i<=n;i++)
		{
			a[i].l=std::lower_bound(w+1,w+m+1,a[i].l)-w;
			a[i].r=std::lower_bound(w+1,w+m+1,a[i].r)-w;
			a[i].l*=2;a[i].r*=2;
			s[a[i].l]++;s[a[i].r+1]--;
		}
		m=m*2+1;
		for (int i=1;i<=m;i++) s[i]+=s[i-1];
		int sc=0;
		for (int i=1;i<=m;i++)
		{
			if (s[i]==1&&s[i-1]!=1) t[i]=t[i-1]+1;
			else t[i]=t[i-1];
			if (!s[i]&&(s[i-1]||i==1)) sc++;
		}
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int w2=t[a[i].r]-t[a[i].l-1]+sc;
			if (s[a[i].r]==1&&!s[a[i].r+1]) w2--;
			if (s[a[i].l]==1&&!s[a[i].l-1]) w2--;
			ans=std::max(ans,w2-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}