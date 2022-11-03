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

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int base=3;
const int INF=1e18;
const int md=1e9+9;

const int arr=1e6+100;

int res[arr][4];
int type[arr],pred[arr];
string st[arr];
vector<int> vec[arr];

void dfs(int u)
{
    for (auto i:vec[u])
        dfs(i);
    if (st[u]=="IN")
        return;
    if (st[u]=="AND")
        type[u]=(type[vec[u][0]]&type[vec[u][1]]); else
    if (st[u]=="NOT")
        type[u]=!type[vec[u][0]]; else
    if (st[u]=="OR")
        type[u]=(type[vec[u][0]]|type[vec[u][1]]); else
    if (st[u]=="XOR")
        type[u]=(type[vec[u][0]]^type[vec[u][1]]);
}

int getans(int u)
{
    if (u==0)
        return(type[1]);

    int tutu=0;

    for (auto i:vec[u])
    {
        tutu*=2;
        tutu+=type[i];
    }

    return(res[u][tutu]);
}

void solve(int u)
{
    if (st[u]=="IN")
        return;

    if (st[u]=="XOR")
    {
        for (int i=0;i<4;i++)
        {
            int ptype=type[u];
            int now=((i/2)^(i%2));
            type[u]=now;

            res[u][i]=getans(pred[u]);
            type[u]=ptype;
        }
    } else
    if (st[u]=="OR")
    {
        for (int i=0;i<4;i++)
        {
            int ptype=type[u];
            int now=((i/2)|(i%2));
            type[u]=now;

            res[u][i]=getans(pred[u]);
            type[u]=ptype;
        }
    } else
    if (st[u]=="AND")
    {

        for (int i=0;i<4;i++)
        {
            int ptype=type[u];
            int now=((i/2)&(i%2));
            type[u]=now;
            res[u][i]=getans(pred[u]);
            type[u]=ptype;
        }
    } else
    if (st[u]=="NOT")
    {
        for (int i=0;i<2;i++)
        {
            int ptype=type[u];
            int now=!i;
            type[u]=now;

            res[u][i]=getans(pred[u]);
            type[u]=ptype;
        }
    }

    for (auto i:vec[u])
        solve(i);
}

signed main()
{
    fast;
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
        if (st[i]=="IN")
            cin>>type[i]; else
        {
            if (st[i]=="NOT")
            {
                int a;
                cin>>a;
                vec[i].pb(a);
                pred[a]=i;
            } else
            {
                int a,b;
                cin>>a>>b;
                vec[i].pb(a);
                vec[i].pb(b);
                pred[a]=i;
                pred[b]=i;
            }
        }
    }

    dfs(1);
    solve(1);

    for (int i=1;i<=n;i++)
        if (st[i]=="IN")
    {
        type[i]=!type[i];
            cout<<getans(pred[i]);
        type[i]=!type[i];
    }
}