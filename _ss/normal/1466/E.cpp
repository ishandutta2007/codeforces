#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=5e5+10;
const ll mod=1e9+7;
ll a[N],cnt[100];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=0;i<60;i++) cnt[i]=0;
        ll sum=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            for (int j=0;j<60;j++)
                if ((a[i]>>j)&1) cnt[j]=(cnt[j]+((ll)1<<j))%mod;
            sum=(sum+a[i])%mod;
        }
        ll res=0;
        for (int i=1;i<=n;i++)
        {
            ll r=0;
            for (int j=0;j<60;j++)
                if ((a[i]>>j)&1) r=(r+cnt[j])%mod;
            res=(res+r*((a[i]%mod*n%mod+sum-r+mod)%mod))%mod;
        }
        cout<<res<<"\n";
    }
    return 0;
}