#include <bits/stdc++.h>
using namespace std;
int ans[1000006];
int *a[1000006];
char *s[1000006];
int num[1000006];
map<int,int>mp;
int n,m;
void dfs(int i,int j)
{
	if(i>n||j>m)return;
	if(s[i][j]=='X')return;
	if(a[i][j]==1)return;
	if(i!=n)
	{
		if(a[i+1][j-1]==0)mp[j]--;
	}
	if(j!=m)
	{
		if(a[i-1][j+1]==0)mp[j+1]--;
	}
	a[i][j]=1;
	dfs(i+1,j);
	dfs(i,j+1);
}
void up(int i,int j)
{
	if(a[i][j]==1)return;
	if(i!=n)
	{
		if(a[i+1][j-1]==0)mp[j]--;
	}
	if(j!=m)
	{
		if(a[i-1][j+1]==0)mp[j+1]--;
	}
	a[i][j]=1;
	dfs(i+1,j);
	dfs(i,j+1);
}
void check(int i)
{
	while(mp.size())
	{
		if(mp.begin()->second==0)
		{
			mp.erase(mp.begin());
		}
		else break;
	}
	if(mp.size())
	{
		ans[i]=mp.begin()->first;
	}
	else ans[i]=m+1;//cout<<"<<<<<<"<<i<<" "<<ans[i]<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*(m+3));
		s[i]=(char *)malloc(sizeof(char)*(m+3));
	}
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=0;
	for(int i=0;i<=n;i++)a[i][0]=1;
	for(int j=0;j<=m;j++)a[0][j]=1;
	for(int i=2;i<=m;i++)mp[i]=n-1;
	for(int i=1;i<=n;i++)dfs(i,1);
	for(int i=1;i<=m;i++)dfs(1,i);
	check(1);//cout<<"ok"<<endl;
	for(int i=1;i<=n;i++)up(i,1);
	for(int j=2;j<=m;j++)
	{
		for(int i=1;i<=n;i++)dfs(i,j);
		//cout<<"<<"<<j<<endl;
		//for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)printf("%d%c",a[i][j]," \n"[j==m]);
		//for(auto pr:mp)cout<<"<<<"<<pr.first<<" "<<pr.second<<endl;
		check(j);
		for(int i=1;i<=n;i++)up(i,j);
	}
	//for(int i=1;i<=m;i++)printf("%d%c",ans[i]," \n"[i==m]);
	int q,l,r;
	cin>>q;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(ans[l]<=r)printf("NO\n");
		else printf("YES\n");
	}
    return 0;
}
/*
4 5
.XXXX
X..X.
X.XX.
X.XX.
6
2 2
1 3
3 3
4 5
5 5
1 5
*/