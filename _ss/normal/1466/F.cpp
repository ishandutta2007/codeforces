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
const int N=5e5+10;
const ll mod=1e9+7;
int p[N];

int find_root(int u)
{
    if (p[u]>0) return (p[u]=find_root(p[u]));
    return u;
}

void merg(int u,int v)
{
    if (p[u]>p[v]) swap(u,v);
    if (p[u]==p[v]) p[u]--;
    p[v]=u;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    vi ans;
    ll res=1;
    cin>>m>>n;
    for (int i=1,u,v,k;i<=m;i++)
    {
        cin>>k>>u;
        if (k==1) v=n+1;
        else cin>>v;
        int ru=find_root(u),rv=find_root(v);
        if (ru!=rv)
        {
            merg(ru,rv);
            ans.eb(i);
            res=(res*2)%mod;
        }
    }
    cout<<res<<" "<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" ";
    return 0;
}