#include<bits/stdc++.h>
using namespace std;
struct dt
{
	int x,y,z;
};
int n,m;
int a[1005][1005],f[1005][1005];
inline int check(int x,int y)
{
	if (x==0||y==0||x==n||y==m)
		return -1;
	int sum=0;
	for (int i=x;i<=x+1;++i)
		for (int j=y;j<=y+1;++j)
		{
			if (!f[i][j])
			{
				if (!sum)
					sum=a[i][j];
				else
				{
					if (sum!=a[i][j])
						sum=-1;
				}
			}
		}
	// cout<<"!"<<x<<' '<<y<<' '<<sum<<endl;
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	queue<pair<int,int> > q;
	vector<dt> ans;
	for (int i=1;i<n;++i)
		for (int j=1;j<m;++j)
		{
			if (check(i,j)>0)
				q.push({i,j});
		}
	while (!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		// cout<<x<<' '<<y<<' '<<check(x,y)<<endl;
		if (check(x,y)>0)
		{
			ans.push_back({x,y,check(x,y)});
			f[x][y]=f[x][y+1]=f[x+1][y]=f[x+1][y+1]=1;
			for (int i=x-1;i<=x+1;++i)
				for (int j=y-1;j<=y+1;++j)
					if (check(i,j)>0)
					{
						// cout<<"!"<<i<,' '
						q.push({i,j});
					}
		}
	}
	bool b=true;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (!f[i][j])
				b=false;
	if (!b)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",ans.size());
	for (int i=(int)ans.size()-1;i>=0;--i)
		printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
	return 0;
}