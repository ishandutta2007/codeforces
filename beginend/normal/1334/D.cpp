#include<bits/stdc++.h>

typedef long long LL;

int n;
LL l,r;

void solve(int now,int pos,int op,int ret)
{
	if (!ret) return;
	if (now==n) printf("%d ",1);
	else if (!op) printf("%d ",now);
	else printf("%d ",now+pos);
	if (!op) solve(now,pos,op+1,ret-1);
	else if (pos<(n-now)) solve(now,pos+1,0,ret-1);
	else solve(now+1,1,0,ret-1);
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lld%lld",&n,&l,&r);
		if (l==(LL)n*(n-1)+1)
		{
			puts("1");
			continue;
		}
		int now=1;LL s=0;
		while (s+(n-now)*2<l) s+=(n-now)*2,now++;
		if ((l-s)&1) solve(now,(l-s)/2+1,0,r-l+1);
		else solve(now,(l-s)/2,1,r-l+1);
		puts("");
	}
	return 0;
}