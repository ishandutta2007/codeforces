#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        pos[p]=i;
    }
    vector<int> v;
    long long sum=0;
    for(int i=n;i>=n-k+1;i--)
    {
        v.push_back(pos[i]);
        sum+=i;
    }
    sort(v.begin(),v.end());
    const long long mod=998244353;
    long long res=1;
    for(int i=0;i<k-1;i++)
    {
        long long x=v[i+1]-v[i];
        res=(res*x)%mod;
    }
    printf("%I64d %I64d\n",sum,res);
    return 0;
}