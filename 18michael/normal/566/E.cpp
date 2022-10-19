#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
vector<int> vec;
int to[1002];
bool u[1002],u1[1002];
bitset<1002> tmp;
bitset<1002> bs[1002],bs1[1002];
inline void Print(bitset<1002> bs[])//Delete
{
	for(int i=1;i<=n;++i)
	{
		printf("%d:",i);for(int j=1;j<=n;++j)printf("%d",(int)bs[i][j]);
		puts("");
	}
	puts("");
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d",&x),bs1[i].set(i);
		for(int j=1;j<=x;++j)scanf("%d",&y),bs[i].set(y);
	}
	for(int i=1,x,y;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if((tmp=bs[i]&bs[j]).count()==2)
			{
				y=tmp._Find_next(x=tmp._Find_first());
				if(bs1[x].test(y))continue;
				printf("%d %d\n",x,y),bs1[x].set(y),bs1[y].set(x);
				if(!u[x])u[x]=1,++cnt;
				if(!u[y])u[y]=1,++cnt;
			}
	if(cnt<=1)
	{
		for(int i=2;i<=n;++i)printf("1 %d\n",i);
		return 0;
	}
	for(int i=1;i<=n;++i)if(u[i])vec.push_back(i);
	if(cnt==2)
	{
		for(int i=1;i<=n;++i)
			if(bs[i].count()<n)
			{
				for(int j=bs[i]._Find_first();j<=n;j=bs[i]._Find_next(j))if(!u[j])printf("%d %d\n",vec[0],j),u[j]=1;
				break;
			}
		for(int i=1;i<=n;++i)if(!u[i])printf("%d %d\n",vec[1],i);
		return 0;
	}
	tmp.reset();
	for(int i=1;i<=n;++i)
	{
		if(!u[i])
		{
			for(int j=1;j<=n;++j)if(!u1[j] && bs[j].test(i) && (!to[i] || bs[j].count()<bs[to[i]].count()))to[i]=j;
			u1[to[i]]=1;
		}
		else tmp.set(i);
	}
	for(int i=1;i<=n;++i)bs[i]&=tmp;
	for(int i=1;i<=n;++i)
		if(!u[i])
			for(int j=1;j<=n;++j)
				if(bs1[j]==bs[to[i]])
				{
					printf("%d %d\n",i,j);
					break;
				}
	return 0;
}