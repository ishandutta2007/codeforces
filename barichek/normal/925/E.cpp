#pragma GCC optimize("O3")
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

const int buf_size=4096;
int buf_pos,buf_len;
unsigned char buf[buf_size];

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
    int c=get_char();
    while (c!=-1&&c<=32){
        c=get_char();
    }
    return c;
}

inline int read_int()
{
    int x=0;
    int c=read_char();
    int m=1;
    if (c=='-'){
        m=-1;
        c=get_char();
    }
    while ('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=get_char();
    }
    return x*m;
}

int my_top[arr];
int s[arr];
int t[arr];
int where_go[arr];
int pred[arr];
vi reb[arr];

int pos[arr];
int last_pos=0;
int a[arr];

int n,m;
int ans=0;

void foo(int* a,int n,int d)
{
    if (d==1){
        for (int i=0;i<n;i++){
            a[i]++;
            ans+=(a[i]==1);
        }
    }
    else{
        for (int i=0;i<n;i++){
            a[i]--;
            ans-=(a[i]==0);
        }
    }
}

void dooo(int q,int d)
{
    while (q!=-1){
        int top=my_top[q];
        foo(a+pos[top],pos[q]-pos[top]+1,d);
        q=pred[top];
    }
}

void work(int q)
{
    if (q>0){
        if (a[pos[q]]>0){
            ans--;
        }
        a[pos[q]]-=md;
        dooo(pred[q],1);
    }
    else{
        q=-q;
        a[pos[q]]+=md;
        if (a[pos[q]]>0){
            ans++;
        }
        dooo(pred[q],-1);
    }
}

void dfs1(int now,int p=-1)
{
    pred[now]=p;
    s[now]=1;
    for (auto wh:reb[now]){
        if (wh!=p){
            dfs1(wh,now);
            s[now]+=s[wh];
            if (where_go[now]==0||s[where_go[now]]<s[wh]){
                where_go[now]=wh;
            }
        }
    }
}

void dfs2(int now,int p=-1)
{
    if (!my_top[now]){
        my_top[now]=now;
    }

    pos[now]=last_pos++;

    if (where_go[now]){
        my_top[where_go[now]]=my_top[now];
        dfs2(where_go[now],now);
    }

    for (auto wh:reb[now]){
        if (wh!=p&&wh!=where_go[now]){
            dfs2(wh,now);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    n=read_int();
    m=read_int();
    for (int i=2;i<=n;i++){
        int u;
        u=read_int();
        reb[u].pb(i);
        reb[i].pb(u);
    }
    for (int i=1;i<=n;i++){
        t[i]=read_int();
    }
    dfs1(1);
    dfs2(1);
    for (int i=1;i<=n;i++){
        a[pos[i]]=-t[i];
    }
    while (m--){
        int q;
        q=read_int();
        work(q);
        cout<<ans<<" ";
    }
    cout<<"\n";
}