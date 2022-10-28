#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define endl '\n'
#define double long double
// #define int long long
#define mod 1000000007
#define ll long long
#define N 2000

int a[N][N];
int b[N][N];

int hor_offset;
int offset;
int SZ;
vector<vector<int>> g;
vector<vector<int>> rg;
vector<int> vis;
vector<int> comp,assignment;
int n,m;
vector<int> towerPointedBy[10005];
vector<int> bar;
int other(int a)
{
    if(a >= hor_offset)
        return (a >= hor_offset + SZ) ? a - SZ : a + SZ;
    else
        return (a >= SZ) ? a- SZ:a + SZ;
}

void addEdge(int a,int b)
{
    g[a].push_back(b);
    rg[b].push_back(a);
}

stack<int> st;
int cno = 0;
void dfs1(int s)
{
    vis[s] = 1;
    for(auto it:g[s])
    {
        if(!vis[it])
        {
            dfs1(it);
        }
    }
    st.push(s);
}
void dfs2(int s)
{
    comp[s] = cno;
    for(auto it:rg[s])
    {
        if(comp[it] == -1)
        {
            dfs2(it);
        }
    }
}

void solve()
{
    for(int  i = 0;i < 4*n ;i++)
    {
        if(!vis[i])
        {
            dfs1(i);
        }
    }
    while(!st.empty())
    {
        int d = st.top();
        st.pop();
        if(comp[d] == -1)
        {
            dfs2(d);
            cno++;

        }
    }
    int fcnt = 0;
    for(int  i = 0;i < n;i++)
    {
        if(comp[i] == comp[i+SZ])
        {
            cout << - 1;
            exit(0);
        }
        else
            assignment[i] = comp[i] > comp[i+SZ];
        fcnt += assignment[i];
    }
    for(int  i = 2*n ;i < 3*n ;i++)
    {
        if(comp[i] == comp[i+SZ])
        {
            cout << - 1;
            exit(0);
        }
        else
            assignment[i] = comp[i] > comp[i+SZ];
        fcnt += assignment[i];
    }
    cout << fcnt << endl;
    for(int i = 0;i < n;i++)
    {
        if(assignment[i])
            cout << "row " << i << endl;
        if(assignment[2*n + i])
            cout << "col " << i << endl;
    }
}

void add_row_based(int req,int i,int j)
{
    if(req)
    {
        if(bar[i % n])
            addEdge(i,j);
        else
            addEdge(i,other(i));
    }
    else
    {
        if(bar[i % n])
            addEdge(i,other(j));
        
    }
}

void add_col_based(int req,int i,int j)
{
    if(req)
    {
        if(bar[j % n])
            addEdge(j,i);
        else
            addEdge(j,other(j));
    }
    else
    {
        if(bar[j % n])
            addEdge(j,other(i));
        
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    cin >> n;
    hor_offset = 2*n;
    SZ = n;
    g.resize(4*n + 2);
    rg.resize(4*n + 2);
    vis.resize(4*n + 2);
    comp.resize(4*n + 2,-1);
    assignment.resize(4*n + 2,0);
    string s;

    for(int i = 0;i < n;i++)
    {
        cin >> s;
        for(int j = 0;j < n;j++)
        {
            a[i][j] = (s[j] == '1');
        }
    }
    for(int i = 0;i < n;i++)
    {
        cin >> s;
        for(int j = 0;j < n;j++)
        {
            b[i][j] = (s[j] == '1');
        }
    }
    bar.resize(n,0);
    cin >> s;
    for(int i = 0;i < n;i++)
        bar[i] = (s[i] == '1');

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int req = b[i][j] ^ a[i][j];
            //keep bar horizontal
            int changed = bar[j] ^ a[i][j];
            int nreq = b[i][j] ^ changed;
            add_row_based(nreq,i,hor_offset + j);
            add_row_based(req,other(i),hor_offset + j);
            //keep bar vertical
            changed = bar[i] ^ a[i][j];
            nreq = b[i][j] ^ changed;
            add_col_based(nreq,i,hor_offset + j);
            add_col_based(req,i,other(hor_offset+ j));
        }

    }

    solve();
    
    return 0;
}