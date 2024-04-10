//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

#define arr (int)(4e5+10)

struct node
{
    map<char,int> next;
    map<char,int> go;
    int link;
    int pred;
    int pred_go;

    node()
    {
        next.clear();
        go.clear();
        link=-1;
        pred=-1;
        pred_go=-1;
    }
};

node V[arr];
int last=0;

int ver_request[arr];

void add_string(const string& s,int id)
{
//    cout<<"add_string :: "<<s<<" !!!\n";
    int cur=0;
    for (auto i:s){
        if (!V[cur].next.count(i)){
            last++;

            V[cur].next[i]=last;

            V[last].pred=cur;
            V[last].pred_go=i;
        }
        cur=V[cur].next[i];
    }
    ver_request[id]=cur;
}

int get_go(int v,char c);

int get_link(int v)
{
    if (V[v].link==-1){
        if (v==0||V[v].pred==0){
            V[v].link=0;
        }
        else{
            V[v].link=get_go(get_link(V[v].pred),V[v].pred_go);
        }
    }
    return V[v].link;
}

int get_go(int v,char c)
{
    if (!V[v].go.count(c)){
        if (V[v].next.count(c)){
            V[v].go[c]=V[v].next[c];
        }
        else{
            V[v].go[c]=(v==0?0:get_go(get_link(v),c));
        }
    }
    return V[v].go[c];
}

vector<pair<int,char>> reb1[arr];

int F[arr];

void updF(int pos,int val)
{
    for (int i=pos;i<arr;i|=i+1){
        F[i]+=val;
    }
}

int getF(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=F[i];
    }
    return res;
}

int getF(int l,int r)
{
    if (l>r){
        return 0;
    }
    return getF(r)-getF(l-1);
}

//int naive_ans[arr];

int tin[arr];
int tout[arr];
int T=0;

void upd_on_way_to_root(int ver,int value)
{
    updF(tin[ver],value);
//    while (ver!=0){
//        naive_ans[ver]+=value;
//        ver=get_link(ver);
//    }
}

int sum_in_subtree(int ver)
{
    return getF(tin[ver],tout[ver]);
//    return naive_ans[ver];
}

int ans[arr];
vector<int> vh[arr];

void dfs1(int now,int ver)
{
//    cout<<now<<" :: "<<ver<<" !!\n";
    upd_on_way_to_root(ver,+1);
    for (auto q:vh[now]){
        ans[q]=sum_in_subtree(ver_request[q]);
    }

    for (auto wh:reb1[now]){
        dfs1(wh.fir,get_go(ver,wh.sec));
    }
    upd_on_way_to_root(ver,-1);
}

vector<int> reb2[arr];

void dfs2(int now)
{
    tin[now]=++T;
    for (auto wh:reb2[now]){
        dfs2(wh);
    }
    tout[now]=T;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int type;
        cin>>type;
        if (type==1){
            char c;
            cin>>c;
            reb1[0].pb(mp(i,c));
        }
        else{
            int from;
            char c;
            cin>>from>>c;
            reb1[from].pb(mp(i,c));
        }
    }
    int m;
    cin>>m;
    for (int i=1;i<=m;i++){
        int from;
        string t;
        cin>>from>>t;
        add_string(t,i);
        vh[from].pb(i);
    }
    for (int i=1;i<=last;i++){
//        cout<<"link :: "<<get_link(i)<<" "<<i<<"\n";
        reb2[get_link(i)].pb(i);
    }
    dfs2(0);

    dfs1(0,0);

    for (int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }
}