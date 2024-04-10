#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=3e6+10;
int h,g,n,m,a[N],dp[N];

void read()
{
    cin>>h>>g;
    n=(1<<h)-1;
    m=(1<<g)-1;
    for (int i=1;i<=n*2+1;i++) dp[i]=a[i]=0;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void f(int i)
{
    int l=i*2,r=l+1;
    if (a[l]==0 && a[r]==0) a[i]=0;
    else if (a[l]>a[r]) a[i]=a[l],f(l);
    else a[i]=a[r],f(r);
    if (a[l]==0 && a[r]==0) dp[i]=i;
    else if (a[l]>a[r]) dp[i]=dp[l];
    else dp[i]=dp[r];
}

vector<int> ans;

void solve(int x)
{
    while (dp[x]>m) f(x),ans.pb(x);
    if (a[x*2]) solve(x*2);
    if (a[x*2+1]) solve(x*2+1);
}

void process()
{
    ans.clear();
    for (int i=n;i;i--)
    {
        int l=i*2,r=l+1;
        if (a[l]==0 && a[r]==0) dp[i]=i;
        else if (a[l]>a[r]) dp[i]=dp[l];
        else dp[i]=dp[r];
    }
    solve(1);
    ll res=0;
    for (int i=1;i<=m;i++) res=res+a[i];
    cout<<res<<"\n";
    for (int x : ans) cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}