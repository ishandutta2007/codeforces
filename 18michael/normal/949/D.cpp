#include<cstdio>
#define LL long long
int b,l=1,r,mid,lcnt,rcnt,ans;
LL n,d,lsum,rsum,sum;
bool ok0,ok1;
LL a[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL min(LL x,LL y)
{
	return x<y? x:y;
}
inline LL max(LL x,LL y)
{
	return x>y? x:y;
}
inline bool check(int x)
{
	lcnt=rcnt=lsum=rsum=ok0=ok1=0,sum=a[x]-a[x-1];
	for(int i=1;i<=n/2;++i)
	{
		lsum+=a[min(d*i+i,x-1)]-a[min(d*(i-1)+(i-1),x-1)],rsum+=a[max(n-d*(i-1)-(i-1),x)]-a[max(n-d*i-i,x)];
		if(d*i+i>=x)ok0=1;if(n-d*i-i+1<=x)ok1=1;
		if(lsum>=b)lsum-=b;else if(ok0 && lsum+sum>=b)sum-=b-lsum,lsum=0;else ++lcnt;
		if(rsum>=b)rsum-=b;else if(ok1 && rsum+sum>=b)sum-=b-rsum,rsum=0;else ++rcnt;
		
	}
	if(d*((n+1)/2)+((n+1)/2)>=x)ok0=1;
	if(n&1)if(lsum>=b)lsum-=b;else if(ok0 && lsum+sum>=b)sum-=b-lsum,lsum=0;else ++lcnt;
	ans=min(ans,max(lcnt,rcnt));
	return lcnt>rcnt;
}
int main()
{
	read(n),read(d),read(b),r=ans=n;
	for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1];
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	return 0&printf("%d",ans);
}