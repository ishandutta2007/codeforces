#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=505;

int n,a[MAXN],u[MAXN*10],v[MAXN*10];

int main()
{
    scanf("%d",&n);
    int sum=2,cnt=0,c2=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if(a[i]>=2)++cnt,sum+=a[i]-2;
    	else ++c2,a[i]=-1;
    }
    if(c2>sum)printf("NO\n");
    else
    {
    	int last=0,m=0,cur=1;
    	for(int i=1;i<=n;i++)
    		if(a[i]>=2)
			{
				if(last)u[++m]=i,v[m]=last,--a[i],--a[last];
				last=i;
			}
		bool flag=0;
		for(int i=1;i<=n;i++)
			if(a[i]<0)
			{
				if(!flag)
				{
					u[++m]=i;v[m]=last;
					--a[last];
					flag=1;
					continue;
				}
				while(a[cur]<=0)++cur;
				u[++m]=i,v[m]=cur;
				--a[cur];
			}
    	printf("YES %d\n%d\n",cnt+min(c2,2)-1,m);
    	for(int i=1;i<=m;i++)
    		printf("%d %d\n",u[i],v[i]);
    }
    return 0;
}