#include<bits/stdc++.h>

const int N=1000005;

int n,a[N];
char str[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	int cnt=0,ans=0;
	for (int i=1;i<=n;i++)
		if (str[i]=='(') a[i]=1,cnt++;
		else cnt--,a[i]=-1;
	if (cnt)
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (str[i]=='(')
		{
			int j=i,s=1;
			while (j<n&&s+a[j+1]>=0) j++,s+=a[j];
			i=j;
		}
		else
		{
			int j=i,s=-1;
			while (j<n&&s+a[j+1]<0) j++,s+=a[j];
			ans+=j-i+2;
			i=j+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}