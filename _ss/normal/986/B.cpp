#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e6+1,msiz=2,mod=1e9+7,inf=1e18;
int n,a[maxn],v[maxn];

int dfs(int u)
{
    v[u]=1;
    if (v[a[u]]) return 0;
    else return dfs(a[u])+1;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int t=0;
    for (int i=1;i<=n;i++)
        if (!v[i]) t+=dfs(i);
    if ((t&1)==((3*n)&1)) cout<<"Petr"; else cout<<"Um_nik";
    return 0;
}