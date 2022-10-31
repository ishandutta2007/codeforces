#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=1000005,M=998244353;
int n,i,t,a[5];
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
		if(a[0]+a[1]<a[2]-1)
			puts("No");
		else
			puts("Yes");
	}
}