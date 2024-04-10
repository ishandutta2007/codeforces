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
#define time ddfkjgofidhj
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=1e6+100;
const int md=1e9+7;
const int base=1039;

int ans[arr],s[arr];
bool use[arr];
vector<pair<int,int> > vec[arr];

int dfs(int u)
{
    use[u]=1;
    int sum=s[u];
    for (auto i:vec[u])
        if (!use[i.fir])
        {
            int now=dfs(i.fir);
            sum+=now;
            if (i.sec<0)
            ans[-i.sec]=-now; else
            ans[i.sec]=now;
        }
    return(sum);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>s[i];

    int sum=0;

    for (int i=1;i<=n;i++)
        sum+=s[i];

    if (sum!=0)
    {
        cout<<"Impossible";
        return(0);
    }

    int m;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb({b,i});
        vec[b].pb({a,-i});
    }

    dfs(1);

    cout<<"Possible\n";

    for (int i=1;i<=m;i++)
        cout<<ans[i]<<'\n';
}
/*
*/