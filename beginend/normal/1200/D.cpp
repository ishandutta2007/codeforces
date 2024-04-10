#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=2005;

int n,k,a[N][N],s[N][N];
char str[N];

void ins(int x1,int y1,int x2,int y2)
{
	x2=std::min(x2,n);y2=std::min(y2,n);
	s[x1][y1]++;s[x1][y2+1]--;s[x2+1][y1]--;s[x2+1][y2+1]++;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for (int j=1;j<=n;j++) a[i][j]=(str[j]=='W'?0:1);
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		int mn=n+1,mx=0;
		for (int j=1;j<=n;j++)
			if (a[i][j]) mn=std::min(mn,j),mx=std::max(mx,j);
		if (!mx) {cnt++;continue;}
		if (mx-mn+1>k) continue;
		ins(i,mx,i+k-1,mn+k-1);
	}
	for (int j=1;j<=n;j++)
	{
		int mn=n+1,mx=0;
		for (int i=1;i<=n;i++)
			if (a[i][j]) mn=std::min(mn,i),mx=std::max(mx,i);
		if (!mx) {cnt++;continue;}
		if (mx-mn+1>k) continue;
		ins(mx,j,mn+k-1,j+k-1);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	int mx=0;
	for (int i=k;i<=n;i++)
		for (int j=k;j<=n;j++)
			mx=std::max(mx,s[i][j]);
	printf("%d\n",mx+cnt);
	return 0;
}