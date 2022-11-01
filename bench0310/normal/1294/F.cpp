#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
int dp[N][3];
array<int,3> id[N][3];
int best=0;
array<int,3> res;

void dfs(int a,int p=-1)
{
    vector<pair<int,int>> one;
    vector<pair<int,int>> two;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        one.push_back({dp[to][1]+1,to});
        if(dp[to][2]>0) two.push_back({dp[to][2]+1,to});
    }
    sort(one.begin(),one.end(),greater<pair<int,int>>());
    sort(two.begin(),two.end(),greater<pair<int,int>>());
    id[a][1][0]=a;
    if(!one.empty())
    {
        dp[a][1]=one[0].first;
        id[a][1][0]=id[one[0].second][1][0];
    }
    if(one.size()>=2)
    {
        dp[a][2]=one[0].first+one[1].first;
        id[a][2][0]=id[one[0].second][1][0];
        id[a][2][1]=id[one[1].second][1][0];
    }
    if(two.size()>=1&&two[0].first>dp[a][2])
    {
        dp[a][2]=two[0].first;
        id[a][2][0]=id[two[0].second][2][0];
        id[a][2][1]=id[two[0].second][2][1];
    }
    if(dp[a][2]>best)
    {
        best=dp[a][2];
        res={id[a][2][0],id[a][2][1],a};
    }
    if(one.size()>=3&&one[0].first+one[1].first+one[2].first>best)
    {
        best=one[0].first+one[1].first+one[2].first;
        res={id[one[0].second][1][0],id[one[1].second][1][0],id[one[2].second][1][0]};
    }
    for(int o=0;o<min(2,(int)one.size());o++)
    {
        for(int i=0;i<min(2,(int)two.size());i++)
        {
            if(one[o].second==two[i].second) continue;
            if(one[o].first+two[i].first>best)
            {
                best=one[o].first+two[i].first;
                res={id[one[o].second][1][0],id[two[i].second][2][0],id[two[i].second][2][1]};
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> d(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
        d[a]++;
        d[b]++;
    }
    if(d[1]>1) dfs(1);
    else if(d[2]>1) dfs(2);
    else dfs(3);
    printf("%d\n%d %d %d\n",best,res[0],res[1],res[2]);
    return 0;
}