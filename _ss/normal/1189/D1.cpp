#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;
vector<int> G[maxn];
int n;
int main()
{
    cin>>n;
    int u,v;
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    int kt=1;
    for (int i=1;i<=n;i++)
    if (G[i].size()==2) kt=0;
    if (kt) cout<<"YES"; else cout<<"NO";
    return 0;
}