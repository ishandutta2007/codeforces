#include<bits/stdc++.h>
using namespace std;
struct Node{
	int type;
	int a,b;
	int _0,_1;
	int real;
}p[1010101];
/*
type
1 IN
2 AND
3 OR
4 XOR
5 NOT
*/

vector<int> f[1010101];

int cnt=0;
int get_new()
{
	cnt++;
	return cnt;
}

int merge(int x,int y)
{
	if(f[x].size()<f[y].size())
		swap(x,y);
	for(int i=0;i<f[y].size();i++)
		f[x].push_back(f[y][i]); 
	return x;
} 

void dfs(int x)
{
	int a=p[x].a,b=p[x].b;
	if(p[x].type==1)
	{
		if(p[x].a==0)
		{
			p[x]._0=0;
			p[x]._1=get_new();
			f[p[x]._1].push_back(b);
			p[x].real=0;
		}
		else
		{
			p[x]._1=0;
			p[x]._0=get_new();
			f[p[x]._0].push_back(b);
			p[x].real=1;
		}
		return;
	}
	dfs(a);
	if(p[x].type!=5)
		dfs(b); 
	if(p[x].type==2)
	{
		p[x].real=p[a].real&p[b].real;
		p[x]._0=merge(p[a]._0,p[b]._0);
		if(p[a].real==0)
			p[x]._0=merge(p[x]._0,p[b]._1);
		else
			p[x]._1=merge(p[x]._1,p[b]._1);
		if(p[b].real==0)
			p[x]._0=merge(p[x]._0,p[a]._1);
		else
			p[x]._1=merge(p[x]._1,p[a]._1);
		return;
	}
	if(p[x].type==3)
	{
		p[x].real=p[a].real|p[b].real;
		p[x]._1=merge(p[a]._1,p[b]._1);
		if(p[a].real==1)
			p[x]._1=merge(p[x]._1,p[b]._0);
		else
			p[x]._0=merge(p[x]._0,p[b]._0);
		if(p[b].real==1)
			p[x]._1=merge(p[x]._1,p[a]._0);
		else
			p[x]._0=merge(p[x]._0,p[a]._0);
		return;
	}
	if(p[x].type==4)
	{
		p[x].real=p[a].real^p[b].real;
		if(p[a].real==1)
		{
			p[x]._0=merge(p[x]._0,p[b]._1);
			p[x]._1=merge(p[x]._1,p[b]._0);
		}
		else
		{
			p[x]._0=merge(p[x]._0,p[b]._0);
			p[x]._1=merge(p[x]._1,p[b]._1);
		}
		if(p[b].real==1)
		{
			p[x]._0=merge(p[x]._0,p[a]._1);
			p[x]._1=merge(p[x]._1,p[a]._0);
		}
		else
		{
			p[x]._0=merge(p[x]._0,p[a]._0);
			p[x]._1=merge(p[x]._1,p[a]._1);
		}
		return;
	}
	if(p[x].type==5)
	{
		p[x].real=!p[a].real;
		p[x]._0=p[a]._1;
		p[x]._1=p[a]._0;
	}
	
}
int ans[1010101];
char s[10];
int main()
{
	int n;
	scanf("%d",&n);
	int num=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int &a=p[i].a,&b=p[i].b;
		if(s[0]=='I'&&s[1]=='N')
		{
			p[i].type=1;
			scanf("%d",&a);
			num++;
			b=num;
		}
		if(s[0]=='A'&&s[1]=='N'&&s[2]=='D')
		{
			p[i].type=2;
			scanf("%d%d",&a,&b);
		}
		if(s[0]=='O'&&s[1]=='R')
		{
			p[i].type=3;
			scanf("%d%d",&a,&b);
		}
		if(s[0]=='X'&&s[1]=='O'&&s[2]=='R')
		{
			p[i].type=4;
			scanf("%d%d",&a,&b);
		}
		if(s[0]=='N'&&s[1]=='O'&&s[2]=='T')
		{
			p[i].type=5;
			scanf("%d",&a);
		}
	}
	dfs(1);
	for(int i=0;i<f[p[1]._0].size();i++)
		ans[f[p[1]._0][i]]=0;
	for(int i=0;i<f[p[1]._1].size();i++)
		ans[f[p[1]._1][i]]=1;
	for(int i=1;i<=num;i++)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}