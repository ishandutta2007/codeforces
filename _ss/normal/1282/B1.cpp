#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;
ll a[N],n,p,k;

void read()
{
    cin>>n>>p>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void process()
{
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        if (i>=k) a[i]+=a[i-k];
        else a[i]+=a[i-1];
    int res=0;
    for (int i=1;i<=n;i++)
        if (a[i]<=p) res=i;
    cout<<res<<"\n";
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