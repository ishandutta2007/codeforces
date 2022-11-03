#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ans=0;

int sum[200000];
vector<int> vec[200000];

void dfs(int u, int pred)
{
    sum[u]=1;

    for (auto i:vec[u])
    if (i!=pred)
    {
        dfs(i,u);
        sum[u]+=sum[i];
    }
    if (sum[u]%2==0)
        ans++;
}

signed main()
{
    int n;
    cin>>n;

    if (n%2==1)
    {
        cout<<-1;
        return(0);
    }

    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    dfs(1,0);

    cout<<ans-1;
}
/*
*/