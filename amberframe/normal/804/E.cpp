#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
void o(int u,int v)
{
	if (u>v) swap(u,v);
	printf("%d %d\n",u,v);
}
void work(int n)
{
	int a=n+1,b=n+2,c=n+3,d=n+4;
	for (int i=n;i>=1;i--) o(a,i);
	for (int i=n;i>=1;i--) o(b,i);
	o(a,d);o(b,c);
	for (int i=1;i<=n;i++) o(c,i);
	for (int i=1;i<=n;i++) o(d,i);
	o(a,c);o(b,d);o(a,b);o(c,d);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("permutation.in","r",stdin);
		freopen("permutation.out","w",stdout);
	#endif
	int n;scanf("%d",&n);
	if (n%4>=2&&n%4<=3) puts("NO");
	else {
		puts("YES");
		for (int i=n%4;i<n;i+=4) work(i); 
	}
	return 0;
}