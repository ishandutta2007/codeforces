#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int siz[502],id[502];
bool u[502];
vector<int> son[502];
inline bool cmp(int x,int y)
{
	return siz[x]<siz[y]? 1:0;
}
inline void solve(int l,int r,int x,int y)
{
	if(l==r)return (void)(son[x].push_back(id[l]),u[l]=1);
	int mid=((l+r)>>1),z=0;
	vector<int> vec;
	for(int i=l;i<=mid;++i)if(!u[i])vec.push_back(id[i]);
	if(vec.size())
	{
		printf("1\n1\n%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
		printf("%d\n",x),fflush(stdout),scanf("%d",&z);
	}
	if(z)solve(l,mid,x,z);
	if(y-z)solve(mid+1,r,x,y-z);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		printf("1\n1\n%d\n",n-1);
		for(int j=2;j<=n;++j)printf("%d%c",j,j==n? '\n':' ');
		printf("%d\n",i),fflush(stdout),scanf("%d",&siz[i]),siz[i]+=(i==1),id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1,x;i<=n;++cnt,++i)
	{
		if(siz[id[i]]==1)continue;
		printf("1\n1\n%d\n",cnt);
		for(int j=1;j<i;++j)if(!u[j])printf("%d ",id[j]);
		printf("\n%d\n",id[i]),fflush(stdout),scanf("%d",&x),cnt-=x,solve(1,i-1,id[i],x);
	}
	puts("ANSWER");
	for(int i=1;i<=n;++i)for(int j=0;j<son[i].size();++j)printf("%d %d\n",i,son[i][j]);
	return 0;
}