#include<bits/stdc++.h>
using namespace std;
int n,m=200;
int cnt[262152],sa[262152],id[262152],rk[262152],oldrk[262152],px[262152];
char s[262152];
inline bool cmp(int x,int y,int l)
{
	return oldrk[x]==oldrk[y] && oldrk[x^l]==oldrk[y^l];
}
int main()
{
	scanf("%d%s",&n,s),n=(1<<n)-1;
	for(int i=0;i<=n;++i)++cnt[rk[i]=s[i]];
	for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
	for(int i=n;~i;--i)sa[--cnt[rk[i]]]=i;
	for(int l=1,p=0;l<=n && p<=n;l<<=1,m=p)
	{
		p=-1;
		for(int i=0;i<=n;++i)id[++p]=(sa[i]^l);
		for(int i=0;i<=m;++i)cnt[i]=0;
		for(int i=0;i<=n;++i)++cnt[px[i]=rk[id[i]]];
		for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
		for(int i=n;~i;--i)sa[--cnt[px[i]]]=id[i];
		for(int i=0;i<=n;++i)oldrk[i]=rk[i];
		rk[sa[0]]=p=0;
		for(int i=1;i<=n;++i)rk[sa[i]]=cmp(sa[i],sa[i-1],l)? p:(++p);
	}
	for(int i=0;i<=n;++i)putchar(s[i^sa[0]]);
	return 0;
}