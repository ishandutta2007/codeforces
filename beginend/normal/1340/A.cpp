#include<bits/stdc++.h>

const int N=100005;

int n,a[N],pos[N];

bool check()
{
	int mx=n+1,i=1;
	while (i<=n)
	{
		int j=i;
		while (j<n&&pos[j+1]==pos[j]+1) j++;
		if (pos[j]+1!=mx) return 0;
		mx=pos[i];
		i=j+1;
	}
	return 1;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
		if (check()) puts("Yes");
		else puts("No");
	}
	return 0;
}