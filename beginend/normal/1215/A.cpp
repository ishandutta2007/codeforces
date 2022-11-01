#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int a1,a2,k1,k2,n;
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	int ans=0,m=n;
	if (k1>k2) std::swap(a1,a2),std::swap(k1,k2);
	int s=std::min(a1,n/k1);
	ans+=s;
	n-=k1*s;
	s=std::min(a2,n/k2);
	ans+=s;
	m-=a1*(k1-1)+a2*(k2-1);
	printf("%d %d\n",std::max(0,m),ans);
	return 0;
}