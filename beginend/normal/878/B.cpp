#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,k,m,a[N],s[N];

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	int tot=0;
	for (int i=1;i<=n;i++)
	{
		tot++;scanf("%d",&a[tot]);
		if (i==1||a[tot]==a[tot-1]) s[tot]=s[tot-1]+1;
		else s[tot]=1;
		if (s[tot]==k) tot-=k;
	}
	n=tot;
	if (m==1) {printf("%d\n",n);return 0;}
	if (s[n]==n) {printf("%lld\n",(LL)n*m%k);return 0;}
	if (k>=n) {printf("%lld\n",(LL)n*m);return 0;}
	int l=1,r=n;LL ans=0,tmp=0;
	while (l<=r)
	{
		int p=l,q=r+1;
		while (a[p+1]==a[l]&&p<r) p++;
		while (a[q-1]==a[l]&&q>p+1) q--;
		if (p+1==q) {ans+=(LL)(r-l+1)*m%k;l=((LL)(r-l+1)*m%k==0)?r+1:l;break;}
		int L=p-l+1+r-q+1;
		if (L<k) {ans+=(LL)(r-l+1)*m;break;}
		if (L>k) {ans+=(LL)(r-l+1)*m-(LL)k*(m-1)*(L/k);break;}
		ans+=k;tmp+=k;l=p+1;r=q-1;
	}
	if (l>r) ans-=tmp;
	printf("%lld\n",ans);
	return 0;
}