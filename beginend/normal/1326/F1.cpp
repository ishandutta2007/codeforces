#include<bits/stdc++.h>
#define pb push_back

typedef long long LL;

const int N=23;
const int M=300005;

int n,bin[N],a[N][N],cnt[M];
LL dp[N][M],f[M],g[N][M],d[N][M];
std::map<int,LL> ma;

void pre()
{
	for (int i=1;i<=n;i++) dp[i][bin[i-1]]=1;
	for (int i=1;i<bin[n];i++)
		for (int j=1;j<=n;j++)
			if (dp[j][i])
			{
				g[cnt[i]][i]+=dp[j][i];
				for (int k=1;k<=n;k++)
					if (!(i&bin[k-1])&&a[j][k]) dp[k][i+bin[k-1]]+=dp[j][i];
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<bin[n];k++)
				if (k&bin[j-1]) g[i][k]+=g[i][k^bin[j-1]];
}

void calc(int dep,LL sta)
{
	LL w=0;
	for (int i=0;i<bin[n];i++)
		if ((n-cnt[i])&1) w-=d[dep][i];
		else w+=d[dep][i];
	ma[sta]=w;
}

void dfs(int mx,int sum,int used,int dep,LL sta)
{
	if (sum==n) {calc(dep,sta);return;}
	if (sum+mx>n) return;
	for (int i=0;i<bin[n];i++) d[dep+1][i]=d[dep][i]*g[mx][i];
	dfs(mx,sum+mx,used+1,dep+1,sta*10+mx);
	dfs(mx+1,sum,0,dep,sta);
}

LL get_sta(int x)
{
	std::vector<int> vec;
	int s=0;
	for (int i=0;i<n;i++)
		if (x&bin[i]) s++;
		else vec.pb(s+1),s=0;
	std::sort(vec.begin(),vec.end());
	LL sta=0;
	for (int i=0;i<vec.size();i++) sta=sta*10+vec[i];
	return sta;
}

void solve()
{
	for (int i=0;i<bin[n-1];i++) f[i]=ma[get_sta(i)];
	for (int i=1;i<n;i++)
		for (int j=0;j<bin[n-1];j++)
			if (!(j&bin[i-1])) f[j]-=f[j^bin[i-1]];
	for (int i=0;i<bin[n-1];i++) printf("%lld ",f[i]);
}

int main()
{
	scanf("%d",&n);
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<bin[n];i++) cnt[i]=cnt[i^(i&(-i))]+1;
	for (int i=1;i<=n;i++)
	{
		char str[N];
		scanf("%s",str+1);
		for (int j=1;j<=n;j++) a[i][j]=str[j]-'0';
	}
	pre();
	for (int i=0;i<bin[n];i++) d[0][i]=1;
	dfs(1,0,0,0,0);
	solve();
	return 0;
}