#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,t,x,a,b,c,d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",max(a+b,c+d));
	}
}