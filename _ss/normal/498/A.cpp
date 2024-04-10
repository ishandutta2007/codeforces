#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x1,x2,y1,y2,a,b,c,n,d=0;
    cin>>x1>>y1>>x2>>y2>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        if (a*x1+b*y1+c>0 && a*x2+b*y2+c<0) d++;
        if (a*x1+b*y1+c<0 && a*x2+b*y2+c>0) d++;
    }
    cout<<d;
    return 0;
}