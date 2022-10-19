#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
LL ans=0,t,t1=0,t2,mn;
int tol[10002],tor[10002];
LL h[10002],tmp[10002];
typedef pair<LL,LL> P;
struct aaa
{
	int st_t;
	P st[10002];
	inline void ins(P a)
	{
		for(;st_t && a.second>=st[st_t].second;--st_t);
		st[++st_t]=a;
	}
}L,R;
inline void solve(int l,int r)
{
	t=mn=inf,L.st_t=R.st_t=0;
	for(int i=l;i<=r;++i)mn=min(mn,h[i]);
	for(int i=l-1;i;--i)tmp[i]=t=min(t,h[i]),L.ins(P(t,t*(r-i+1)));
	t=inf;
	for(int i=r+1;i<=n;++i)tmp[i]=t=min(t,h[i]),R.ins(P(t,t*(i-l+1)));
	t=inf;
	for(int i=l-1,j=n;i;--i)
	{
		t=min(t,h[i]);
		for(;j>r && mn-t>tmp[j];--j);
		if(t<=mn)ans=max(ans,t*(r-i+1)+(mn-t)*(j-l+1));
	}
	t=inf;
	for(int i=r+1,j=1;i<=n;++i)
	{
		t=min(t,h[i]);
		for(;j<l && mn-t>tmp[j];++j);
		if(t<=mn)ans=max(ans,t*(i-l+1)+(mn-t)*(r-j+1));
	}
	for(int i=1;i<L.st_t-i+1;++i)swap(L.st[i],L.st[L.st_t-i+1]);
	for(int i=1;i<R.st_t-i+1;++i)swap(R.st[i],R.st[R.st_t-i+1]);
	for(int i=0,j=R.st_t;i<=L.st_t;ans=max(ans,L.st[i].second+R.st[j].second),++i)
	{
		for(;j && L.st[i].first+R.st[j].first>mn;--j);
		if(L.st[i].first+R.st[j].first>mn)break;
	}
	for(int i=1;i<=n;++i)if(tol[i]<l && tor[i]>r)ans=max(ans,h[i]*(tor[i]-tol[i]-1)+(mn-h[i])*(r-l+1));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&h[i]);
	for(int i=1;i<n;++i)
	{
		t=inf,t2=0;
		for(int j=i;j;--j)t=min(t,h[j]),t1=max(t1,t*(i-j+1));
		t=inf;
		for(int j=i+1;j<=n;++j)t=min(t,h[j]),t2=max(t2,t*(j-i));
		ans=max(ans,t1+t2);
	}
	for(int i=1,j,k;i<=n;++i)
	{
		for(j=i;j>1 && h[j-1]>=h[i];--j);
		for(k=i;k<n && h[k+1]>=h[i];++k);
		tol[i]=j-1,tor[i]=k+1;
	}
	for(int i=1;i<=n;++i)solve(tol[i]+1,tor[i]-1);
	return 0&printf("%lld",ans);
}