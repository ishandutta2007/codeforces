#include<stdio.h>
#include<bits/stdc++.h>
using std::min;
using std::max;

using std::swap;

using std::sort;

using std::vector;
using std::set;
using std::map;
//using std::unordered_map;
// unordered_map is disgusting and not used as default 
using std::multiset;
using std::set;
using std::priority_queue;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef unsigned unt;

struct pii
{
	int x,y;
	pii():x(0),y(0){}
	pii(int x0,int y0):x(x0),y(y0){}
};
namespace sol
{
	int n,m;
	int a[1<<20];
	bool vis[1<<23];
	int f[1<<23];
	void exec()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			vis[i]=0;
		int mnv=1e9;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),vis[a[i]]=1,mnv=min(mnv,a[i]);
		int ans=1e9;
		multiset<int>S;
		for(int i=1;i<=m;i++)
		{
			f[i]=-1e9;
			if(vis[i])S.insert(f[i]);
		}
		//int cnt=0;
		for(int i=1;i<=m;i++)
		{
			if(f[i]!=i)
			{
				if(vis[i])
				{
					S.erase(S.find(f[i]));
					S.insert(i);
				}
				f[i]=i;
			}
			
			for(int ii=i*2;ii<=m;ii+=i)
			{
				int t=max(f[ii],min(f[ii/i],i));
				if(f[ii]!=t)
				{
					//cnt++;
					//printf("%d [%d] -> %d\n",ii,f[ii],t);
					if(vis[ii])
					{
						S.erase(S.find(f[ii]));
						S.insert(t);
					}
					f[ii]=t;
				}
			}
			//for(int t:S)
			//	printf("%d ",t);puts("!");
			//printf("%d %d\n",i,*S.begin());
			int cur=i-*S.begin();
			if(cur<=ans)ans=cur;
		}
		//fprintf(stderr,"%d\n",cnt); 
		/*
		for(int i=m;i;i--)
		{
			if(i-mnv<=ans)ans=i-mnv;
			for(int k=i;k<=m;k+=i)
				if(vis[k])mnv=std::min(mnv,split(k,i));
		}
		*/
		printf("%d\n",ans);
	}
}

int main()
{
	int __T=1;
	scanf("%d",&__T);
	while(__T--)sol::exec();
}