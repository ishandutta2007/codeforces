#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,t,a,b,x,y;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a,&b,&x,&y);
		printf("%d\n",abs(a-x)+abs(b-y)+2*(a!=x&&b!=y));
	}
}