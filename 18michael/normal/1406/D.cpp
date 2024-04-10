#include<cstdio>
#define LL long long
int n,q,l,r,x;
LL ans,ed;
LL dif[100002];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&dif[i]);
	ans=ed=dif[n];
	for(int i=n;i>1;--i)
	{
		dif[i]-=dif[i-1];
		if(dif[i]<0)ans-=dif[i];
	}
	printf("%lld\n",(ans>>1)+(ans&1)),scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		if(r==n)ed+=x,ans+=x;
		if(l>1)
		{
			if(dif[l]<0)ans+=dif[l];
			dif[l]+=x;
			if(dif[l]<0)ans-=dif[l];
		}
		if(r<n)
		{
			if(dif[r+1]<0)ans+=dif[r+1];
			dif[r+1]-=x;
			if(dif[r+1]<0)ans-=dif[r+1];
		}
		printf("%lld\n",(ans>>1)+(ans&1));
	}
	return 0;
}