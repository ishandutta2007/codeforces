#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
const int N=2e5+10;
vector<int> G[N];
int last[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,dis;
    cin>>n>>k;
    if (k==n-1)
    {
        for (int i=2;i<=n;i++) G[1].pb(i);
        dis=2;
    }
    else if (k==n-2)
    {
        dis=3;
        G[1].pb(2);
        for (int i=3;i<=n;i++)
            if (i&1) G[1].pb(i);
            else G[2].pb(i);
    }
    else if (n-1-k<=k)
    {
        dis=4;
        for (int i=1;i<=n-1-k;i++) G[1].pb(i+1);
        for (int i=n-k+1;i<=n;i++) G[i%(n-1-k)+2].pb(i);
    }
    else
    {
        dis=(n-1-k)/k*2+2;
        if ((n-1-k)%k==1) dis++;
        else if ((n-1-k)%k>1) dis+=2;
        for (int i=2;i<=k+1;i++) G[1].pb(i),last[i%k]=i;
        for (int i=k+2;i<=n-k;i++) G[i-k].pb(i),last[i%k]=i;
        for (int i=n-k+1;i<=n;i++) G[last[i%k]].pb(i);
    }
    cout<<dis<<"\n";
    for (int i=1;i<=n;i++)
        for (int x : G[i]) cout<<i<<" "<<x<<"\n";
    return 0;
}