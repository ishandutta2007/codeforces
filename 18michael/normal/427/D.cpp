#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
int n,m=300,t,ans=inf;
int cnt[10005],rk[10005],sa[10005],id[10005],px[10005],oldrk[10005],height[10005];
char s[10005];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline bool cmp(int x,int y,int l)
{
	return oldrk[x]==oldrk[y] && oldrk[x+l]==oldrk[y+l];
}
int main()
{
	scanf("%s",s+1),t=strlen(s+1),s[t+1]='#',scanf("%s",s+t+2),n=strlen(s+1);
	for(int i=0;i<=m;++i)cnt[i]=0;
	for(int i=1;i<=n;++i)++cnt[rk[i]=s[i]];
	for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)sa[cnt[rk[i]]--]=i;
	for(int w=1,p;w<=n;w<<=1,m=p)
	{
		p=0;
		for(int i=n;i>n-w;--i)id[++p]=i;
		for(int i=1;i<=n;++i)if(sa[i]>w)id[++p]=sa[i]-w;
		for(int i=0;i<=m;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)++cnt[px[i]=rk[id[i]]];
		for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
		for(int i=n;i;--i)sa[cnt[px[i]]--]=id[i];
		for(int i=1;i<=n;++i)oldrk[i]=rk[i];
		p=0;
		for(int i=1;i<=n;++i)rk[sa[i]]=cmp(sa[i],sa[i-1],w)? p:(++p);
		if(p==n)break;
	}
	for(int i=1,k=0;i<=n;++i)
	{
		if(k)--k;
		while(s[i+k]==s[sa[rk[i]-1]+k])++k;
		height[rk[i]]=k;
	}
	for(int i=2;i<=n;++i)
		if(s[sa[i]]!='#' && height[i]>height[i-1] && height[i]>height[i+1] && ((sa[i]>t)^(sa[i-1]>t)))
			ans=min(ans,max(height[i-1],height[i+1])+1);
	return 0&printf("%d",ans==inf? -1:ans);
}