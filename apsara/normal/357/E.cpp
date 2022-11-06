#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long LL;
int ct[10],tc[10],n,x;
int main()
{
	while(~scanf("%d",&n))
	{
		memset(ct,0,sizeof(ct));
		int s=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			ct[x]++;
			s+=x;
		}
		int ret=4*n;
		for(int i=0;i<=n;i++)
		{
			int n4=s-3*i;
			int n3=i-n4;
			if(n4<0||n4>n)continue;
			if(n3<0||n3>n)continue;
			for(int j=0;j<=4;j++)tc[j]=ct[j];
			int tmp=0;
			if(tc[4]>=n4)tmp+=tc[4]-n4;
			int nd=n-i;
			for(int j=0;j<=2;j++)
			{
				int trans=min(tc[j],nd);
				tmp+=j*trans;
				nd-=trans;
			}
			ret=min(ret,tmp);
		}
		if(ret==4*n)ret=-1;
		printf("%d\n",ret);
	}
	return 0;
}