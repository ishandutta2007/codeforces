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
vi G[N];
ll w[N];

bool cmp(int t1,int t2) {return w[t1]>w[t2];}
int p[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        ll res=0;
        for (int i=1;i<=n;i++) G[i].clear(),cin>>w[i],p[i]=i,res+=w[i];
        for (int i=1,u,v;i<n;i++)
        {
            cin>>u>>v;
            G[u].eb(v);
            G[v].eb(u);
        }
        sort(p+1,p+n+1,cmp);
        vll vt;
        for (int i=1;i<=n;i++)
        {
            int u=p[i];
            for (int j=1;j<(int)G[u].size();j++) vt.eb(w[u]);
        }
        cout<<res<<" ";
        for (ll x : vt) res+=x,cout<<res<<" ";
        cout<<"\n";
    }
    return 0;
}