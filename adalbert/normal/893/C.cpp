#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll

typedef long long ll;
typedef double ld;
const int arr=6e5;

vector<int> vec[arr];
int use[arr],c[arr],rans;

void dfs(int u)
{
    if (use[u])
        return;
    use[u]=1;
    rans=min(rans,c[u]);
    for (auto i:vec[u])
        dfs(i);
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>c[i];

    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    int ans=0;

    for (int i=1;i<=n;i++)
        if (!use[i])
    {
        rans=1e18;
        dfs(i);
        ans+=rans;
    }

    cout<<ans;
}
/*

*/