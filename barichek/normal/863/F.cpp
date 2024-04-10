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
#define int long long

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

bool operator+=(pii &a,const pii &b)
{
    a.fir+=b.fir;
    a.sec+=b.sec;
}

#define ar (int)(3000+10)

int cnt_vertex;
int s,t;
int dist[ar];
int pred[ar];
int p[ar];
int f[ar][ar];
int cost[ar][ar];

void _add(int from_,int to_,int flow_,int cost_)
{
    f[from_][to_]=flow_;
    cost[from_][to_]=cost_;
    cost[to_][from_]=-cost_;
}

pii dijkstra()
{
    set<pii> q;
    q.clear();
    for (int i=0;i<cnt_vertex;i++)
        if (i!=s)
            dist[i]=1e9,
            q.insert(mp(dist[i],i));
        else
            dist[i]=0,
            q.insert(mp(dist[i],i));
    while (!q.empty())
    {
        int now=q.begin()->sec;
        q.erase(q.begin());
        for (int wh=0;wh<cnt_vertex;wh++)
            if (f[now][wh]&&dist[wh]>dist[now]+cost[now][wh]+p[now]-p[wh])
            {
                q.erase(mp(dist[wh],wh));
                dist[wh]=dist[now]+cost[now][wh]+p[now]-p[wh];
                pred[wh]=now;
                q.insert(mp(dist[wh],wh));
            }
    }
    if (dist[t]==1e9) return mp(0,0);
    pii res=mp(0,1e9);
    int cur;
    cur=t;
    while (cur!=s)
    {
        int from=pred[cur];
        res.sec=min(res.sec,f[from][cur]);
        cur=from;
    }
    cur=t;
    while (cur!=s)
    {
        int from=pred[cur];
        res.fir+=res.sec*cost[from][cur];
        f[from][cur]-=res.sec;
        f[cur][from]+=res.sec;
        cur=from;
    }
    for (int i=0;i<cnt_vertex;i++)
        if (dist[i]!=1e9)
            p[i]+=dist[i];
    return res;
}

pii min_cost_max_flow()
{
    pii res=mp(0,0);
    pii val=dijkstra();
    while (val.sec)
    {
        res+=val;
        val=dijkstra();
    }
    return res;
}

int L[arr];
int R[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        L[i]=1;
        R[i]=n;
    }
    while (q--){
        int type,l,r,v;
        cin>>type>>l>>r>>v;
        if (type==1){
            for (int i=l;i<=r;i++){
                L[i]=max(L[i],v);
            }
        }
        else{
            for (int i=l;i<=r;i++){
                R[i]=min(R[i],v);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (L[i]>R[i]){
            return cout<<-1<<"\n", 0;
        }
    }

    fast;
    s=0;
    t=n*n+n+1;
    cnt_vertex=t+1;
    for (int i=1;i<=n;i++){
        _add(s,i,1,0);
        for (int j=L[i];j<=R[i];j++){
            _add(i,n+(j-1)*n+1,1e6,0);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<n;j++){
            _add(n+(i-1)*n+j,n+(i-1)*n+j+1,1e6,0);
        }
        for (int j=1;j<=n;j++){
            _add(n+(i-1)*n+j,t,1,2*j-1);
        }
    }
    cout<<min_cost_max_flow().fir<<"\n";
}