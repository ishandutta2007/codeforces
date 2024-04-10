#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=18;
int v[N][N];
ll dp[1<<N][N];
ll g[N+1][1<<N];
ll f[1<<(N-1)];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<n;j++) v[i][j]=(s[j]-'0');
    }
    for(int i=0;i<n;i++) dp[1<<i][i]=1;
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if((i&(1<<k))||v[j][k]==0) continue;
                dp[i|(1<<k)][k]+=dp[i][j];
            }
        }
    }
    auto popcnt=[](int a)->int{return __builtin_popcount(a);};
    for(int i=1;i<(1<<n);i++) for(int j=0;j<n;j++) g[popcnt(i)][i]+=dp[i][j];
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                if((j&(1<<i))==0) continue;
                g[o][j]+=g[o][j^(1<<i)];
            }
        }
    }
    map<vector<int>,ll> partitions;
    for(int o=0;o<(1<<(n-1));o++)
    {
        vector<int> partition;
        int c=1;
        for(int i=0;i<n-1;i++)
        {
            if(o&(1<<i)) c++;
            else
            {
                partition.push_back(c);
                c=1;
            }
        }
        partition.push_back(c);
        sort(partition.begin(),partition.end());
        if(partitions.find(partition)==partitions.end())
        {
            ll res=0;
            for(int i=1;i<(1<<n);i++)
            {
                ll now=1;
                for(int l:partition) now*=g[l][i];
                res+=((((n-popcnt(i))&1)?-1:1)*now);
            }
            partitions[partition]=res;
        }
        f[o]=partitions[partition];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=(1<<(n-1))-1;j>=0;j--)
        {
            if(j&(1<<i)) continue;
            f[j]-=f[j|(1<<i)];
        }
    }
    for(int i=0;i<(1<<(n-1));i++) cout << f[i] << " \n"[i==(1<<(n-1))-1];
    return 0;
}