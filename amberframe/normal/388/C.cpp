#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
const int maxn = 1005;

int n,a[maxn],b[maxn],s1,s2;
bool comp(int a,int b){return a>b;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int s;scanf("%d",&s);
		for (int i=1;i<=s;i++)
			scanf("%d",&b[i]);
		for (int i=1,j=s;i<j;i++,j--)
			s1+=b[i],s2+=b[j];
		a[i]=s&1?b[s+1>>1]:0;
	}
	sort(a+1,a+n+1,comp);
	for (int i=1;i<=n;i+=2)
		s1+=a[i],s2+=a[i+1];
	printf("%d %d",s1,s2);
	return 0;
}