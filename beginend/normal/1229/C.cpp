#include<bits/stdc++.h>
#define pb push_back

typedef long long LL;

const int N=100005;

int n,m,a[N],s[N][2],q;
LL ans;
std::vector<int> vec[N];

void modify(int x)
{
	ans-=(LL)s[x][0]*s[x][1];
	s[x][0]--;s[x][1]++;
	ans+=(LL)s[x][0]*s[x][1];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (x>y) vec[y].pb(x),s[y][1]++,s[x][0]++;
		else vec[x].pb(y),s[x][1]++,s[y][0]++;
	}
	for (int i=1;i<=n;i++) ans+=(LL)s[i][0]*s[i][1];
	printf("%lld\n",ans);
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		int x;scanf("%d",&x);
		ans-=(LL)s[x][0]*s[x][1];
		for (int j=0;j<vec[x].size();j++) vec[vec[x][j]].pb(x),modify(vec[x][j]);
		vec[x].clear();
		s[x][0]+=s[x][1];s[x][1]=0;
		printf("%lld\n",ans);
	}
	return 0;
}