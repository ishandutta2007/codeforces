#include <bits/stdc++.h>

using namespace std;

const int N=15;
int k;
int n[N];
vector<long long> a[N];
vector<long long> sum(N);
map<long long,int> pos;
long long dist;
vector<bool> dp(1<<N,0);
pair<int,int> res[1<<N][N];

void solve(int now,long long one)
{
    int b=now;
    vector<bool> used(k,0);
    used[now]=1;
    vector<int> chosen(k);
    vector<int> p(k);
    chosen[now]=one;
    while(1)
    {
        long long d=dist-(sum[now]-chosen[now]);
        if(pos.find(d)==pos.end()) return;
        int idx=pos[d];
        if(d==one)
        {
            p[b]=now;
            break;
        }
        if(used[idx]) return;
        used[idx]=1;
        chosen[idx]=d;
        p[idx]=now;
        now=idx;
    }
    int mask=0;
    for(int i=0;i<k;i++) if(used[i]) mask+=(1<<i);
    dp[mask]=1;
    for(int i=0;i<k;i++) if(used[i]) res[mask][i]={chosen[i],p[i]};
}

int main()
{
    scanf("%d",&k);
    long long s=0;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&n[i]);
        a[i].resize(n[i]);
        for(int j=0;j<n[i];j++)
        {
            scanf("%I64d",&a[i][j]);
            pos[a[i][j]]=i;
            sum[i]+=a[i][j];
            s+=a[i][j];
        }
    }
    if((s%k))
    {
        printf("No\n");
        return 0;
    }
    dist=s/k;
    for(int i=0;i<k;i++) for(int j=0;j<n[i];j++) solve(i,a[i][j]);
    for(int o=0;o<(1<<k);o++)
    {
        for(int m=o;m;m=(m-1)&o)
        {
            if(dp[m]&&dp[m^o])
            {
                dp[o]=1;
                for(int t=m;t;t=(t-1)&t) res[o][__builtin_ctz(t)]=res[m][__builtin_ctz(t)];
                for(int t=m^o;t;t=(t-1)&t) res[o][__builtin_ctz(t)]=res[m^o][__builtin_ctz(t)];
            }
        }
    }
    if(dp[(1<<k)-1])
    {
        printf("Yes\n");
        for(int i=0;i<k;i++) printf("%d %d\n",res[(1<<k)-1][i].first,res[(1<<k)-1][i].second+1);
    }
    else printf("No\n");
    return 0;
}