#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=500100;
int a[V],n;
int cnt[V];
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		int lo=-1,up=n;
		while(lo+1<up)
		{
			int mid=(lo+up)/2;
			bool can=true;
			if(2*mid>n)can=false;
			for(int i=0;i<mid;i++)
			if(a[i]*2>a[n-mid+i])can=false;
			if(!can)up=mid;
			else lo=mid;
		}
		printf("%d\n",n-lo);
	}
	return 0;
}