#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
const ll mod=998244353;
vector<int> v[N];
vector<ll> res(N,1);

void dfs(int a,int p=-1)
{
    ll cnt=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        res[a]=(res[a]*(cnt++))%mod;
        res[a]=(res[a]*res[to])%mod;
    }
    if(p!=-1) res[a]=(res[a]*cnt)%mod;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    printf("%I64d\n",(res[1]*n)%mod);
    return 0;
}