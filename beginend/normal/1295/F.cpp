#include<bits/stdc++.h>

typedef long long LL;

const int N=105;
const int MOD=998244353;

int n,l[N],r[N],w[N],tot,inv[N],f[N][N][N],s[N][N];

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&r[i],&l[i]);
		l[i]=MOD-l[i];r[i]=MOD-r[i];
		r[i]++;
		w[++tot]=l[i];w[++tot]=r[i];
	}
	std::sort(w+1,w+tot+1);
	tot=std::unique(w+1,w+tot+1)-w-1;
	inv[0]=inv[1]=1;
	for (int i=2;i<=n*2;i++) inv[i]=(LL)(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=n;i++)
	{
		l[i]=std::lower_bound(w+1,w+tot+1,l[i])-w;
		r[i]=std::lower_bound(w+1,w+tot+1,r[i])-w;
	}
	f[0][0][0]=1;
	s[0][0]=1;
	for (int i=1;i<tot;i++) s[0][i]+=s[0][i-1];
	for (int i=1;i<=n;i++)
	{
		for (int j=l[i];j<r[i];j++)
		{
			int L=w[j+1]-w[j];
			f[i][j][1]=(LL)s[i-1][j-1]*L%MOD;
			for (int k=2;k<=i;k++)
				f[i][j][k]=(LL)f[i-1][j][k-1]*(L+k-1)%MOD*inv[k]%MOD;
			for (int k=1;k<=i;k++) (s[i][j]+=f[i][j][k])%=MOD;
		}
		for (int j=1;j<tot;j++) (s[i][j]+=s[i][j-1])%=MOD;
	}
	int ans=s[n][tot-1];
	for (int i=1;i<=n;i++) ans=(LL)ans*ksm(w[r[i]]-w[l[i]],MOD-2)%MOD;
	printf("%d\n",ans);
	return 0;
}