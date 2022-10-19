#include<cstdio>
#define LL long long
int n,mx=0,mx1,h1_t=0,st_t=1,la;LL ans;
int h[1000002],h1[1000002],cnt[1000002],st[1000002];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&h[i]);
		if(h[i]>h[mx])mx=i;
	}
	for(int i=0;i<n;++i)
	{
		if(h1[h1_t]!=h[(i+mx)%n])h1[++h1_t]=h[(i+mx)%n],cnt[h1_t]=1;
		else ++cnt[h1_t];
	}
	st[1]=1;
	for(int i=2;i<=h1_t;++i)
	{
		while(h1[st[st_t]]<h1[i])ans+=2*cnt[st[st_t]]+1LL*cnt[st[st_t]]*(cnt[st[st_t]]-1)/2,--st_t;
		if(h1[i]<h1[st[st_t]])st[++st_t]=i;else cnt[st[st_t]]+=cnt[i];
	}
	for(int i=2;i<=st_t;++i)ans+=cnt[st[i]];
	for(int i=1;i<=st_t;++i)ans+=1LL*cnt[st[i]]*(cnt[st[i]]-1)/2;
	mx1=1;
	for(int i=2;i<n;++i)
		if(h[(mx+i)%n]>=h[(mx+mx1)%n])
			mx1=i;
	if(mx1<n-1)
	{
		++ans,la=n-1;
		for(int i=n-2;i>mx1;--i)
			if(h[(mx+i)%n]>=h[(mx+la)%n])
				++ans,la=i;
	}
	return 0&printf("%lld",ans);
}