#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const LL mod = 1000000007;

int T,n,m;
LL f[17][2][2];
int l[17],r[17];
char a[17],b[17];
LL sol(int *arr,int tag)
{
	LL ans=0;
	for (int maxnum=1;maxnum<16;maxnum++)
	{
		memset(f,0,sizeof f);
		f[16][0][0]=1;
		for (int i=16;i>=1;i--)
		for (int j=1;j>=0;j--)
		for (int k=1;k>=0;k--)
		if (LL v=f[i][j][k]) {
			int l=4*(i-1),r=4*(i-1)+3;
			for (int x=0;x<=maxnum;x++)
			{
				int nj=j||(x<arr[i-1]);
				int nk=k||(x==maxnum);
				if (x>arr[i-1]&&!j) continue;
				if (l<=maxnum&&maxnum<=r) {
					int p=(x>>(maxnum-l))&1;
					if (p) f[i-1][nj][nk]+=v;
				}
				else f[i-1][nj][nk]+=v;
			}
		}
		ans+=f[0][1][1];
		if (!tag) ans+=f[0][0][1];
	}
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif
	scanf("%d",&T);
	for (int i=1;i<=T;i++) {
		scanf("%s %s",a+1,b+1);
		n=strlen(a+1);m=strlen(b+1);
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		for (int i=1;i<=n;i++)
			l[n-i]=(a[i]>='0'&&a[i]<='9'?a[i]-'0':a[i]-'a'+10);
		for (int i=1;i<=m;i++)
			r[m-i]=(b[i]>='0'&&b[i]<='9'?b[i]-'0':b[i]-'a'+10);
		printf("%lld\n",sol(r,0)-sol(l,1));
	}
	return 0;
}