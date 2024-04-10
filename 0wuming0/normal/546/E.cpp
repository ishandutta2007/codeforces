#include"bits/stdc++.h"
using namespace std;
const int MAXN = 1010;//
const int MAXM = 2010;//
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}
//
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
    edge[tol].flow = 0;head[u] = tol++;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
    edge[tol].flow = 0;head[v]=tol++;
}
//
//
int sap(int start,int end,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            if(Min > edge[i].cap - edge[i].flow)
            Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1;i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1;i = edge[i].next)
        if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
        {
            Min = dep[edge[i].to];
            cur[u] = i;
        }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}
int a[105],b[105];
vector<int>v[105];
vector<int>ans[105];
int save[105][105];
int main()
{
    init();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    int nn=n+3;
    while(m--)
    {
        int p,q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    int bg=n+1,ed=n+2;
    for(int i=1;i<=n;i++)
    {
        int last=i;
        for(auto j:v[i])
        {
            addedge(last,++nn,a[i]);
            addedge(nn,j,a[i]);
            last=nn;
            ans[i].push_back(tol-1);
        }
    }int aaa=4,bbb=1;
    int sum=0,sb=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        sb+=b[i];
        addedge(bg,i,a[i]);
        addedge(i,ed,b[i]);
    }
    if(sum!=sb)cout<<"NO"<<endl;
    else if(sap(bg,ed,nn+2)==sum)
    {//for(int i=0;i<tol;i++)cout<<edge[i].to<<" "<<edge[i].cap<<" "<<edge[i].flow<<endl;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                save[i][v[i][j]]=edge[ans[i][j]^1].flow;
                save[i][i]-=edge[ans[i][j]^1].flow;
            }
            save[i][i]+=a[i];
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",save[i][j]," \n"[j==n]);
    }
    else cout<<"NO"<<endl;
    return 0;
}