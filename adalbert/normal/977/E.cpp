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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int arr=6e5;

vector<int> vec[arr];
bool use[arr];
bool ch;

void dfs(int u)
{
    if (vec[u].size()!=2)
        ch=0;
    use[u]=1;
    for (auto i:vec[u])
    {
        if (!use[i])
            dfs(i);
    }
}

signed main()
{
    int n,m;
    cin>>n>>m;

    while (m--)
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
            ch=1;
            dfs(i);
            if (ch)
                ans++;
        }

    cout<<ans;
}
/*
*/