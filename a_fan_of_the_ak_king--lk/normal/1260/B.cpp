#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=500005;
int n,a,b;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		if(2*a-b>=0&&2*b-a>=0&&(2*a-b)%3==0&&(2*b-a)%3==0)
			puts("yes");
		else
			puts("no");
	}
}