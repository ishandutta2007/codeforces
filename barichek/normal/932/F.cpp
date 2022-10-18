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

typedef int type;

struct line
{
    /// k*x+b
    type k,b;
    set<line>::iterator it;
    set<line>* where;

    line()
    {
        this->k=0;
        this->b=0;
    }
    line(type k,type b)
    {
        this->k=k;
        this->b=b;
    }
    template<typename type_x> type_x eval(type_x x)
    {
        return k*x+b;
    }
};

bool operator<(const line& lhs,const line& rhs)
{
    if (rhs.k==5e18){
        auto it=lhs.it;
        return next(it)!=lhs.where->end()&&(next(it)->k*rhs.b+next(it)->b<=it->k*rhs.b+it->b);
    }
    return lhs.k>rhs.k||(lhs.k==rhs.k&&lhs.b<rhs.b);
}

inline ld intersect(const line& l1,const line& l2)
{
    return ld(l1.b-l2.b)/(l2.k-l1.k);
}

bool to_erase(line l1,line l2,line l3)
{
    ld x=intersect(l1,l3);
    return l2.eval(x)>=l1.eval(x);
}

struct convex_hull_trick
{
    set<line> lines;

    convex_hull_trick()
    {
        lines.clear();
    }

    void clear()
    {
        lines.clear();
    }

    void add_line(line l)
    {
        auto it=lines.insert(l).fir;
        line* what=(line*)&*it;
        what->it=it;
        what->where=(set<line>*)&lines;

        if (it!=lines.begin()&&next(it)!=lines.end()&&to_erase(*prev(it),*it,*next(it))){
            lines.erase(it);
            return;
        }

        while (it!=lines.begin()&&prev(it)!=lines.begin()&&to_erase(*prev(prev(it)),*prev(it),*it)){
            lines.erase(prev(it));
        }

        while (next(it)!=lines.end()&&next(next(it))!=lines.end()&&to_erase(*it,*next(it),*next(next(it)))){
            lines.erase(next(it));
        }
    }
    type get(type x)
    {
        if (lines.empty()){
            return 5e18;
        }
        line buf=*lines.lower_bound(line(5e18,x));
        return buf.eval(x);
    }
};

#define arr (int)(1e5+10)

convex_hull_trick t[4*arr];
line lines[arr];
line line_for_update;

void upd(int v,int l,int r,int pos)
{
    t[v].add_line(line_for_update);
    if (l==r){
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        upd(v*2,l,m,pos);
    }
    else{
        upd(v*2+1,m+1,r,pos);
    }
}

int get(int v,int l,int r,int tl,int tr,int x)
{
    if (l>tr||r<tl){
        return 2e18;
    }
    if (l>=tl&&r<=tr){
        return t[v].get(x);
    }
    int m=(l+r)/2;
    return min(get(v*2,l,m,tl,tr,x),get(v*2+1,m+1,r,tl,tr,x));
}

int n;
int tin[arr];
int tout[arr];
vi reb[arr];
int timer;
int a[arr];
int b[arr];
int dp[arr];

void dfs1(int now,int pred)
{
    tin[now]=++timer;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs1(wh,now);
        }
    }
    tout[now]=timer;
}

void dfs2(int now,int pred)
{
    int cnt_go=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs2(wh,now);
            cnt_go++;
        }
    }
    if (cnt_go==0){
        dp[now]=0;
    }
    else{
        dp[now]=get(1,1,n,tin[now]+1,tout[now],a[now]);
    }
    line_for_update=*new line(b[now],dp[now]);
    upd(1,1,n,tin[now]);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    n=read_int();
    for (int i=1;i<=n;i++){
        a[i]=read_int();
    }
    for (int i=1;i<=n;i++){
        b[i]=read_int();
    }
    for (int i=1;i<n;i++){
        int u,v;
        u=read_int();
        v=read_int();
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for (int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
}