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

#define arr (int)(1e6+10)

int n;
vi reb[arr];
int T;
int deep[arr];

const int M=20;

int p[arr][M];
int tin[arr];
int tout[arr];

int size_down[arr];
int where_go[arr];
set<int> sets[arr];

void dfs0(int now,int pred)
{
    p[now][0]=pred;
    for (int i=1;i<M;i++){
        p[now][i]=p[p[now][i-1]][i-1];
    }
    size_down[now]=1;

    tin[now]=++T;

    for (auto wh:reb[now]){
        if (wh!=pred){
            deep[wh]=deep[now]+1;
            dfs0(wh,now);
            size_down[now]+=size_down[wh];
            if (where_go[now]==0||size_down[wh]>size_down[where_go[now]]){
                where_go[now]=wh;
            }
        }
    }

    tout[now]=T;
}

int top[arr];
int pos[arr];
int reverse_pos[arr];
int POS;
vi vectora[arr];

void hld(int now,int pred=-1)
{
    pos[now]=++POS;
    reverse_pos[POS]=now;
    if (!top[now]){
        top[now]=now;
    }
    vectora[top[now]].pb(now);

    if (where_go[now]){
        top[where_go[now]]=top[now];
        hld(where_go[now],now);
    }

    for (auto wh:reb[now]){
        if (wh!=pred&&wh!=where_go[now]){
            hld(wh,now);
        }
    }
}

inline int lca(int u,int v)
{
    if (deep[u]>deep[v]){
        swap(u,v);
    }
    for (int i=M-1;i>=0;i--){
        if (deep[p[v][i]]>=deep[u]){
            v=p[v][i];
        }
    }
    if (u==v){
        return u;
    }
    for (int i=M-1;i>=0;i--){
        if (p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}

int want;
int global_up;

bool is_pred(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

bool addshnuto[arr];

void add(int v)
{
    if (addshnuto[v]){
        return;
    }
    addshnuto[v]=1;
//    cerr<<"add :: "<<v<<"\n";
    if (global_up==0||deep[v]<deep[global_up]){
        global_up=v;
    }
    want--;
//    cerr<<"  top["<<v<<"] :: "<<top[v]<<"\n";
    sets[top[v]].insert(deep[v]);
}

int get_julia(int v)
{
    while (top[v]!=1){
        int to=top[v];
//        cerr<<"   kek chisto :: "<<v<<" "<<to<<"\n";
//        cerr<<"    size sets :: "<<len(sets[to])<<"\n";
        if (!sets[to].empty()&&*sets[to].begin()<=deep[v]){
            break;
        }
        v=p[to][0];
    }
    int to=top[v];
    if (sets[to].empty()||*sets[to].begin()>deep[v]){
        return -1;
    }

//    cerr<<"  keeeek :: "<<v<<" "<<to<<"\n";

    auto it=sets[to].upper_bound(deep[v]);
    it--;
    return vectora[to][*it-deep[to]];
}

int get_best(int v)
{
    if (is_pred(v,global_up)){
//        cerr<<"global best?"<<"\n";
        return global_up;
    }
    else{
        int lol=get_julia(v);
//        cerr<<"  v lol :: "<<v<<" "<<lol<<"\n";
        if (lol==-1){
//            cerr<<"return lca?"<<"\n";
//            cerr<<"?? :: "<<global_up<<","<<v<<"\n";
            return global_up;
        }
        else{
            return lol;
        }
    }
}

int dist(int u,int v)
{
    int l=lca(u,v);
    return deep[u]+deep[v]-2*deep[l];
}

int LOL;

int dist(int v)
{
    LOL=get_best(v);
    return dist(v,LOL);
}

void push_way(int u,int v,int l)
{
    while (u!=l){
        add(u);
        u=p[u][0];
    }
    while (v!=l){
        add(v);
        v=p[v][0];
    }
    add(l);
}

void push_way(int v)
{
    int l=lca(v,LOL);

    push_way(v,LOL,l);
}

const int buf_size=4096;
static unsigned char buf[buf_size];
int buf_pos,buf_len;

inline bool is_eof()
{
    if (buf_pos==buf_len){
        buf_pos=0;
        buf_len=fread(buf,1,buf_size,stdin);
        if (buf_len==0){
            return 1;
        }
    }
    return 0;
}

inline int get_char()
{
    return is_eof()?-1:buf[buf_pos++];
}

inline int read_char()
{
    char c=get_char();
    while (c!=-1&&c<=32){
        c=get_char();
    }
    return c;
}

inline int read_int()
{
    int m=1;
    int x=0;
    char c=read_char();
    if (c=='-'){
        m=-1;
        c=get_char();
    }
    elif (c=='+'){
        c=get_char();
    }
    while ('0'<=c&&c<='9'){
        x=x*10+(c-'0');
        c=get_char();
    }
    return x*m;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun
    /// ya dauuuuuuuuuuuuuuuuuuuuuuuuuun

    int k;

    n=read_int();
    k=read_int();
    for (int i=1;i<n;i++){
        int u,v;
        u=read_int();
        v=read_int();
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs0(1,1);
    hld(1,1);
    want=n-k;
    add(n);


    vi ans(0);
    for (int i=n-1;i>=1;i--){
        if (addshnuto[i]){
            continue;
        }
//        cerr<<"iiii :: "<<i<<"\n";
//        cerr<<dist(i)<<"\n";
//        cerr<<"LOL :: "<<LOL<<"\n";
        if (dist(i)<=want){
            push_way(i);
        }
        else{
            ans.pb(i);
        }
    }
    reverse(all(ans));
    for (auto i:ans){
        cout<<i<<" ";
    }
}