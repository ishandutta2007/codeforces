#include<bits/stdc++.h>

typedef long long LL;

const int N=500005;

int n,m,fro_nx[N],s[N],a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),m=std::max(m,a[i]),s[a[i]]++;
	for (int i=1;i<=m;i++)
		if (s[i]) fro_nx[i]=i;
		else fro_nx[i]=fro_nx[i-1];
	for (int i=1;i<=m;i++) s[i]+=s[i-1];
	LL ans=0;
	for (int y=2;y<=m;y++)
	{
		LL cnt=0;
		for (int j=y;j<=m;j+=y)
			cnt+=(LL)(j/y)*(s[std::min(j+y-1,m)]-s[j-1]);
		int mx=-1;
		for (int j=m-m%y;j>=0;j-=y)
		{
			int x=fro_nx[std::min(m,j+y-1)];
			if (x>=j) mx=std::max(mx,x%y);
			if (mx<0) continue;
			if (std::min(cnt-j/y,(LL)(mx+j)/2)>1) ans=std::max(ans,(LL)y*std::min(cnt-j/y,(LL)(mx+j)/2));
		}
		int mx1=-1,mx2=-1,pos;
		for (int j=m-m%y;j>=0;j-=y)
		{
			int x=fro_nx[std::min(m,j+y-1)],w=(x>0&&s[x]-s[x-1]>1)?x:fro_nx[std::max(0,x-1)];
			if (x>=j)
			{
				if (x%y>mx1) mx2=mx1,mx1=x%y,pos=x;
				else if (x%y>mx2) mx2=x%y;
				if (x%y==mx1) pos=x;
			}
			if (w>=j&&w%y>mx2) mx2=w%y;
			if (mx2<0) continue;
			if (std::min((LL)(mx2+j),cnt-j/y*2)>1) ans=std::max(ans,(LL)y*std::min((LL)(mx2+j),cnt-j/y*2));
			if (pos>=j+y&&s[m]-s[std::min(m,j+y-1)]>=2||pos<j+y&&s[m]-s[std::min(m,j+y-1)]>=1&&std::min((LL)(mx1+j),cnt-j/y*2-1)>1)
				ans=std::max(ans,(LL)y*std::min((LL)(mx1+j),cnt-j/y*2-1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}