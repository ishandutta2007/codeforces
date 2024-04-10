#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

struct edge
{
    int from,to,flow,rev;
    edge() {}
    edge(int from_,int to_,int flow_,int rev_)
    {
        from=flow_;
        to=to_;
        flow=flow_;
        rev=rev_;
    }
};

vector<edge> reb[arr];

void add_edge(int from,int to,int flow)
{
    edge e1=*new edge(from,to,flow,len(reb[to]));
    edge e2=*new edge(to,from,0,len(reb[from]));
    reb[from].pb(e1);
    reb[to].pb(e2);
}

int dist[arr];

bool bfs(int s,int t)
{
    queue<int> q;
    for (int i=1;i<=t;i++){
        dist[i]=1e9;
    }
    dist[0]=0;
    q.push(0);
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:reb[now]){
            if (wh.flow&&dist[wh.to]>dist[now]+1){
                dist[wh.to]=dist[now]+1;
                q.push(wh.to);
            }
        }
    }
    if (dist[t]==1e9){
        return 0;
    }
    return 1;
}

bool use[arr];
int pred[arr];
int pred1[arr];
int p[arr];

void dfs(int now,int t)
{
//    cerr<<"dfs :: "<<now<<"\n";
    use[now]=1;
    if (now==t){
        return;
    }
    for (;p[now]<len(reb[now]);){
        auto wh=reb[now][p[now]];
        if (!use[wh.to]&&wh.flow>0&&dist[wh.to]>dist[now]){
            dfs(wh.to,t);
            pred[wh.to]=now;
            pred1[wh.to]=p[now];
        }
        if (use[t]){
            return;
        }
        p[now]++;
    }
}

int go_back(int s,int t)
{
    int res=1e9;
    int cur=t;

    while (cur!=s){
        int from=pred[cur];
        int num=pred1[cur];
        res=min(res,reb[from][num].flow);
        cur=from;
    }

//    cerr<<"go_back :: "<<res<<"\n";

    cur=t;

    while (cur!=s){
        int from=pred[cur];
        int num=pred1[cur];
        reb[from][num].flow-=res;
        reb[cur][reb[from][num].rev].flow+=res;
        cur=from;
    }

    return res;
}

int max_flow(int s,int t)
{
//    cerr<<"max_flow :: "<<s<<" "<<t<<"\n";
    int res=0;
    while (bfs(s,t)){
        for (int i=0;i<=t;i++){
            p[i]=0;
        }
//        cerr<<"i bfs'ed"<<"\n";
        while (1){
            for (int i=0;i<=t;i++){
                pred[i]=-1;
                use[i]=0;
            }
            dfs(s,t);
            if (!use[t]){
                break;
            }
//            cerr<<"i dfs'ed"<<"\n";
            res+=go_back(s,t);
//            cerr<<"new res :: "<<res<<"\n";
        }
    }
//    cerr<<"res max_flow :: "<<res<<"\n";
    return res;
}

int n,m;
vector<pii> q;

void build(int k)
{
    for (int i=0;i<=n+m+1;i++){
        reb[i].clear();
        use[i]=0;
        pred[i]=-1;
    }

    int s=0;
    int t=n+m+1;
    for (int i=0;i<m;i++){
        add_edge(s,i+1,1);
        add_edge(i+1,m+q[i].fir,1);
        add_edge(i+1,m+q[i].sec,1);
    }
    for (int i=1;i<=n;i++){
        add_edge(m+i,t,k);
    }
}

bool check(int k)
{
//    cerr<<"check :: "<<k<<"\n";
    build(k);
    int s=0;
    int t=n+m+1;
    return max_flow(s,t)==m;
}

void answer(int result)
{
    build(result);
    int s=0;
    int t=n+m+1;
    max_flow(s,t);
    vector<pii> ans(0);
    for (int i=0;i<m;i++){
        for (auto j:reb[i+1]){
            if (j.to>=m+1&&j.to<=n+m){
                if (j.flow==0){
                    ans.pb(mp(j.to-m,(q[i].fir==j.to-m?q[i].sec:q[i].fir)));
                }
            }
        }
    }
    cout<<result<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    cin>>n>>m;
    q.resize(m);
    for (auto& i:q){
        cin>>i.fir>>i.sec;
    }
    int l=0,r=m;
    while (r-l>1){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m;
        }
    }
    if (check(l)){
        answer(l);
    }
    else{
        answer(r);
    }
}