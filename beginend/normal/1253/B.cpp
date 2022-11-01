#include<bits/stdc++.h>

const int N=1000005;

int n,a[N],t[N],pos[N],now[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int s=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>0)
		{
			if (t[a[i]]||now[a[i]]==ans+1) {puts("-1");return 0;}
			t[a[i]]++;
			now[a[i]]=ans+1;
			s++;
		}
		else
		{
			if (!t[-a[i]]) {puts("-1");return 0;}
			t[-a[i]]--;
			s--;
		}
		if (!s) pos[++ans]=i;
	}
	if (s) puts("-1");
	else
	{
		printf("%d\n",ans);
		for (int i=1;i<=ans;i++) printf("%d ",pos[i]-pos[i-1]);
	}
	return 0;
}