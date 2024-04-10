#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
int n,a[N],k,p,b[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    ll res=1e18;
    for (int i=1;i<=k-n+1;i++)
    {
        ll val=0;
        for (int j=1;j<=n;j++) val=max(val,(ll)abs(a[j]-b[j+i-1])+abs(b[j+i-1]-p));
        res=min(res,val);
    }
    cout<<res;
    return 0;
}