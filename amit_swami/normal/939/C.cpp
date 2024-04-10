#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[233333],f,s,cnt[520233],ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	scanf("%d%d",&f,&s);--f;--s;
	for(int i=0;i<n;++i)
	{
		cnt[f-i+n]+=a[i];
		cnt[s-i+n]-=a[i];
	}
	for(int i=1;i<n+n;++i)cnt[i]+=cnt[i-1];
	for(int i=0;i<n;++i)cnt[i]+=cnt[i+n];
	for(int i=1;i<n;++i)
	{
		if(cnt[ans]<cnt[i])
		{
			ans=i;
		}
	}
	printf("%d",ans+1);
	return 0;
}