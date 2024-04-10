#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,st_t=0,tmp=0;
LL ans;
int a[300002],l[300002],r[300002],st[300002],pre[300002],cnt[1000002];
struct aaa
{
	int l,r,o;
};
vector<aaa> vecl[300002],vecr[300002];
int main()
{
	scanf("%d%d",&n,&k),ans=-n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pre[i]=(pre[i-1]+a[i])%k;
	for(int i=1;i<=n;++i)
	{
		for(;st_t && a[st[st_t]]<=a[i];--st_t);
		l[i]=st[st_t],st[++st_t]=i;
	}
	st[st_t=0]=n+1;
	for(int i=n;i;--i)
	{
		for(;st_t && a[st[st_t]]<a[i];--st_t);
		r[i]=st[st_t],st[++st_t]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(i-l[i]<=r[i]-i)vecr[i-1].push_back((aaa){l[i]+1,i,-1}),vecr[r[i]-1].push_back((aaa){l[i]+1,i,1});
		else vecl[l[i]].push_back((aaa){i,r[i]-1,-1}),vecl[i].push_back((aaa){i,r[i]-1,1});
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<vecl[i].size();++j)
		{
			tmp=0;
			for(int l=vecl[i][j].l;l<=vecl[i][j].r;++l)ans+=cnt[(tmp+pre[vecl[i][j].l-1])%k]*vecl[i][j].o,(tmp+=a[l+1])%=k;
		}
		++cnt[pre[i]];
		for(int j=0;j<vecr[i].size();++j)
		{
			tmp=0;
			for(int l=vecr[i][j].r;l>=vecr[i][j].l;--l)ans+=cnt[(pre[vecr[i][j].r]+k-tmp)%k]*vecr[i][j].o,(tmp+=a[l-1])%=k;
		}
	}
	return 0&printf("%lld",ans);
}