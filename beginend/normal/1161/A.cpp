#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,m,a[N],cnt[N];
bool fir[N];

int main()
{
	scanf("%d%d",&n,&m);
	int tot=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if (!cnt[a[i]]) fir[i]=1,tot++;
		cnt[a[i]]++;
	}
	int ans=0;
	ans+=2*((!cnt[1])+(!cnt[n]));
	ans+=3*((n-tot)-(!cnt[1])-(!cnt[n]));
	for (int i=1;i<=m;i++)
	{
		if (fir[i])
		{
			if (a[i]<n&&!cnt[a[i]+1]) ans++;
			if (a[i]>1&&!cnt[a[i]-1]) ans++;
		}
		cnt[a[i]]--;
	}
	printf("%d\n",ans);
	return 0;
}