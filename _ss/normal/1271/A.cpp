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
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    b=min(b,c);
    ll res=0;
    if (e>=f)
    {
        res+=min(d,a)*e;
        d-=min(d,a);
        res+=min(d,b)*f;
    }
    else
    {
        res+=min(d,b)*f;
        d-=min(d,b);
        res+=min(d,a)*e;
    }
    cout<<res;
    return 0;
}