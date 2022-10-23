#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;
int n,m,b[N],g[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int mx=0,mn=1e9,mx2=0;
    ll res=0,s=0;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        mx2=max(mx2,b[i]);
        if (mx2>mx) swap(mx,mx2);
        res+=(ll)b[i]*m;
    };
    for (int j=1;j<=m;j++) cin>>g[j],mn=min(mn,g[j]),s+=g[j];
    if (mn<mx) cout<<-1;
    else if (mn==mx) cout<<res-(ll)mx*m+s;
    else cout<<res-(ll)mx*m+mx-mx2+s;
    return 0;
}