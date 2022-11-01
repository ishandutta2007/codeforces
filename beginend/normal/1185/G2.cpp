#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=55;
const int M=2505;
const int MOD=1000000007;

int n,m,h[N][N][N][2],f[4][N][M],g[N][N][M],u[N][N][M],tim[4],jc[N],ny[N];
std::vector<int> vec[4];

void pre_h()
{
	h[1][0][0][0]=h[0][1][0][1]=h[0][0][0][0]=1;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=i+j;k++)
			{
				if (!h[i][j][k][0]) h[i][j][k][0]=((i>0?h[i-1][j][k][1]:0)+(i>1&&k>0?h[i-1][j][k-1][0]:0))%MOD;
				if (!h[i][j][k][1]) h[i][j][k][1]=((j>0?h[i][j-1][k][0]:0)+(j>1&&k>0?h[i][j-1][k-1][1]:0))%MOD;
			}
}

void pre_f()
{
	for (int l=1;l<=3;l++)
	{
		f[l][0][0]=1;
		for (int i=0;i<vec[l].size();i++) tim[l]+=vec[l][i];
		for (int i=0;i<vec[l].size();i++)
			for (int j=i+1;j>=1;j--)
				for (int k=vec[l][i];k<=tim[l];k++)
					(f[l][j][k]+=f[l][j-1][k-vec[l][i]])%=MOD;
	}
}

void pre_g()
{
	for (int i=0;i<=vec[1].size();i++)
	{
		for (int j=0;j<=tim[1];j++) u[i][0][j]=f[1][i][j];
		for (int j=0;j<vec[2].size();j++)
			for (int k=j+1;k>=1;k--)
				for (int l=vec[2][j];l<=tim[1]+tim[2];l++)
					(u[i][k][l]+=u[i][k-1][l-vec[2][j]])%=MOD;
	}
	for (int i=0;i<=vec[1].size();i++)
		for (int j=0;j<=vec[2].size();j++)
			for (int k=0;k<=tim[1]+tim[2];k++)
			{
				if (!u[i][j][k]) continue;
				for (int l=0;l<=i+j;l++)
					(g[i+j][l][k]+=(LL)u[i][j][k]*(h[i][j][l][0]+h[i][j][l][1])%MOD*jc[i]%MOD*jc[j]%MOD)%=MOD;
			}
}

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%d%d",&n,&m);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	pre_h();
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		vec[y].pb(x);
	}
	if (vec[1].size()>vec[2].size()) std::swap(vec[1],vec[2]);
	if (vec[1].size()>vec[3].size()) std::swap(vec[1],vec[3]);
	if (vec[2].size()>vec[3].size()) std::swap(vec[2],vec[3]);
	pre_f();
	pre_g();
	int ans=0;
	for (int i=0;i<=std::min(tim[3],m);i++)
		for (int j=0;j<=vec[3].size();j++)
		{
			if (!f[3][j][i]) continue;
			f[3][j][i]=(LL)f[3][j][i]*jc[j]%MOD;
			for (int k=std::max(0,j-1);k<=vec[1].size()+vec[2].size();k++)
				for (int l=0;l<=std::min(j,k);l++)
				{
					if (!g[k][l][m-i]) continue;
					(ans+=(LL)g[k][l][m-i]*f[3][j][i]%MOD*C(k+1-l,j-l)%MOD)%=MOD;
				}
		}
	printf("%d\n",ans);
	return 0;
}