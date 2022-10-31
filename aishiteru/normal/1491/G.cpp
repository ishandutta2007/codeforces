#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,vis[N],p[N],k;
struct str{
	int l,r;
};
vector<str> g;
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
//2 3 1
//1 3 2
//3 1 2
//3 2 1
//1 2 3
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&p[i]);
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			if(p[i]==i)
				continue;
			vector<int> A,B;
			for(j=i;!vis[j];j=p[j])
			{
				vis[j]=1;
				A.push_back(j);
			}
			for(k=i+1;(vis[k]||p[k]==k)&&k<=n;++k);
			if(k<=n)
			{
				for(j=k;!vis[j];j=p[j])
				{
					vis[j]=1;
					B.push_back(j);
				}
				g.push_back({A[0],B[0]});
				for(j=1;j<B.size();++j)
					g.push_back({A[0],B[j]});
				for(j=1;j<A.size();++j)
					g.push_back({A[j],B[0]});
				g.push_back({A[0],B[0]});
			}
			else
				if(A.size()==2)
				{
					for(j=1;j<=n;++j)
						if(j!=i&&j!=p[i])
							break;
					int e=j;
					g.push_back({e,i});
					g.push_back({e,p[i]});
					g.push_back({e,i});
				}
				else
				{
					g.push_back({A[0],A[A.size()-1]});
					int las=A[A.size()-1];
					for(j=1;j<A.size()-2;++j)
						g.push_back({las,A[j]});
					int x=A[0],y=A[A.size()-2],z=A[A.size()-1];
					g.push_back({x,y});
					g.push_back({y,z});
					g.push_back({x,z});
				}
		}
	printf("%d\n",g.size());
	for(auto it:g)
		printf("%d %d\n",it.l,it.r);
}