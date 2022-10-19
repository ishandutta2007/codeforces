#include<bits/stdc++.h>
using namespace std;
int gs[100005],f[200005];
char s[10005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		gs[a]++;
	}
	int q;
	cin>>q;
	for(int i=1;i<=100000;i++)f[min(gs[i],8)]++;
	for(int i=1;i<=q;i++)
	{
		scanf("%s",s+1);
		int a;
		scanf("%d",&a);
		f[min(gs[a],8)]--;
		if(s[1]=='+')gs[a]++;
		else gs[a]--;
		f[min(gs[a],8)]++;
		if(f[8])
		{
			puts("YES");
			continue;
		}
		if(f[6]+f[7]>1)
		{
			puts("YES");
			continue;
		}
		if(f[6]+f[7])
		{
			if(f[2]+f[3]+f[4]+f[5])
			{
				puts("YES");
				continue;
			}
			puts("NO");
			continue;
		}
		if(f[4]+f[5])
		{
			if(f[4]+f[5]>1)
			{
				puts("YES");
				continue;
			}
			if(f[2]+f[3]>1)puts("YES");
			else puts("NO");
			continue;
		}
		puts("NO");
	}
	return 0;
}