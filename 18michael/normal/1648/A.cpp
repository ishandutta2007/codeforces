#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 100000
#define LL long long
using namespace std;
int n,m;LL ans=0;
vector<int> vecx[100002];
vector<int> vecy[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m);
	for(int i=1,x;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(x),vecx[x].push_back(i),vecy[x].push_back(j);
	for(int i=1;i<=Mx;++i)
	{
		sort(vecx[i].begin(),vecx[i].end()),sort(vecy[i].begin(),vecy[i].end());
		for(int j=0;j<vecx[i].size();++j)ans+=1LL*vecx[i][j]*(j-((int)vecx[i].size()-j-1))+1LL*vecy[i][j]*(j-((int)vecy[i].size()-j-1));
		//printf("%d:%d %d %lld\n",i,vecx[i].size(),vecy[i].size(),ans);
	}
	return 0&printf("%lld",ans);
}