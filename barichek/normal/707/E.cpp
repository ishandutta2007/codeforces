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

inline string read_string()
{
    string s="";
    char c=read_char();
    while (c!=-1&&c>32){
        s+=c;
        c=get_char();
    }
    return s;
}

int f[ar][ar];

void upd(int x,int y,int val)
{
    for (int i=x;i<ar;i|=i+1){
        for (int j=y;j<ar;j|=j+1){
            f[i][j]+=val;
        }
    }
}

int get(int x,int y)
{
    int res=0;
    for (int i=x;i>=0;i&=i+1,i--){
        for (int j=y;j>=0;j&=j+1,j--){
            res+=f[i][j];
        }
    }
    return res;
}

int get(int x1,int y1,int x2,int y2)
{
    int res=0;

    res+=get(x2,y2);

    res-=get(x1-1,y2);
    res-=get(x2,y1-1);

    res+=get(x1-1,y1-1);

    return res;
}

bool is[ar];
int ans[ar];
vector<pair<pii,int>> g[ar];
vi qq[ar];
int num;
int x1[ar];
int y1[ar];
int x2[ar];
int y2[ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    n=read_int();
    m=read_int();
    k=read_int();
    for (int i=1;i<=k;i++){
        is[i]=1;
        int l;
        l=read_int();
        while (l--){
            int x,y,w;
            x=read_int();
            y=read_int();
            w=read_int();
            g[i].pb({{x,y},w});
        }
    }
    int q;
    q=read_int();
    while (q--){
        string s;
        s=read_string();
        if (s=="ASK"){
            x1[num]=read_int();
            y1[num]=read_int();
            x2[num]=read_int();
            y2[num]=read_int();
            for (int i=1;i<=k;i++){
                if (is[i]){
                    qq[i].pb(num);
                }
            }
            num++;
        }
        else{
            int id;
            id=read_int();
            is[id]^=1;
        }
    }
    for (int i=1;i<=k;i++){
        for (auto j:g[i]){
            upd(j.fir.fir,j.fir.sec,j.sec);
        }

        for (auto j:qq[i]){
            ans[j]+=get(x1[j],y1[j],x2[j],y2[j]);
        }

        for (auto j:g[i]){
            upd(j.fir.fir,j.fir.sec,-j.sec);
        }
    }
    for (int i=0;i<num;i++){
        cout<<ans[i]<<"\n";
    }
}