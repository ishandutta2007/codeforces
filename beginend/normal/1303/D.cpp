#include<bits/stdc++.h>

typedef long long LL;

int m;
LL n,bin[55],s[105];

bool work(int x,LL ned)
{
	if (x<0) return 0;
	LL tmp=std::min(ned,s[x]);
	s[x]-=tmp;ned-=tmp;
	if (!ned) return 1;
	if (work(x-1,ned*2)) return 1;
	s[x]+=tmp;
	return 0;
}

int main()
{
	bin[0]=1;
	for (int i=1;i<=50;i++) bin[i]=bin[i-1]*2;
	int T;scanf("%d",&T);
	while (T--)
	{
		int ans=0;
		memset(s,0,sizeof(s));
		scanf("%lld%d",&n,&m);
		for (int i=1;i<=m;i++)
		{
			int x;scanf("%d",&x);
			int id=std::lower_bound(bin,bin+51,x)-bin;
			s[id]++;
		}
		LL sum=0;
		for (int i=0;i<=50;i++)
			if (bin[i]<=n) sum+=(LL)s[i]*bin[i];
		if (sum<n)
		{
			int pos=0;
			for (int i=0;i<=50;i++)
				if (bin[i]>n&&s[i]) {pos=i;break;}
			if (!pos) {puts("-1");continue;}
			while (bin[pos]>n) pos--,ans++;
			if (sum+bin[pos]<n) s[pos]=2;
			else s[pos]=1;
			for (int i=pos+1;i<=50;i++) s[i]=0;
		}
		for (int i=0;i<=50;i++)
			if (n&bin[i])
			{
				if (work(i,1)) continue;
				for (int j=i+1;j<=50;j++)
					if (s[j]) {s[j]--;ans+=j-i;i=j-1;break;}
			}
		printf("%d\n",ans);
	}
	return 0;
}