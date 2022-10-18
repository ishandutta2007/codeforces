#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
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

#define arr (int)(3e5+10)

struct edge
{
    int from,to,flow;
    int start_flow;
    edge* rev;

    edge() {}
};

vector<edge*> reb[arr];

void add_edge(int u,int v,int flow)
{
//    cout<<"add_edge :: "<<u<<" -> "<<v<<" :: "<<flow<<"\n";
    reb[u].pb(new edge());
    reb[v].pb(new edge());

    reb[u].back()->from=u;
    reb[u].back()->to=v;
    reb[u].back()->flow=flow;
    reb[u].back()->start_flow=flow;
    reb[u].back()->rev=(edge*)reb[v].back();

    reb[v].back()->from=v;
    reb[v].back()->to=u;
    reb[v].back()->flow=0;
    reb[v].back()->start_flow=0;
    reb[v].back()->rev=(edge*)reb[u].back();
}

set<pii> answer;

int s,t;
int dist[arr];

bool bfs()
{
    for (int i=s;i<=t;i++){
        dist[i]=1e9;
    }
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:reb[now]){
            if (wh->flow&&dist[wh->to]>dist[now]+1){
                dist[wh->to]=dist[now]+1;
                q.push(wh->to);
            }
        }
    }
    if (dist[t]>1e8){
        return 0;
    }
    return 1;
}

edge* pred[arr];

int pp[arr];

int dfs(int now,int value=1e9)
{
    if (now==t){
        return value;
    }
    while (pp[now]<len(reb[now])){
        edge* wh=reb[now][pp[now]];
        if (wh->flow&&dist[wh->to]==dist[now]+1){
            pred[wh->to]=(edge*)wh;
//            cout<<"pred["<<wh->to<<"] :: "<<now<<"\n";
            int cur=dfs(wh->to,min(value,wh->flow));
            if (cur){
                return cur;
            }
        }
        pp[now]++;
    }
    return 0;
}

void go_back(int f)
{
//    cout<<"go_back : "<<f<<"\n";
    int cur=t;
    while (cur!=s){
//        cout<<cur<<"\n";
        edge* e1=pred[cur];
        edge* e2=e1->rev;

        e1->flow-=f;
        e2->flow+=f;

        cur=e1->from;
    }
}

int dinic()
{
    for (int i=s;i<=t;i++){
        random_shuffle(all(reb[i]));
    }
    int res=0;
    while(bfs()){
        for (int i=s;i<=t;i++){
            pp[i]=0;
        }
        while (1){
            int cur=dfs(s);
            if (!cur){
                break;
            }
            res+=cur;
            go_back(cur);
        }
    }
    return res;
}

int type[10000];
vi poson1[10000];
pii poson2[10000];
vi poson3[10000];

int last=1;

int kek[arr];
int pos[arr];
int lolv[arr];
vi rem[arr];

void rec(int v,int l,int r)
{
    kek[v]=last++;
//    cout<<"rec :: "<<v<<" || "<<l<<" "<<r<<" :: "<<kek[v]<<"\n";
    if (l==r){
        lolv[l]=v;
        pos[l]=kek[v];
        return;
    }

    int m=(l+r)/2;
    rec(v*2,l,m);
    rec(v*2+1,m+1,r);

    add_edge(kek[v],kek[v*2],+10000000);
    add_edge(kek[v],kek[v*2+1],+10000000);
}

void rec1(int v,int l,int r,int tl,int tr,int num)
{
    if (l>tr||r<tl){
        return;
    }

    if (l>=tl&&r<=tr){
        add_edge(num,kek[v],+1);
        return;
    }
    int m=(l+r)/2;

    rec1(v*2,l,m,tl,tr,num);
    rec1(v*2+1,m+1,r,tl,tr,num);
}

int n,m;

void build_answer()
{
    for (int i=1;i<=n;i++){
        for (auto wh:reb[i]){
            if (wh->flow!=wh->start_flow){
                rem[wh->to].pb(i);
//                cout<<"reb["<<wh->to<<"].pb("<<i<<")"<<"\n";
            }
        }
    }

    for (int i=1;i<=m;i++){
        for (auto q:reb[pos[i]]){
            if (q->to==t&&q->flow==0){
//                cout<<i<<" !!!\n";
                int cur=lolv[i];
                while (rem[kek[cur]].empty()){
                    cur/=2;
                }
                int lol=rem[kek[cur]].back();
                rem[kek[cur]].pop_back();
                answer.insert({lol,i});
            }
        }
    }
}

bool can[5001][5001];

void normalizate_answer()
{
    for (int i=1;i<=n;i++){
        if (type[i]==2){
            int cnt=0;
            for (auto q:answer){
                if (q.fir==i){
                    cnt++;
                }
            }
            if (cnt==1){
                for (auto q:answer){
                    if (q.fir!=i&&can[i][q.sec]){
                        answer.insert({i,q.sec});
                        answer.erase(q);
                        break;
                    }
                }
            }
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>type[i];
        if (type[i]==0){
            int size;
            cin>>size;
            while (size--){
                int a;
                cin>>a;
                poson1[i].pb(a);
            }
        }
        elif (type[i]==1){
            cin>>poson2[i].fir>>poson2[i].sec;
        }
        else{
            poson3[i].resize(3);
            for (auto& j:poson3[i]){
                cin>>j;
                can[i][j]=1;
            }
        }
    }
    s=0;
    last+=n;
    rec(1,1,m);
    t=last;
//    cout<<"s t :: "<<s<<" "<<t<<"\n";

    /// edges
    for (int i=1;i<=n;i++){
        if (type[i]==0){
            add_edge(s,i,+1);
            for (auto j:poson1[i]){
                add_edge(i,pos[j],+1);
            }
        }
        elif (type[i]==1){
            add_edge(s,i,+1);
            rec1(1,1,m,poson2[i].fir,poson2[i].sec,i);
        }
        else{
            add_edge(s,i,+2);
            for (auto j:poson3[i]){
                add_edge(i,pos[j],+1);
            }
        }
    }

    for (int i=1;i<=m;i++){
        add_edge(pos[i],t,+1);
    }

    int ans=dinic();

    cout<<ans<<"\n";

    build_answer();
    normalizate_answer();

    for (auto i:answer){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
}