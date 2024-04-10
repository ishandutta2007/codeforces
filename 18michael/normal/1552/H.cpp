#include<bits/stdc++.h>
using namespace std;
int S,l=1,r=7,mid;
int v[12];
int main()
{
	for(int i=1;i<=7;++i)v[i]=-1;
	puts("? 40000");
	for(int i=1;i<=200;++i)for(int j=1;j<=200;++j)printf("%d %d ",i,j);
	puts(""),fflush(stdout),scanf("%d",&S);
	for(;l<=r;)
	{
		mid=((l+r)>>1),printf("? %d\n",(200>>mid)*200);
		for(int i=1;i<=200;++i)if(!(i&((1<<mid)-1)))for(int j=1;j<=200;++j)printf("%d %d ",i,j);
		puts(""),fflush(stdout),scanf("%d",&v[mid]);
		if((v[mid]<<mid)==S)l=mid+1;
		else r=mid-1;
	}
	for(int i=1,x;;++i)
		if(i==8 || (~v[i] && (v[i]<<i)^S))
		{
			x=abs((S>>(i-1))-(v[i]<<1)),printf("! %d",(x+S/x-2)<<1);
			return 0&fflush(stdout);
		}
}