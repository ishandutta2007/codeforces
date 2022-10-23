#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e6+1;

struct edge
{
    int v,id;
};

vector<edge> g[maxn+1];
int b[maxn],c[maxn],n=0,m,a[maxn],deleted[maxn],mark[maxn],visit[maxn];
stack<int> cycle;

void in()
{
    cin>>m;
    m--;
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<=m;i++) cin>>c[i];
}

int rev(int x)
{
    return upper_bound(a+1,a+n+1,x)-a-1;
}

void cd()
{
    priority_queue< int , vector<int> , greater<int> > q;
    for (int i=1;i<=m;i++)
    {
        q.push(b[i]);
        q.push(c[i]);
    }
    while (!q.empty())
    {
        n++;
        a[n]=q.top();
        q.pop();
        while (!q.empty() && q.top()==a[n]) q.pop();
    }
    int u,v;
    for (int i=1;i<=m;i++)
    {
        u=rev(b[i]);
        v=rev(c[i]);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
}

int check()
{
    for (int i=1;i<=m;i++)
        if (b[i]>c[i]) return -1;
    int counted=0,t=1;
    for (int i=1;i<=n;i++)
        if (g[i].size()&1)
        {
            t=i;
            counted++;
        }
    if (counted>2) return -1;
    return t;
}

void euler(int x)
{
    stack<int> st;
    st.push(x);
    int u,v,id;
    bool flag;
    deleted[0]++;
    while (!st.empty())
    {
        u=st.top();
        visit[u]=1;
        flag=false;
        for (int i=mark[u];i<g[u].size();i++)
        {
            v=g[u][i].v;
            id=g[u][i].id;
            if (!deleted[id])
            {
                deleted[id]++;
                st.push(v);
                flag=true;
                mark[u]=i;
                break;
            }
        }
        if (!flag)
        {
            cycle.push(u);
            st.pop();
        }
    }
}

void out()
{
    while (!cycle.empty())
    {
        cout<<a[cycle.top()]<<" ";
        cycle.pop();
    }
}

bool connect()
{
    for (int i=1;i<=n;i++)
        if (!visit[i]) return false;
    return true;
}

void endp()
{
    cout<<-1;
    exit(0);
}

void solve()
{
    int tmp=check();
    if (tmp==-1) endp();
    euler(tmp);
    if (!connect()) endp();
    out();
}

int main()
{
    //freopen("ss.inp","r",stdin);
    //freopen("ss.out","w",stdout);
    in();
    cd();
    solve();
    return 0;
}