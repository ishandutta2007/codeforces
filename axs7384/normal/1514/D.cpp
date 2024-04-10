#include<bits/stdc++.h>
using namespace std;
const int KDX=500;
const int N=300005;
int a[N],ti[N],T[N];
struct data
{
	int x,y,id;
	bool operator<(const data &a)const
	{
		return y<a.y;
	}
}q;
vector<data> v[605];
int n,m;
int ans[N];
inline int calc(int x,int y)
{
	return y*2<=x+1?1:y*2-x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&q.x,&q.y);
		q.id=i;
		v[q.x/KDX].push_back(q);
	}
	for (int i=0;i<=600;++i)
		if (v[i].size())
		{
			for (int j=1;j<=n;++j)
				ti[j]=0;
			int md=(i+1)*KDX,p=md,mx=a[md],tmx;
			// if (md>n)
			// {
			// 	p=md=n;
			// 	mx=a[md];
			// }
			ti[a[md]]=1;
			sort(v[i].begin(),v[i].end());
			for (int j=0;j<(int)v[i].size();++j)
			{
				if (v[i][j].y<md)
				{
					tmx=1;
					for (int k=v[i][j].x;k<=v[i][j].y;++k)
					{
						++T[a[k]];
						if (T[a[k]]>T[tmx])
							tmx=a[k];
					}
					ans[v[i][j].id]=calc(v[i][j].y-v[i][j].x+1,T[tmx]);
					for (int k=v[i][j].x;k<=v[i][j].y;++k)
						--T[a[k]];
					continue;
				}
				while (v[i][j].y>p)
				{
					++p;
					++ti[a[p]];
					if (ti[a[p]]>ti[mx])
						mx=a[p];
				}
				tmx=mx;
				for (int k=v[i][j].x;k<md;++k)
				{
					++ti[a[k]];
					if (ti[a[k]]>ti[tmx])
						tmx=a[k];
				}
				// cout<<v[i][j].id<<' '<<ti[tmx]<<endl;
				ans[v[i][j].id]=calc(v[i][j].y-v[i][j].x+1,ti[tmx]);
				for (int k=v[i][j].x;k<md;++k)
					--ti[a[k]];
			}
		}
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}