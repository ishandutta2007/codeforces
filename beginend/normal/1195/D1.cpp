#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=998244353;

int n,len[N],a[N][15],pow[25],cnt[15];

int main()
{
	pow[0]=1;
	for (int i=1;i<=20;i++) pow[i]=(LL)pow[i-1]*10%MOD;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		while (x) a[i][++len[i]]=x%10,x/=10;
		cnt[len[i]]++;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=len[i];j++)
			for (int k=1;k<=10;k++)
			{
				int pos;
				if (k<=j) pos=k+j;
				else pos=j*2;
				(ans+=(LL)pow[pos-1]*a[i][j]%MOD*cnt[k]%MOD)%=MOD;
				if (k<j) pos=k+j;
				else pos=j*2-1;
				(ans+=(LL)pow[pos-1]*a[i][j]%MOD*cnt[k]%MOD)%=MOD;
			}
	printf("%d\n",ans);
	return 0;
}