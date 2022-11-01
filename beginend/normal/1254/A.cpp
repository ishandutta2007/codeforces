#include<bits/stdc++.h>

char lab[70],ma[105][105],str[105];
int n,m,k;

void work(int id,int cnt)
{
	for (int i=1;i<=n&&cnt;i++)
		if (i&1)
		{
			for (int j=1;j<=m&&cnt;j++)
				if (ma[i][j]=='.') ma[i][j]=lab[id];
				else if (ma[i][j]=='!') cnt--,ma[i][j]=lab[id];
		}
		else
		{
			for (int j=m;j>=1&&cnt;j--)
				if (ma[i][j]=='.') ma[i][j]=lab[id];
				else if (ma[i][j]=='!') cnt--,ma[i][j]=lab[id];
		}
}

int main()
{
	for (int i=1;i<=26;i++) lab[i]='a'+i-1;
	for (int i=26+1;i<=52;i++) lab[i]='A'+i-27;
	for (int i=53;i<=62;i++) lab[i]='0'+i-53;
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",ma[i]+1);
			for (int j=1;j<=m;j++)
				if (ma[i][j]=='R') cnt++,ma[i][j]='!';
		}
		for (int i=1;i<=cnt%k;i++) work(i,cnt/k+1);
		for (int i=cnt%k+1;i<=k;i++) work(i,cnt/k);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++) putchar(ma[i][j]=='.'?lab[k]:ma[i][j]);
			puts("");
		}
	}
	return 0;
}