#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e6+10,mod=1e9+7,inf=1e18;

ll n,m,factor[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    factor[0]=1;
    for (int i=1;i<=n;i++) factor[i]=factor[i-1]*i%m;
    ll res=0;
    for (int i=1;i<=n;i++) res=(res+factor[i]*factor[n-i]%m*(n-i+1)%m*(n-i+1)%m)%m;
    cout<<res;
    return 0;
}