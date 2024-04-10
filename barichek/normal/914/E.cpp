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

#define arr (int)(2097152)

const int buf_size=4096;
unsigned char buf[buf_size];
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

int T;
pii cnt_mask[arr];

inline int upd(int mask)
{
//    cout<<"upd :: "<<mask<<"\n";
    if (cnt_mask[mask].sec<T){
        cnt_mask[mask]={0,T};
    }
    cnt_mask[mask].fir++;
}

inline int get(int mask)
{
//    cout<<"get :: "<<mask<<"\n";
    if (cnt_mask[mask].sec<T){
        cnt_mask[mask]={0,T};
    }
    return cnt_mask[mask].fir;
}

int T1;
pii cnt1[arr];

inline int upd1(int mask,int val)
{
//    cout<<"upd1 :: "<<mask<<" "<<val<<"\n";
    if (cnt1[mask].sec<T1){
        cnt1[mask]={0,T1};
    }
    cnt1[mask].fir+=val;
}

inline int get1(int mask)
{
    if (cnt1[mask].sec<T1){
        cnt1[mask]={0,T1};
    }
    return cnt1[mask].fir;
}

inline int get_num(char c)
{
    return c-'a';
}

vi reb[(int)(2e5+10)];
bool kill[arr];
int cnt[arr];

void dfs1(int now,int p=-1)
{
    cnt[now]=1;
    for (auto wh:reb[now]){
        if (!kill[wh]&&wh!=p){
            dfs1(wh,now);
            cnt[now]+=cnt[wh];
        }
    }
}

int find_c(int now,int p,int sz)
{
//    cerr<<"f :: "<<now<<" "<<p<<" "<<sz<<"\n";
    for (auto wh:reb[now]){
        if (!kill[wh]&&wh!=p){
            if (2*cnt[wh]>sz){
                return find_c(wh,now,sz);
            }
        }
    }
    return now;
}

char val[arr];

vector<pii> cur;

void dfs2(int now,int mask,int p)
{
    cur.pb({now,mask});
    for (auto wh:reb[now]){
        if (!kill[wh]&&wh!=p){
            dfs2(wh,mask^(1ll<<get_num(val[wh])),now);
        }
    }
}

int cnt2[arr];

int answer[arr];

void dfs3(int now,int p)
{
//    cout<<"dfs3 :: "<<now<<" "<<p<<"\n";
    cnt2[now]=get1(now);
    for (auto wh:reb[now]){
        if (!kill[wh]&&wh!=p){
            dfs3(wh,now);
            cnt2[now]+=cnt2[wh];
        }
    }
//    cout<<"  answer["<<now<<"] += "<<cnt2[now]<<"\n";
    answer[now]+=cnt2[now];
}

inline int get_good(int mask)
{
//    cout<<"get good :: "<<mask<<"\n";
    int res=0;
    res+=get(mask);
    for (int i=0;i<20;i++){
        res+=get(mask^(1ll<<i));
    }
    return res;
}

void build(int now)
{
//    cout<<"build :: "<<now<<"\n";
    dfs1(now);
    now=find_c(now,-1,cnt[now]);
//    cout<<"build :: "<<now<<" !!\n";

    T++;
    T1++;
    upd(0);
    for (auto wh:reb[now]){
        if (!kill[wh]){
//            cout<<"go1 :: "<<wh<<"\n";
            cur.clear();
            dfs2(wh,(1ll<<get_num(val[wh])),now);
            for (auto i:cur){
//                cout<<"pair :: "<<i.fir<<" "<<i.sec<<"\n";
                upd1(i.fir,get_good(i.sec^(1ll<<get_num(val[now]))));
            }
            dfs3(wh,now);
            answer[now]+=cnt2[wh]; /// only here
//            cout<<"    answerrr :: "<<now<<" "<<cnt2[wh]<<"\n";

            for (auto i:cur){
                upd(i.sec);
            }
        }
    }

    reverse(all(reb[now]));

    T++;
    T1++;
//    upd(0);
    for (auto wh:reb[now]){
        if (!kill[wh]){
//            cout<<"go2 :: "<<wh<<"\n";
            cur.clear();
            dfs2(wh,(1ll<<get_num(val[wh])),now);
            for (auto i:cur){
//                cout<<"pair :: "<<i.fir<<" "<<i.sec<<"\n";
                upd1(i.fir,get_good(i.sec^(1ll<<get_num(val[now]))));
            }
            dfs3(wh,now);
            /// answer[now]+=cnt2[wh]; /// only not here :)

            for (auto i:cur){
                upd(i.sec);
            }
        }
    }

    kill[now]=1;

    for (auto wh:reb[now]){
        if (!kill[wh]){
            build(wh);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    n=read_int();
    for (int i=1;i<n;i++){
        int u,v;
        u=read_int();
        v=read_int();
        reb[u].pb(v);
        reb[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        val[i]=read_char();
//        cout<<val[i]<<" !!\n";
    }
    build(1);
    for (int i=1;i<=n;i++){
        cout<<answer[i]+1<<" ";
    }
    cout<<"\n";
}