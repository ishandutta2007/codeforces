#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp std::make_pair
#define pb push_back
 
typedef long long LL;
typedef std::pair<int,int> pi;
 
const int N=1005;
const int MOD=998244353;
 
int n,a[N],g[5][5],id[5][5][5],ans[N][5],f[N][5],ss[60],tt[60],tot,m;
struct data{int x,y,z;}bel[N];
std::vector<pi> col[N];
struct Matrix
{
	int a[60][60];
	void clear() {for (int i=1;i<=tot;i++) for (int j=1;j<=tot;j++) a[i][j]=0;}
	void unit(int n) {clear();for (int i=1;i<=n;i++) a[i][i]=1;}
}trs[35];
 
int get_sg(int s1,int s2,int s3,int c)
{
	int w[5]={0,0,0,0,0};
	if (g[c][1]) w[s3]=1;
	if (g[c][2]) w[s2]=1;
	if (g[c][3]) w[s1]=1;
	for (int i=0;;i++) if (!w[i]) return i;
}

Matrix mul(Matrix a,Matrix b)
{
	Matrix c;c.clear();
	for (int k=1;k<=tot;k++)
		for (int i=1;i<=tot;i++)
			for (int j=1;j<=tot;j++)
				(c.a[i][j]+=(LL)a.a[i][k]*b.a[k][j]%MOD)%=MOD;
	return c;
}
 
void ksm(int *a,int y)
{
	if (!y) return;
	for (int i=30;i>=0;i--) if (y&(1<<i))
	{
		memset(ss,0,sizeof(ss));
		for (int j=1;j<=tot;j++)
			for (int k=1;k<=tot;k++)
				(ss[j]+=(LL)trs[i].a[k][j]*a[k]%MOD)%=MOD;
		for (int j=1;j<=tot;j++) a[j]=ss[j];
	}
}
 
void pre()
{
	id[4][4][4]=++tot;
	bel[1]=(data){4,4,4};
	for (int i=1;i<=tot;i++)
	{
		int s1=bel[i].x,s2=bel[i].y,s3=bel[i].z;
		for (int j=1;j<=3;j++)
		{
			int s4=get_sg(s1,s2,s3,j);
			if (!id[s2][s3][s4]) id[s2][s3][s4]=++tot,bel[tot]=(data){s2,s3,s4};
		}
	}
	for (int i=1;i<=tot;i++)
	{
		int s1=bel[i].x,s2=bel[i].y,s3=bel[i].z;
		for (int j=1;j<=3;j++)
		{
			int s4=get_sg(s1,s2,s3,j);
			trs[0].a[i][id[s2][s3][s4]]++;
		}
	}
	for (int i=1;i<=30;i++) trs[i]=mul(trs[i-1],trs[i-1]);
}
 
void work(int p)
{
	std::sort(col[p].begin(),col[p].end());
	memset(tt,0,sizeof(tt));
	tt[1]=1;
	int ls=0;
	col[p].pb(mp(a[p]+1,-1));
	for (int i=0;i<col[p].size();i++)
	{
		int x=col[p][i].first,y=col[p][i].second;
		ksm(tt,x-ls-1);
		if (y==-1) break;
		memset(ss,0,sizeof(ss));
		for (int j=1;j<=tot;j++)
		{
			int s1=bel[j].x,s2=bel[j].y,s3=bel[j].z,s4=get_sg(s1,s2,s3,y);
			(ss[id[s2][s3][s4]]+=tt[j])%=MOD;
		}
		for (int j=1;j<=tot;j++) tt[j]=ss[j];
		ls=x;
	}
	for (int i=1;i<=tot;i++) (f[p][bel[i].z]+=tt[i])%=MOD;
}
 
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		col[x].pb(mp(y,c));
	}
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			scanf("%d",&g[i][j]);
	pre();
	for (int i=1;i<=n;i++) work(i);
	ans[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=3;j++)
			for (int k=0;k<=3;k++)
				(ans[i][j]+=(LL)ans[i-1][j^k]*f[i][k]%MOD)%=MOD;
	printf("%d\n",ans[n][0]);
	return 0;
}