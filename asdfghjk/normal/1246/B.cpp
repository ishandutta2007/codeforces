#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,K,a[100005],i,j,k,x,y,z,w,pw[10],p[25000000],c[25000000];
bool v[25000000];
vector<int> vct[100005];
long long ans;
int main()
{
	scanf("%d%d",&n,&K);
	pw[0]=1;
	for(i=1;i<=7;++i)
		pw[i]=pw[i-1]*17;
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		j=a[i];
		x=1,z=0,w=0;
		for(k=2;k*k<=j;++k)
			if(j%k==0)
			{
				y=0;
				while(j%k==0)
					j/=k,++y;
				z+=y%K*pw[w];
				if(y%K)
					x*=k,++w;
			}
		if(j>1)
		{
			x*=j;
			z+=pw[w];
		}
		v[z]=true;
		vct[x].push_back(z);
		//printf("%d %d %d\n",a[i],x,z);
	}
	for(i=0;i<25000000;++i)
	if(v[i])
	{
		for(j=0,k=0;j<=5;++j)
		{
			if((K-i/pw[j]%17)%K>=17)
				break;
			k+=(K-i/pw[j]%17)%K*pw[j];
		}
		if(j<=5)
			p[i]=-1;
		else
			p[i]=k;
	}
	for(i=1;i<=100000;++i)
		if(!vct[i].empty())
		{
			for(j=vct[i].size()-1;j>=0;--j)
				c[vct[i][j]]++;
			for(j=vct[i].size()-1;j>=0;--j)
				if(p[vct[i][j]]!=-1)
					ans+=c[p[vct[i][j]]]+(p[vct[i][j]]==vct[i][j]?-1:0);
			for(j=vct[i].size()-1;j>=0;--j)
				c[vct[i][j]]--;
		}
	ans/=2;
	printf("%I64d",ans);
	return 0;
}