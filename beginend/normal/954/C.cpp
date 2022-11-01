#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;
const int inf=1000000000;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int y=-1;
	for (int i=2;i<=n;i++)
		if (abs(a[i]-a[i-1])!=1)
		{
			if (y==-1) y=abs(a[i]-a[i-1]);
			else if (abs(a[i]-a[i-1])!=y) {puts("NO");return 0;}
		}
	if (y==-1) y=inf;
	if (!y) {puts("NO");return 0;}
	for (int i=2;i<=n;i++)
		if (abs(a[i]-a[i-1])==1&&(a[i]-1)/y!=(a[i-1]-1)/y) {puts("NO");return 0;}
	printf("YES\n%d %d",inf,y);
	return 0;
}