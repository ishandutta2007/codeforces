#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#define LL long long
using namespace std;
LL n,k,l=1,r,mid,t;char s[3];
inline LL RND(LL l,LL r)
{
	return rand()%(r-l+1)+l;
}
inline LL min(LL a,LL b)
{
	return a<b? a:b;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
int main()
{
	srand(time(NULL)),scanf("%lld%lld",&n,&k),r=n;
	while(l<=r)
	{
		if(r-l<=4*k)
		{
			t=RND(l,r),cout<<t<<' '<<t<<endl,scanf("%s",s);
			if(s[0]=='Y')return 0;
		}
		else
		{
			mid=((l+r)>>1),cout<<l<<' '<<mid<<endl,scanf("%s",s);
			if(s[0]=='Y')r=mid;else l=mid+1;
		}
		l=max(l-k,1),r=min(r+k,n);
	}
	return 0;
}