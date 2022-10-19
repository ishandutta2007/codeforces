#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
LL ans=0;
int X[302],Y[302];
LL f[302][302][6];
struct aaa
{
	int x,y;
	double k;
};
vector<aaa> vec;
inline bool cmp(aaa a,aaa b)
{
	return a.k<b.k;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&Y[i]),f[i][i][0]=1;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i^j)vec.push_back((aaa){i,j,atan2(X[i]-X[j],Y[i]-Y[j])});
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();++i)for(int j=1;j<=n;++j)for(int k=1;k<=5;++k)f[j][vec[i].y][k]+=f[j][vec[i].x][k-1];
	for(int i=1;i<=n;++i)ans+=f[i][i][5];
	return 0&printf("%lld",ans);
}