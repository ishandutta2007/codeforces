#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
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

#define ld double

//#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#define __USE_MINGW_ANSI_STDIO 0

template<typename type1,typename type2> bool operator+=(pair<type1,type2>& a,pair<type1,type2> b)
{
    a.fir+=b.fir;
    a.sec+=b.sec;
}

template<typename type1,typename type2> ostream& operator<<(ostream &os,pair<type1,type2> a)
{
    return os<<"("<<a.fir<<","<<a.sec<<")";
}

struct edge
{
    int from,to,flow;
    ld cost;
    int num,rev;
    edge() {}
    edge(int from_,int to_,int flow_,ld cost_,int num_=0,int rev_=0)
    {
        from=from_;
        to=to_;
        flow=flow_;
        cost=cost_;
        num=num_;
        rev=rev_;
    }
};

pii pred[arr];
ld dist[arr];
ld p[arr];
int s,t;
vector<edge> reb[arr];

void _add(int from_,int to_,int flow_,ld cost_)
{
    edge e1=edge(from_,to_,flow_,cost_);
    edge e2=edge(to_,from_,0,-cost_);
    e1.num=reb[from_].size();
    e2.num=reb[to_].size();
    e1.rev=reb[to_].size();
    e2.rev=reb[from_].size();
    reb[from_].pb(e1);
    reb[to_].pb(e2);
}

pair<ld,int> dijkstra()
{
    fill(dist,dist+t+1,1e9);
    dist[s]=0;
    set<pii> q;
    q.clear();
    for (int i=0;i<=t;i++)
        q.insert(mp(dist[i],i));
    while (!q.empty())
    {
        int now=q.begin()->sec;
        q.erase(q.begin());
        for (auto wh:reb[now])
            if (wh.flow!=0&&dist[wh.to]>dist[now]+wh.cost+p[now]-p[wh.to])
            {
                q.erase(mp(dist[wh.to],wh.to));
                dist[wh.to]=dist[now]+wh.cost+p[now]-p[wh.to];
                pred[wh.to]=mp(now,wh.num);
                q.insert(mp(dist[wh.to],wh.to));
            }
    }
    if (dist[t]==1e9)
        return mp(0,0);
    for (int i=0;i<=t;i++)
        if (dist[i]!=1e9)
            p[i]+=dist[i];
    pair<ld,int> res=mp(0,1e9);
    int cur;
    cur=t;
    while (cur!=s)
    {
        int from=pred[cur].fir;
        int use=pred[cur].sec;
        res.sec=min(res.sec,reb[from][use].flow);
        cur=from;
    }
    cur=t;
    while (cur!=s)
    {
        int from=pred[cur].fir;
        int use=pred[cur].sec;
        reb[from][use].flow-=res.sec;
        reb[cur][reb[from][use].rev].flow+=res.sec;
        res.fir+=res.sec*reb[from][use].cost;
        cur=from;
    }
    return res;
}

pair<ld,int> min_cost_max_flow()
{
    pair<ld,int> res=mp(0,0);
    pair<ld,int> val=dijkstra();
    while (val.sec)
        res+=val,
        val=dijkstra();
    return res;
}

ld p1[arr];
ld p2[arr];

main()
{
    fast;
    int n,a,b;
    cin>>n>>a>>b;
    s=0;
    t=n+3;
    _add(s,n+1,a,0);
    _add(s,n+2,b,0);
    for (int i=1;i<=n;i++)
        cin>>p1[i];
    for (int i=1;i<=n;i++)
        cin>>p2[i];
    for (int i=1;i<=n;i++)
        _add(n+1,i,1,-p1[i]),
        _add(n+2,i,1,-p2[i]),
        _add(i,t,1,0),
        _add(i,t,1,p1[i]*p2[i]);
    cout<<-min_cost_max_flow().fir<<"\n";
}