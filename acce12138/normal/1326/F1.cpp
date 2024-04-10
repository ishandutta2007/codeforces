#include<bits/stdc++.h>
using namespace std;
#define getcode(i,j) (((i)>>(j))&1)
int con[18][18],n;
int dpl[1<<14][14][1<<6], dpr[1<<14][14][1<<6];
long long ans[1<<17];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char s[111];
		scanf("%s",s);
		for(int j=0;j<n;j++)con[i][j]=s[j]-'0';
	}
	for(int i=0;i<n;i++)dpl[1<<i][i][0]=dpr[1<<i][i][0]=1;
	int vl = n/2, vr = n-vl;
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) if(getcode(i,j))
	{
		int cnt = __builtin_popcount(i);
		if(cnt >= vr) continue;
		for(int k=0;k<(1<<cnt-1);k++)
		{
			for(int nxt=0;nxt<n;nxt++)if(!getcode(i,nxt))
			{
				dpl[i^(1<<nxt)][nxt][k | (con[j][nxt]<<cnt-1)] += dpl[i][j][k];
				dpr[i^(1<<nxt)][nxt][(k<<1)|con[j][nxt]] += dpr[i][j][k];
			}
		}
	}
	for(int p=0;p<n;p++)for(int q=0;q<n;q++)if(p!=q)
	{
		for(int msk=0;msk<(1<<n);msk++)
		{
			if(!getcode(msk,p))continue;
			if(getcode(msk,q))continue;
			if(__builtin_popcount(msk)!=vl)continue;
			int msk2=((1<<n)-1)^msk;
			for(int i=0;i<(1<<vl-1);i++) for(int j=0;j<(1<<vr-1);j++) ans[i | (con[p][q]<<vl-1) | (j<<vl)] += 1ll * dpl[msk][p][i] * dpr[msk2][q][j];
		}
	}
	for(int i=0; i<(1<<n-1);i++) printf("%lld ", ans[i]);
	return 0;
}