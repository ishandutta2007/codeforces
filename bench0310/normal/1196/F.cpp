#include <bits/stdc++.h>

using namespace std;

const int N=200005;
const int K=405;
const long long inf=1000000000000000000;
vector<pair<int,int>> edges;
map<int,int> id;
vector<pair<long long,int>> d;
vector<bool> vis(N,0);
int idx=1;
long long dp[2*K][2*K];

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
    {
        int a,b;
        long long c;
        scanf("%d%d%I64d",&a,&b,&c);
        edges.push_back({a,b});
        d.push_back({c,i});
    }
    sort(d.begin(),d.end());
    for(int o=0;o<2*K;o++) for(int i=0;i<2*K;i++) dp[o][i]=inf;
    for(int i=0;i<min(m,k);i++)
    {
        int a,b;
        tie(a,b)=edges[d[i].second];
        if(vis[a]==0)
        {
            vis[a]=1;
            id.insert({a,idx++});
        }
        if(vis[b]==0)
        {
            vis[b]=1;
            id.insert({b,idx++});
        }
        a=id[a];
        b=id[b];
        dp[a][b]=dp[b][a]=d[i].first;
    }
    for(int k=1;k<idx;k++)
    {
        for(int i=1;i<idx;i++)
        {
            for(int j=1;j<idx;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    vector<long long> v;
    for(int i=1;i<idx;i++) for(int j=i+1;j<idx;j++) v.push_back(dp[i][j]);
    sort(v.begin(),v.end());
    printf("%I64d\n",v[k-1]);
	return 0;
}