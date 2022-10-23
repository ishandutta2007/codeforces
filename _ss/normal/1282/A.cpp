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
    int t,a,b,c,r;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>c>>r;
        int l=c-r;
        r=c+r;
        if (a>b) swap(a,b);
        int d=b-a;
        l=max(l,a);
        r=min(r,b);
        if (l<=r) d-=r-l;
        cout<<d<<"\n";
    }
    return 0;
}