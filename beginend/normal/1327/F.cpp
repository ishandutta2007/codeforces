#include<bits/stdc++.h>
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=500005;
const int MOD=998244353;

int n,k,m,tag[N],f[N],s[N],bin[35];
pi it[N],tmp[N];
struct data{int l,r,x;}a[N];

int solve(int now)
{
	memset(tag,0,sizeof(tag));
	int tot=0;
	for (int i=1;i<=m;i++)
		if (!(a[i].x&bin[now])) it[++tot]=mp(a[i].l,a[i].r);
		else tag[a[i].l]++,tag[a[i].r+1]--;
	for (int i=1;i<=n;i++) tag[i]+=tag[i-1];
	std::sort(it+1,it+tot+1);
	int top=0;
	for (int i=1;i<=tot;i++) if (it[i].first!=it[i-1].first) tmp[++top]=it[i];
	tot=top;
	for (int i=1;i<=top;i++) it[i]=tmp[i];
	int mn=n+1;top=0;
	for (int i=tot;i>=1;i--) if (it[i].second<mn) mn=it[i].second,tmp[++top]=it[i];
	tot=top;
	for (int i=1;i<=top;i++) it[i]=tmp[top-i+1];
	memset(f,0,sizeof(f));
	int ls=0;
	s[0]=f[0]=1;
	for (int i=1;i<=n;i++)
	{
		while (ls<tot&&it[ls+1].second<i) ls++;
		s[i]=s[i-1];
		if (tag[i]) continue;
		if (!ls) f[i]=s[i-1];
		else f[i]=(s[i-1]+MOD-s[it[ls].first-1])%MOD;
		(s[i]+=f[i])%=MOD;
	}
	int ans=s[n];
	if (tot) (ans+=MOD-s[it[tot].first-1])%=MOD;
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	bin[0]=1;
	for (int i=1;i<=k;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
	int ans=1;
	for (int i=0;i<k;i++) ans=(LL)ans*solve(i)%MOD;
	printf("%d\n",ans);
	return 0;
}