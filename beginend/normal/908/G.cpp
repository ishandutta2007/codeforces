#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=705;
const int MOD=1000000007;

int n,f[N][N][2],g[15][N],pre[N],a[N];
char str[N];

void solve(int now)
{
	memset(f,0,sizeof(f));
	f[0][0][1]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++)
		{
			if (f[i][j][0])
			{
				for (int k=0;k<=now;k++) (f[i+1][j+1][0]+=f[i][j][0])%=MOD;
				for (int k=now+1;k<=9;k++) (f[i+1][j][0]+=f[i][j][0])%=MOD;
			}
			if (f[i][j][1])
			{
				for (int k=0;k<a[i+1];k++)
					if (k<=now) (f[i+1][j+1][0]+=f[i][j][1])%=MOD;
					else (f[i+1][j][0]+=f[i][j][1])%=MOD;
				if (a[i+1]<=now) (f[i+1][j+1][1]+=f[i][j][1])%=MOD;
				else (f[i+1][j][1]+=f[i][j][1])%=MOD;
			}
		}
	for (int i=0;i<n;i++) g[now+1][i+1]=(f[n][i][0]+f[n][i][1])%MOD,(g[now+1][i+1]+=g[now+1][i])%=MOD;
}

void calc()
{
	int ans=0;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=n;j++)
			(ans+=(LL)i*pre[j]%MOD*(g[i][j]-g[i+1][j])%MOD)%=MOD;
	ans+=ans<0?MOD:0;
	printf("%d\n",ans);
}

int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for (int i=1;i<=n;i++) a[i]=str[i]-'0';
	pre[1]=1;
	for (int i=2;i<=n;i++) pre[i]=(LL)pre[i-1]*10%MOD;
	std::reverse(pre+1,pre+n+1);
	for (int i=0;i<9;i++) solve(i);
	calc();
	return 0;
}