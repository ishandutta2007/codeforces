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
const int N=1e6+10;
ll a[N],n,val[N],cnt[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        ll x=a[i],d=0;
        while (x%2==0) x/=2,d++;
        val[i]=d;
        cnt[d]++;
    }
    int t=0;
    for (int i=1;i<=70;i++)
        if (cnt[i]>cnt[t]) t=i;
    cout<<n-cnt[t]<<"\n";
    for (int i=1;i<=n;i++)
        if (val[i]!=t) cout<<a[i]<<" ";
    return 0;
}