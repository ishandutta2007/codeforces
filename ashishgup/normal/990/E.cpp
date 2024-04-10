#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e6+5;

int n, m, k, ans=1e15;
int s[N], a[N], f[N], previous[N];

int work(int k)
{
    int x=0, cur=0;
    while(x<n)
    {
        cur+=a[k];
        int nxt=x+k;
        if(f[nxt]==1)
        {
            if(nxt-previous[nxt]>=k)
            {
                return 1e15;
            }
            nxt=previous[nxt];
        }
        x=nxt;
    }
    return cur;
}

int32_t main()
{
    IOS;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>s[i];
        f[s[i]]++;
    }
    if(f[0]==1)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=1;i<N;i++)
    {
        if(f[i]==0)
            previous[i]=i;
        else
            previous[i]=previous[i-1];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        ans=min(ans, work(i));
    }
    if(ans>1e12)
        ans=-1;
    cout<<ans;
    return 0;
}