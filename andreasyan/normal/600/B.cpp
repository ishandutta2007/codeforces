#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=2*100005;
struct ban
{
	int x,i;
};
bool operator<(const ban& a,const ban& b)
{
	return a.x<b.x;
}

int n,m;
int a[N],ans[N];
ban b[N];
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<m;++i)
	{
		b[i].i=i;
		scanf("%d",&b[i].x);
	}
	sort(a,a+n);
	sort(b,b+m);
	j=0;
	for(i=0;i<m;++i)
	{
		while(a[j]<=b[i].x)
		{
			if(j==n)
				break;
			++j;
			if(j==n)
				break;
		}
		ans[b[i].i]=j;
	}
	for(i=0;i<m;++i)
		printf("%d ",ans[i]);
	return 0;
}