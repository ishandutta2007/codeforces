#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
ll f[maxn],n,m;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    f[1]=1;
    f[2]=2;
    for (int i=3;i<=max(m,n);i++) f[i]=(f[i-1]+f[i-2])%mod;
    cout<<((f[m]+f[n]-1)*2)%mod;
    return 0;
}