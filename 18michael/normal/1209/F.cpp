#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,t;
int len[1000002],pw[7],ans[1000002]={};
vector<int> vec[1000002][10];
vector<int> v,v1;
queue<vector<int> > q;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,int z)
{
	for(int i=1;i<len[z];++i)vec[++t][(z/pw[i-1])%10].push_back(y),vec[y][(z/pw[len[z]-i])%10].push_back(t),y=t;
	vec[x][z/pw[len[z]-1]].push_back(y),vec[y][z%10].push_back(x);
}
int main()
{
	read(n),read(m),t=n,pw[0]=1;
	for(int i=1;i<=6;++i)pw[i]=pw[i-1]*10;
	for(int i=1;i<=m;++i)len[i]=len[i/10]+1;
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y,i);
	for(int i=2;i<=t;++i)ans[i]=-1;
	v.push_back(1),q.push(v),v.clear();
	while(!q.empty())
	{
		v=q.front(),q.pop();
		for(int i=0;i<10;++i)
		{
			v1.clear();
			for(int j=0;j<v.size();++j)
				for(int k=0;k<vec[v[j]][i].size();++k)
					if(ans[vec[v[j]][i][k]]<0)
						ans[vec[v[j]][i][k]]=(10LL*ans[v[j]]+i)%mod,v1.push_back(vec[v[j]][i][k]);
			if(!v1.empty())q.push(v1);
		}
	}
	for(int i=2;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}