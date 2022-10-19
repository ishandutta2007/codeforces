#include<bits/stdc++.h>
using namespace std;
const int mod=19260817,mod1=19491001,mod2=19368913;
int n,res=1,ans=1;
int h[500002],h1[500002],h2[500002];
char s[500002];
bitset<mod> bs;
bitset<mod1> bs1;
bitset<mod2> bs2;
bitset<500002> f[2];
int main()
{
	scanf("%d",&n),scanf("%s",s+1);
	for(int i=1;i<=n;++i)h[i]=h1[i]=h2[i]=(s[i]-='a'),f[0][i]=1;
	for(int i=2,i0=0,i1=1;(res+=i)<=n;++i,i0^=1,i1^=1)
	{
		bs.reset(),bs1.reset(),bs2.reset(),f[i1].reset();
		for(int j=n-res+1;j;--j)
		{
			if(f[i0][j+i])bs[h[j+i]]=bs1[h1[j+i]]=bs2[h2[j+i]]=1;
			if((bs[h[j]] && bs1[h1[j]] && bs2[h2[j]]) || (bs[h[j+1]] && bs1[h1[j+1]] && bs2[h2[j+1]]))f[i1][j]=1,ans=i;
		}
		if(ans!=i)break;
		for(int j=1;j<=n-res+1;++j)h[j]=(h[j]*26+s[j+i-1])%mod,h1[j]=(h1[j]*26+s[j+i-1])%mod1,h2[j]=(h2[j]*26+s[j+i-1])%mod2;
	}
	printf("%d",ans);
	return 0;
}