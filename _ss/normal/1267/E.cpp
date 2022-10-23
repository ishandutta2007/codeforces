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
const ll N=110,mod=1e9+7,inf=1e9;
int a[N][N],n,m;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    int res=inf,t;
    for (int i=1;i<n;i++)
    {
        vector<int> vt;
        int s=0;
        for (int j=1;j<=m;j++) vt.pb(a[j][i]-a[j][n]),s+=a[j][i]-a[j][n];
        sort(all(vt));
        int d=0;
        for (int j=0;j<vt.size() && s<0;j++) s-=vt[j],d++;
        if (d<res) res=d,t=i;
    }
    vector<pii> vt;
    for (int i=1;i<=m;i++) vt.pb(mp(a[i][t]-a[i][n],i));
    sort(all(vt));
    cout<<res<<"\n";
    for (int i=0;i<res;i++) cout<<vt[i].se<<" ";
    return 0;
}