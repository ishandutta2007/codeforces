#include<bits/stdc++.h>
using namespace std;
int t,n,a[100];
char s[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		for (int i=0;i<=25;++i)
			a[i]=0;
		for (int i=0;i<n;++i)
			++a[s[i]-'a'];
		int ts=0,mx=0,mn=n;
		for (int i=0;i<=25;++i)
		{
			if (a[i]>=(n+1)/2)
				ts=i;
			mx=max(mx,a[i]);
			if (a[i]!=0)
				mn=min(mn,a[i]);
		}
		if (mn==1)
		{
			for (int i=0;i<=25;++i)
				if (a[i]==1)
				{
					putchar(i+'a');
					--a[i];
					break;
				}
			for (int i=0;i<=25;++i)
				for (int j=1;j<=a[i];++j)
					putchar(i+'a');
			putchar('\n');
			continue;
		}
		if (mx==n)
		{
			for (int i=1;i<=n;++i)
				putchar(ts+'a');
			putchar('\n');
			continue;
		}
		for (int i=0;i<=25;++i)
			if (a[i])
			{
				if (a[i]>n/2+1)
				{
					int nx=-1;
					for (int j=i+1;j<=25;++j)
						if (a[j])
						{
							nx=j;
							break;
						}
					int nnx=-1;
					for (int j=nx+1;j<=25;++j)
						if (a[j])
						{
							nnx=j;
							break;
						}
					if (nnx==-1)
					{
						putchar(i+'a');
						for (int j=1;j<=a[nx];++j)
							putchar(nx+'a');
						for (int j=2;j<=a[i];++j)
							putchar(i+'a');
						putchar('\n');
					}
					else
					{
						putchar(i+'a');
						putchar(nx+'a');
						--a[nx];
						for (int j=2;j<=a[i];++j)
							putchar(i+'a');
						putchar(nnx+'a');
						--a[nnx];
						for (int j=i+1;j<=25;++j)
							for (int k=1;k<=a[j];++k)
								putchar(j+'a');
						putchar('\n');
					}
				}
				else
				{
					putchar(i+'a');
					putchar(i+'a');
					a[i]-=2;
					for (int j=i+1;j<=25;++j)
						for (int k=1;k<=a[j];++k)
						{
							putchar(j+'a');
							if (a[i])
							{
								putchar(i+'a');
								--a[i];
							}
						}
					putchar('\n');
				}
				break;
			}
	}	
	return 0;
}