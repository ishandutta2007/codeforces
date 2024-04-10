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

#define arr (int)(4e5+10)

int mx[arr][20];
int p[arr][20];
int sum_p[arr][20];
int pred[arr][20];
int cnt=1;
int WW[arr];

void dooo(int R,int W)
{
    int cur=(++cnt);
    pred[cur][0]=R;
    WW[cur]=W;
    for (int i=1;i<20;i++){
        pred[cur][i]=pred[pred[cur][i-1]][i-1];
    }
    mx[cur][0]=WW[R];
    for (int i=1;i<20;i++){
        mx[cur][i]=max(mx[cur][i-1],mx[pred[cur][i-1]][i-1]); /// here bug (mayby)
    }
    int kek=cur;
    for (int i=19;i>=0;i--){
        if (mx[kek][i]<W){
            kek=pred[kek][i];
        }
    }

    kek=pred[kek][0];
    p[cur][0]=kek;
    for (int i=1;i<20;i++){
        p[cur][i]=p[p[cur][i-1]][i-1];
    }
    sum_p[cur][0]=WW[kek];
    for (int i=1;i<20;i++){
        sum_p[cur][i]=sum_p[cur][i-1]+sum_p[p[cur][i-1]][i-1];
        if (sum_p[cur][i]>1e18){
            sum_p[cur][i]=1e18;
        }
    }
}

int get_ans(int R,int X)
{
    if (WW[R]>X){
        return 0;
    }
    X-=WW[R];
    int res=1;
    int cur=R;
    for (int i=19;i>=0;i--){
        if (sum_p[cur][i]<=X){
            res+=(1ll<<i);
            X-=sum_p[cur][i];
            cur=p[cur][i];
        }
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    WW[0]=1e18;
    for (int i=0;i<20;i++){
        mx[0][i]=1e18;
    }

    for (int i=0;i<20;i++){
        pred[1][i]=0;
        mx[1][i]=1e18;
        sum_p[1][i]=1e18;
        p[1][i]=0;
    }

    int q;
    q=read_int();
    int last=0;
    while (q--){
        int type,p,q;
        type=read_int();
        p=read_int();
        q=read_int();
        if (type==1){
            int R=p^last;
            int W=q^last;
            dooo(R,W);
        }
        else{
            int R=p^last;
            int X=q^last;
            cout<<(last=get_ans(R,X))<<"\n";
        }
    }
}