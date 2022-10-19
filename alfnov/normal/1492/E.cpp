#include<bits/stdc++.h>
using namespace std;
vector<int>g[250005];
int n,m,ff=0;
bool test(vector<int>v)
{
	if(ff)return 1;
	for(int i=1;i<=n;i++)
	{
		int dd=0;
		for(int j=1;j<=m;j++)dd+=v[j]!=g[i][j];
		if(dd>2)return 0;
	}
	ff=1;
	puts("Yes");
	for(int i=1;i<=m;i++)printf("%d ",v[i]);
	puts("");
	return 1;
}
void tset(vector<int>v,int rr)
{
	test(v);
	for(int i=1;i<=n;i++)
	{
		int dd=0;
		for(int j=1;j<=m;j++)if(j!=rr)dd+=g[i][j]!=v[j];
		if(dd==2)
		{
			vector<int>vv=v;
			vv[rr]=g[i][rr];
			test(vv);
			return;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		g[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			int a;
			scanf("%d",&a);
			g[i].push_back(a);
		}
	}
	int mx=-1,ww;
	for(int i=1;i<=n;i++)
	{
		int dd=0;
		for(int j=1;j<=m;j++)dd+=g[1][j]!=g[i][j];
		if(mx<dd)mx=dd,ww=i;
	}
	if(mx<=2)
	{
		test(g[1]);
		return 0;
	}
	if(mx>=5)
	{
		puts("No");
		return 0;
	}
	if(mx==4)
	{
		int w1=0,w2=0,w3=0,w4=0;
		for(int j=1;j<=m;j++)if(g[ww][j]!=g[1][j])
		{
			if(!w1)w1=j;
			else if(!w2)w2=j;
			else if(!w3)w3=j;
			else if(!w4)w4=j;
		}
		bool flag=0;
		vector<int>gg;
		gg=g[ww];
		gg[w1]=g[1][w1],gg[w2]=g[1][w2];
		flag|=test(gg);
		if(flag==1)return 0;
		gg=g[ww];
		gg[w3]=g[1][w3],gg[w4]=g[1][w4];
		flag|=test(gg);
		if(flag==1)return 0;		
		gg=g[ww];
		gg[w1]=g[1][w1],gg[w3]=g[1][w3];
		flag|=test(gg);
		if(flag==1)return 0;
		gg=g[ww];
		gg[w1]=g[1][w1],gg[w4]=g[1][w4];
		flag|=test(gg);
		if(flag==1)return 0;
		gg=g[ww];
		gg[w2]=g[1][w2],gg[w3]=g[1][w3];
		flag|=test(gg);
		if(flag==1)return 0;
		gg=g[ww];
		gg[w4]=g[1][w4],gg[w2]=g[1][w2];
		flag|=test(gg);
		if(flag==1)return 0;
		puts("No");
		return 0;
	}
	int w1=0,w2=0,w3=0;
	for(int j=1;j<=m;j++)if(g[ww][j]!=g[1][j])
	{
		if(!w1)w1=j;
		else if(!w2)w2=j;
		else if(!w3)w3=j;
	}
	vector<int>gg;
	gg=g[ww];
	gg[w1]=g[1][w1];
	tset(gg,w2);
	tset(gg,w3);
	gg=g[ww];
	gg[w2]=g[1][w2];
	tset(gg,w1);
	tset(gg,w3);
	gg=g[ww];
	gg[w3]=g[1][w3];
	tset(gg,w1);
	tset(gg,w2);
	gg=g[ww];
	gg[w1]=g[1][w1],gg[w2]=g[1][w2];
	tset(gg,w3);
	gg=g[ww];
	gg[w1]=g[1][w1],gg[w3]=g[1][w3];
	tset(gg,w2);
	gg=g[ww];
	gg[w2]=g[1][w2],gg[w3]=g[1][w3];
	tset(gg,w1);
	if(!ff)puts("No");
	return 0;
}