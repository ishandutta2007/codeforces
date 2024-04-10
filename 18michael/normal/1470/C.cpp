#include<cstdio>
#include<ctime>
#include<cstdlib>
int n,k,cnt,t=0,p,l,r,mid;
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int RND()
{
	int x=rand();
	x*=rand(),x+=rand();
	x*=rand(),x+=rand();
	x*=rand(),x+=rand();
	x%=n,x+=n,x%=n;
	return x+1;
}
int main()
{
	srand(time(NULL)),scanf("%d%d",&n,&k);
	while(1)
	{
		printf("? %d\n",cnt=RND()),fflush(stdout),scanf("%d",&p);
		if(p!=k)break;++t;
	}
	if(p<k)
	{
		l=cnt+1,r=cnt+min(n,t);
		while(l<=r)
		{
			printf("? %d\n",((mid=((l+r)>>1))-1)%n+1),fflush(stdout),scanf("%d",&p);
			if(p<k)l=mid+1;else r=mid-1;
		}
		printf("! %d\n",(l-1)%n+1),fflush(stdout);
	}
	else
	{
		l=n+cnt-min(n,t),r=n+cnt-1;
		while(l<=r)
		{
			printf("? %d\n",((mid=((l+r)>>1))-1)%n+1),fflush(stdout),scanf("%d",&p);
			if(p>k)r=mid-1;else l=mid+1;
		}
		printf("! %d\n",(r-1)%n+1),fflush(stdout);
	}
	return 0;
}