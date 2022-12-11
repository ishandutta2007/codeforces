#include <bits/stdc++.h>
using namespace std;

int n,a[1000111];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]+cur);
		cur=std::max(cur,a[i]+cur);
	}
	return 0;
}