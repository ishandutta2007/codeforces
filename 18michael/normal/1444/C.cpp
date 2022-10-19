#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k,k1,x,y,rx,rx1,ry,ry1;LL ans;
int rt[1000002],rt1[1000002],rt2[1000002],siz[1000002],siz1[1000002],siz2[1000002],Rx[1000002],Rx1[1000002],Ry[1000002],Ry1[1000002],c[1000002];
bitset<1000002> u;
vector<int> v,v1;
typedef pair<int,int> P;
vector<P> vec[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(P a,P b)
{
	return c[a.second]<c[b.second]? 1:0;
}
inline int getroot(int x)
{
	return x==rt[x]? x:getroot(rt[x]);
}
inline void clear()
{
	for(int i=v1.size()-1;~i;--i)
	{
		rx=Rx[i],rx1=Rx1[i],ry=Ry[i],ry1=Ry1[i];
		if(siz[rx]<siz[ry1])siz[ry1]=siz1[i],rt[rx]=rt1[i];
		else siz[rx]=siz1[i],rt[ry1]=rt1[i];
		if(siz[ry]<siz[rx1])siz[rx1]=siz2[i],rt[ry]=rt2[i];
		else siz[ry]=siz2[i],rt[rx1]=rt2[i];
	}
	for(int i=0;i<v.size();++i)u[v[i]]=0;
	v.clear(),v1.clear();
}
int main()
{
	read(n),read(m),read(k),k1=k;
	for(int i=1;i<=n;++i)read(c[i]),rt[i]=i,rt[i+n]=i+n,siz[i]=siz[i+n]=1;
	for(int i=1;i<=m;++i)
	{
		read(x),read(y);
		if(u[c[x]] || u[c[y]])--m,--i;
		else if(c[x]==c[y])
		{
			rx=getroot(x),rx1=getroot(x+n),ry=getroot(y),ry1=getroot(y+n);
			if(rx==ry)u[c[x]]=1;
			else
			{
				if(siz[rx]<siz[ry1])siz[ry1]+=siz[rx],rt[rx]=ry1;
				else siz[rx]+=siz[ry1],rt[ry1]=rx;
				if(siz[ry]<siz[rx1])siz[rx1]+=siz[ry],rt[ry]=rx1;
				else siz[ry]+=siz[rx1],rt[rx1]=ry;
			}
			--m,--i;
		}
		else
		{
			if(c[x]>c[y])swap(x,y);
			vec[c[x]].push_back(P(x,y));
		}
	}
	for(int i=1;i<=k;++i)if(u[i])--k1;
	ans=1LL*k1*(k1-1)/2;
	for(int i=1;i<=k;++i)
		if(!u[i])
		{
			sort(vec[i].begin(),vec[i].end(),cmp);
			for(int j=0;j<vec[i].size();++j)
			{
				if(j && c[vec[i][j].second]!=c[vec[i][j-1].second])clear();
				x=vec[i][j].second,y=vec[i][j].first,rx=getroot(x);
				if(u[c[x]])continue;
				rx1=getroot(x+n),ry=getroot(y),ry1=getroot(y+n);
				if(rx==ry)u[c[x]]=1,--ans,v.push_back(c[x]);
				else
				{
					if(siz[rx]<siz[ry1])siz1[v1.size()]=siz[ry1],rt1[v1.size()]=rt[rx],siz[ry1]+=siz[rx],rt[rx]=ry1;
					else siz1[v1.size()]=siz[rx],rt1[v1.size()]=rt[ry1],siz[rx]+=siz[ry1],rt[ry1]=rx;
					if(siz[ry]<siz[rx1])siz2[v1.size()]=siz[rx1],rt2[v1.size()]=rt[ry],siz[rx1]+=siz[ry],rt[ry]=rx1;
					else siz2[v1.size()]=siz[ry],rt2[v1.size()]=rt[rx1],siz[ry]+=siz[rx1],rt[rx1]=ry;
					Rx[v1.size()]=rx,Rx1[v1.size()]=rx1,Ry[v1.size()]=ry,Ry1[v1.size()]=ry1,v1.push_back(j);
				}
			}
			clear();
		}
	return 0&printf("%lld",ans);
}