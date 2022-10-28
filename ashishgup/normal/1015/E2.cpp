#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n, m;
char a[N][N];
int up[N][N], down[N][N], lft[N][N], rght[N][N];
int verti[N][N], hori[N][N], mark[N][N];
vector<int> x, y, s;

void calcup()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*')
				up[i][j]=up[i-1][j]+1;
			else
				up[i][j]=0;
		}
	}
}

void calcdown()
{
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*')
				down[i][j]=down[i+1][j]+1;
			else
				down[i][j]=0;
		}
	}
}

void calclft()
{
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='*')
				lft[i][j]=lft[i][j-1]+1;
			else
				lft[i][j]=0;
		}
	}
}

void calcrght()
{
	for(int j=m;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='*')
				rght[i][j]=rght[i][j+1]+1;
			else
				rght[i][j]=0;
		}
	}
}

void check()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			verti[i][j]+=verti[i-1][j];
			if(verti[i][j]>0)
				mark[i][j]=1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			hori[i][j]+=hori[i][j-1];
			if(hori[i][j]>0)
				mark[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*' && mark[i][j]==0)
			{
				cout<<"-1";
				exit(0);
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	calcup();	
	calcdown();
	calclft();
	calcrght();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int vert=min(up[i][j], down[i][j]);
			int hor=min(lft[i][j], rght[i][j]);
			int cur=min(vert, hor);
			cur-=1;
			if(cur<=0)
				continue;
			verti[i-cur][j]+=1;
			verti[i+cur+1][j]-=1;
			hori[i][j-cur]+=1;
			hori[i][j+cur+1]-=1;
			x.push_back(i);
			y.push_back(j);
			s.push_back(cur);
		}
	}
	check();
	cout<<x.size()<<endl;
	for(int i=0;i<x.size();i++)
		cout<<x[i]<<" "<<y[i]<<" "<<s[i]<<endl;
	return 0;
}