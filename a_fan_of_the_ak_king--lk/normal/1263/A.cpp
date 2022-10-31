#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int n,i,j,a[3],t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		if(a[0]+a[1]<=a[2])
			printf("%d\n",a[0]+a[1]);
		else
			printf("%d\n",(a[0]+a[1]+a[2])/2);
	}
}