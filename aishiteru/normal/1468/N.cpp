#include<bits/stdc++.h>
using namespace std; 
const int N=1000005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,t,x,y,z,a,b,c,d,e;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&z);
	 	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	 	x-=a,y-=b,z-=c;
	 	if(x<0||y<0||z<0)
	 		puts("No");
	 	else
	 	{
	 		d-=x,e-=y;
	 		d=max(0,d);
	 		e=max(0,e);
	 		if(d+e<=z)
	 			puts("Yes");
	 		else
	 			puts("No");
	 	}
	 }
}