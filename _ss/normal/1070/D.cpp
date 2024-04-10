#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,x,s=0,flag=0,ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        s+=x;
        if (s/k) flag=0;
        ans+=s/k;
        s%=k;
        if (flag) ans++,s=0,flag=0;
        if (s) flag=1;
    }
    if (s) ans++;
    cout<<ans;
    return 0;
}