#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,maxx=0,minx=1e5,maxy=0,miny=1e5;
    char c;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            cin>>c;
            if (c=='B')
            {
                maxx=max(maxx,i);
                minx=min(minx,i);
                maxy=max(maxy,j);
                miny=min(miny,j);
            }}
    cout<<(maxx+minx)/2<<" "<<(maxy+miny)/2;
    return 0;
}