#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
char ss[N]; 
int pos[N][26],n,q;
vector<int> vec[3];
int f[255][255][255];
int len[3];
void solve (int x)//DP 
{
	if (x==0)
	{
		for (int u=0;u<=len[1];u++)
		for (int i=0;i<=len[2];i++)
		{
			int tmp=n+1;
			if (f[len[0]-1][u][i]<n)	tmp=pos[f[len[0]-1][u][i]+1][vec[0][len[0]]];
			if (u>0&&f[len[0]][u-1][i]<n) tmp=min(tmp,pos[f[len[0]][u-1][i]+1][vec[1][u]]);
			if (i>0&&f[len[0]][u][i-1]<n) tmp=min(tmp,pos[f[len[0]][u][i-1]+1][vec[2][i]]);
			f[len[0]][u][i]=tmp;
		}
	}
	if (x==1)
	{
		for (int u=0;u<=len[0];u++)
		for (int i=0;i<=len[2];i++)
		{
			int tmp=n+1;
			if (f[u][len[1]-1][i]<n) tmp=pos[f[u][len[1]-1][i]+1][vec[1][len[1]]];
			if (u>0&&f[u-1][len[1]][i]<n) tmp=min(tmp,pos[f[u-1][len[1]][i]+1][vec[0][u]]);
			if (i>0&&f[u][len[1]][i-1]<n) tmp=min(tmp,pos[f[u][len[1]][i-1]+1][vec[2][i]]);
			f[u][len[1]][i]=tmp;
		}
	}
	if (x==2)
	{
		for (int u=0;u<=len[0];u++)
		for (int i=0;i<=len[1];i++)
		{
			int tmp=n+1;
			if (f[u][i][len[2]-1]<n) tmp=pos[f[u][i][len[2]-1]+1][vec[2][len[2]]];
			if (u>0&&f[u-1][i][len[2]]<n) tmp=min(tmp,pos[f[u-1][i][len[2]]+1][vec[0][u]]);
			if (i>0&&f[u][i-1][len[2]]<n) tmp=min(tmp,pos[f[u][i-1][len[2]]+1][vec[1][i]]);
			f[u][i][len[2]]=tmp;
		}
	}
	/*for (int u=0;u<=len[0];u++)
	for (int i=0;i<=len[1];i++)
	for (int j=0;j<=len[2];j++)
	printf("%d %d %d %d\n",u,i,j,f[u][i][j]);
	printf("\n");*/
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",ss+1);
	for (int u=0;u<26;u++) pos[n+1][u]=n+1;
	for (int u=n;u>=1;u--)
	{
		for (int i=0;i<26;i++) pos[u][i]=pos[u+1][i];
		pos[u][ss[u]-'a']=u;
	}
	vec[0].push_back(0);vec[1].push_back(0);vec[2].push_back(0);
	while (q--)
	{
		char op[5];
		scanf("%s",op);
		if (op[0]=='-')
		{
			int x;
			scanf("%d",&x);
			x--;
			vec[x].pop_back();
			len[x]--;
		}
		else
		{
			int x;scanf("%d%s",&x,op);
			x--;
			//printf("%d %d %d\n",x,len[x],op[0]-'a');
			vec[x].push_back(op[0]-'a');
			len[x]++;
			solve(x);
		}
		if (f[len[0]][len[1]][len[2]]<=n)  printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}