#include <iostream>
#include <vector>

#define pli pair<long long,int>
using namespace std;
const long long inf=1e18;
const int N=1e5+10;

struct heap
{
    vector<pli> vt;

    bool cmp(pli obj1,pli obj2) { return obj1<obj2; }

    int size() { return vt.size(); }

    bool empty() { return vt.empty(); }

    void up(int id)
    {
        if (id==0) return;
        int p=(id-1)/2;
        if (cmp(vt[id],vt[p]))
        {
            swap(vt[id],vt[p]);
            up(p);
        }
    }

    void down(int id)
    {
        int lef=id*2+1,rig=id*2+2,best=-1;
        if (rig<(int)vt.size() && cmp(vt[rig],vt[lef])) best=rig;
        else if (lef<(int)vt.size()) best=lef;
        if (best!=-1 && cmp(vt[best],vt[id]))
        {
            swap(vt[best],vt[id]);
            down(best);
        }
    }

    void push(pli obj)
    {
        vt.push_back(obj);
        up(((int)vt.size()-2)/2);
    }

    void pop()
    {
        vt[0]=vt.back();
        vt.pop_back();
        down(0);
    }

    pli top() { return vt[0]; }

    /*void change(int id,pli obj)
    {
        bool check=cmp(obj,vt[id]);
        vt[id]=obj;
        if (check) up(id);
        else down(id);
    }*/
};

void dijkstra(long long d[],vector<pli> adj[],int st,int len,int trace[])
{
    for (int i=1;i<=len;i++) d[i]=inf;
    d[st]=0;
    heap q;
    q.push(make_pair(0,st));
    while (!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for (pli v : adj[u])
            if (d[u]+v.first<d[v.second])
            {
                d[v.second]=d[u]+v.first;
                trace[v.second]=u;
                q.push(make_pair(d[v.second],v.second));
            }
        while (!q.empty() && d[q.top().second]<q.top().first) q.pop();
    }
}

vector<pli> G[N];
int n,m,trace[N];
long long dis[N];

void read()
{
    cin>>n>>m;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(make_pair(w,v));
        G[v].push_back(make_pair(w,u));
    }
}

void process()
{
    dijkstra(dis,G,1,n,trace);
    if (dis[n]==inf)
    {
        cout<<-1;
        return;
    }
    vector<int> ans;
    int u=n;
    while (u)
    {
        ans.push_back(u);
        u=trace[u];
    }
    for (int i=(int)ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
}

int main()
{
    read();
    process();
    return 0;
}