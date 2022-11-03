#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

bool use[10000];
bool go[6000][6000];
int cnt[10000];
int n,m,s;
vector<int> vec[10000];

void dfs(int u)
{
    use[u]=1;

    for (auto i:vec[u])
        if (!use[i])
        dfs(i);
}

void dell(int u)
{
    for (int j=1;j<=n;j++)
    if (j!=s)
        if (go[j][u])
        cnt[j]--;
}

signed main()
{
    cin>>n>>m>>s;

    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);

    }
    
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            use[j]=0;

        dfs(i);

        for (int j=1;j<=n;j++)
        {
            go[i][j]=use[j];
            cnt[i]+=use[j];
        }
    }

    for (int i=1;i<=n;i++)
        if (go[s][i])
        dell(i);

    int ans=0;
	
	
	
    while (cnt[s]!=n)
    {
        int best=0;
        for (int j=1;j<=n;j++)
            if (cnt[j]>cnt[best] && j!=s)
            best=j;
        cnt[s]+=cnt[best];

        for (int i=1;i<=n;i++)
            if (!go[s][i] && go[best][i])
            {
                go[s][i]=1;
                dell(i);
            }
            
        ans++;
    }

    cout<<ans;
}