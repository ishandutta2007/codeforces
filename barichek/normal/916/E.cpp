#pragma GCC optimize("O3")
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

const int buf_size=4096;

static unsigned char buf[buf_size];

static int buf_pos,buf_len;

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

int t[5*arr];
int push[5*arr];

int n;
vi reb[arr];

int tin[arr];
int tout[arr];
int timer;

int p[arr][20];
int deep[arr];

int f1[arr];
int f2[arr];

void upd(int pos,int val1,int val2)
{
    for (int i=pos;i<arr;i|=i+1){
        f1[i]+=val1;
        f2[i]+=val2;
    }
}

void upd(int v,int l,int r,int tl,int tr,int val)
{
    upd(tl,+val,-val*(tl-1));
    upd(tr,-val,val*tr);
}

int get(int pos)
{
    int sum1=0;
    int sum2=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        sum1+=f1[i];
        sum2+=f2[i];
    }
    return sum1*pos+sum2;
}

int get(int v,int l,int r,int tl,int tr)
{
    return get(tr)-get(tl-1);
}

void dfs(int now,int pred)
{
    tin[now]=++timer;
    p[now][0]=pred;
    for (auto wh:reb[now]){
        if (wh!=pred){
            deep[wh]=deep[now]+1;
            dfs(wh,now);
        }
    }
    tout[now]=timer;
}

bool is_pred(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int init()
{
    for (int j=1;j<20;j++){
        for (int i=1;i<=n;i++){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}

inline int lca(int u,int v)
{
    if (deep[u]>deep[v]){
        swap(u,v);
    }
    for (int i=19;i>=0;i--){
        if (deep[p[v][i]]>=deep[u]){
            v=p[v][i];
        }
    }
    if (u==v){
        return u;
    }
    for (int i=19;i>=0;i--){
        if (p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}

int root=1;

int get_next(int u,int v)
{
    for (int i=19;i>=0;i--){
        int to=p[v][i];
        if (!is_pred(to,u)){
            v=to;
        }
    }
    return v;
}

int real_lca(int u,int v)
{
    int l=lca(u,v);
    if (!is_pred(l,root)){
        return l;
    }
    if (is_pred(root,u)||is_pred(root,v)){
        return root;
    }
    int res=root;
    for (int i=19;i>=0;i--){
        int to=p[res][i];
        if (is_pred(l,to)&&!is_pred(to,u)&&!is_pred(to,v)){
            res=to;
        }
    }
    return p[res][0];
}

void real_push(int v,int x)
{
    if (v==root){
        return void(upd(1,1,n,1,n,x));
    }
    if (!is_pred(v,root)){
//        cout<<"i will real push to :: "<<tin[v]<<" "<<tout[v]<<"\n";
        return upd(1,1,n,tin[v],tout[v],x);
    }
    upd(1,1,n,1,n,x);
    int kek=get_next(v,root);
    upd(1,1,n,tin[kek],tout[kek],-x);
}

int real_get(int v)
{
    if (v==root){
        return get(1,1,n,1,n);
    }
    if (!is_pred(v,root)){
//        cout<<"i will real get from :: "<<tin[v]<<" "<<tout[v]<<"\n";
        return get(1,1,n,tin[v],tout[v]);
    }
    int res=0;
    res+=get(1,1,n,1,n);
    int kek=get_next(v,root);
    res-=get(1,1,n,tin[kek],tout[kek]);
    return res;
}

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int q;
    n=read_int();
    q=read_int();
    for (int i=1;i<=n;i++){
        a[i]=read_int();
    }
    for (int i=1;i<n;i++){
        int u,v;
        u=read_int();
        v=read_int();
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(1,1);
    init();

    for (int i=1;i<=n;i++){
        upd(1,1,n,tin[i],tin[i],a[i]);
    }

    while (q--){
        int type;
        type=read_int();
//        cout<<"type :: "<<type<<"\n";
        if (type==1){
            int v;
            v=read_int();
            root=v;
        }
        elif (type==2){
            int u,v,x;
            u=read_int();
            v=read_int();
            x=read_int();
            int l=real_lca(u,v);
//            cout<<"real_lca :: "<<l<<"\n";
            real_push(l,x);
        }
        else{
            int v;
            v=read_int();
            cout<<real_get(v)<<"\n";
        }
    }
}