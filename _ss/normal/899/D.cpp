#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    if (n==2)
    {
        cout<<1;
        return 0;
    }
    if (n==3)
    {
        cout<<3;
        return 0;
    }
    if (n==4)
    {
        cout<<6;
        return 0;
    }
    ll t=1,cnt=0;
    while (t-1<=2*n-1) t*=10;
    t/=10;
    ll h=t-1;
    while ((h+1)/2<=n)
    {
        cnt+=min(n-(h+1)/2+1,(h+1)/2-1);
        h+=t;
    }
    cout<<cnt;
    return 0;
}