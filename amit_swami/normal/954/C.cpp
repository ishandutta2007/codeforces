#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200000+10;

int n,a[N],m;

pair<int,int> f(int x)
{
	return make_pair((x-1)/m+1,(x-1)%m+1);
}

bool g(pair<int,int> a,pair<int,int> b)
{
	return abs(a.first-b.first)+abs(a.second-b.second)==1;
}

bool check()
{
	int i;
	for(i=1;i<n;++i)
		if(!g(f(a[i]),f(a[i+1])))
			return false;
	return true;
}

void print(pair<int,int> p)
{
	cout<<p.first<<","<<p.second<<endl;
}

int main()
{
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	if(n==1)
	{
		printf("YES\n1000000000 1000000000");
		return 0;
	}
	for(i=1;i<n;++i)
		if(abs(a[i]-a[i+1])!=1)
		{
			m=abs(a[i]-a[i+1]);
			if(m&&check())
			{
				printf("YES\n1000000000 %d",m);
				return 0;
			}
			printf("NO");
			return 0;
		}
	printf("YES\n1000000000 1000000000");
	return 0;
}