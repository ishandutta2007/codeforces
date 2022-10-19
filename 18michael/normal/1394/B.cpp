#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,t1=0,t2=1;
int x[200002],y[200002],w[200002],id[200002];
int Hs1[9][9],Hs2[9][9];
vector<int> vec[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int a,int b)
{
	return w[a]<w[b]? 1:0;
}
inline void dfs(int x,int y1,int y2)
{
	if(x>k){ans+=(y1==t1 && y2==t2);return ;}
	for(int i=0;i<x;++i)dfs(x+1,y1+Hs1[x][i],y2*Hs2[x][i]);
}
int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=m;++i)read(x[i]),read(y[i]),read(w[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1;i<=m;++i)vec[x[id[i]]].push_back(y[id[i]]);
	for(int i=1;i<=k;++i)
		for(int j=0;j<i;++j)
			Hs1[i][j]=0,Hs2[i][j]=1;
	for(int i=1;i<=n;++i)
	{
		t1+=i,t2*=i;
		for(int j=0;j<vec[i].size();++j)
			Hs1[vec[i].size()][j]+=vec[i][j],Hs2[vec[i].size()][j]*=vec[i][j];
	}
	dfs(1,0,1),printf("%d",ans);
	return 0;
}