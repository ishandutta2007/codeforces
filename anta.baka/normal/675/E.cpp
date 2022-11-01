#include <bits/stdc++.h>
using namespace std;
const long long INF=(long long)2e12;
const int N=100000;
int n, a[N];
long long dp[N];
vector<long long> tr(2*N,INF);

long long get_min(int l, int r)
{
    long long res=INF;
    for(l+=n, r+=n; l<=r; l=(l+1)>>1, r=(r-1)>>1)
    {
        if(l&1) res=min(res,tr[l]);
        if(!(r&1)) res=min(res,tr[r]);
    }
    return res;
}

void update(int pos, long long val)
{
    tr[pos+=n]=val;
    for(pos>>=1; pos; pos>>=1)
        tr[pos]=min(tr[pos*2],tr[pos*2+1]);
}

int main()
{
    cin>>n;
    for(int i=0; i<n-1; i++)
        cin>>a[i], a[i]--;
    a[n-1]=n-1;
    dp[n-1]=0;
    update(n-1,n-1);
    long long ans=0;
    for(int i=n-2; i>=0; i--)
    {
        ans+=(dp[i]=get_min(i+1,a[i])+n-i-1-a[i]);
        update(i,dp[i]+i);
    }
    cout<<ans;
    return 0;
}