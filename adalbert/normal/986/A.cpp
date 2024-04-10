#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;

vector<int> vec[arr],start[arr];
int len[arr];
vector<int> ans[arr];

signed main()
{
    int n,m,k,s;
    cin>>n>>m>>k>>s;

    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        start[a].pb(i);
    }

    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }

    for (int i=1;i<=k;i++)
    {
        queue<int> q;

        for (int i=1;i<=n;i++)
            len[i]=1e9;

        for (auto j:start[i])
        {
            len[j]=0;
            q.push(j);
        }

        while (!q.empty())
        {
            int u=q.front();
            q.pop();

            for (auto i:vec[u])
                if (len[i]==1e9)
            {
                len[i]=min(len[i],len[u]+1);
                q.push(i);
            }
        }

        for (int i=1;i<=n;i++)
            ans[i].pb(len[i]);
    }

    for (int i=1;i<=n;i++)
    {
        sort(ans[i].begin(),ans[i].end());

        int res=0;

        for (int j=0;j<s;j++)
            res+=ans[i][j];
        cout<<res<<' ';
    }
}