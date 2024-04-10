#include <bits/stdc++.h>

using namespace std;

const int N=500005;
vector<int> v[N];
vector<pair<int,long long>> g[N];
long long w[N];
long long dp[N][2];
int k;

void dfs(int a,int p=-1)
{
    for(pair<int,long long> e:g[a])
    {
        int to=e.first;
        if(to==p) continue;
        w[to]=e.second;
        dfs(to,a);
    }
    vector<long long> t;
    long long res=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        res+=dp[to][1];
        if(dp[to][0]+w[to]>dp[to][1]) t.push_back(dp[to][0]+w[to]-dp[to][1]);
    }
    sort(t.begin(),t.end(),greater<long long>());
    dp[a][0]=res;
    for(int i=0;i<min(k-1,(int)t.size());i++) dp[a][0]+=t[i];
    dp[a][1]=dp[a][0];
    if((int)t.size()>=k) dp[a][1]+=t[k-1];
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            long long c;
            scanf("%d%d%I64d",&a,&b,&c);
            v[a].push_back(b);
            v[b].push_back(a);
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        dfs(1);
        printf("%I64d\n",dp[1][1]);
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            g[i].clear();
            w[i]=0;
            dp[i][0]=dp[i][1]=0;
        }
    }
	return 0;
}