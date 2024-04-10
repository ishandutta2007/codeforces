#include <bits/stdc++.h>

using namespace std;

int main()
{
	const long long mod=998244353;
    int n,m;
	scanf("%d%d",&n,&m);
	vector<int> a(m);
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	vector<int> b;
	for(int i=0;i<m;i++) if(b.empty()||b.back()!=a[i]) b.push_back(a[i]);
	m=b.size();
	if(m>2*n)
    {
        printf("0\n");
        return 0;
    }
	vector<int> p[n+1];
	for(int i=1;i<=m;i++) p[b[i-1]].push_back(i);
	int id[m+1][m+1];
	for(int i=0;i<=m;i++) id[i][i]=n+1;
    for(int o=0;o<=m;o++)
    {
        for(int i=o+1;i<=m;i++)
        {
            id[o][i]=min(id[o][i-1],b[i-1]);
        }
    }
    long long dp[m+1][m+1];
    for(int i=0;i<=m;i++) dp[i][i]=1;
    for(int o=1;o<=m;o++)
    {
        for(int i=0;i+o<=m;i++)
        {
            int l=i,r=i+o;
            int s=p[id[l][r]][0];
            int t=p[id[l][r]].back();
            if(s<=l||r<t)
            {
                dp[l][r]=0;
                continue;
            }
            long long one=0,two=0;
            for(int j=l;j<s;j++) one=(one+dp[l][j]*dp[j][s-1])%mod;
            for(int j=t;j<=r;j++) two=(two+dp[t][j]*dp[j][r])%mod;
            dp[l][r]=(one*two)%mod;
            for(int i=0;i<(int)p[id[l][r]].size()-1;i++) dp[l][r]=(dp[l][r]*dp[p[id[l][r]][i]][p[id[l][r]][i+1]-1])%mod;
        }
    }
    printf("%I64d\n",dp[0][m]);
	return 0;
}