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

ll cnt(ll x)
{
    ll res=0;
    while (x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll t=1;
    while (t-1<=n) t*=10;
    t/=10;
    cout<<cnt(t-1)+cnt(n-t+1);
    return 0;
}