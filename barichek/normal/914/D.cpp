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

#define arr (int)(1e7+10)

int t[arr];

void upd(int v,int l,int r,int pos,int val)
{
    if (l==r){
        t[v]=val;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        upd(v*2,l,m,pos,val);
    }
    else{
        upd(v*2+1,m+1,r,pos,val);
    }
    t[v]=__gcd(t[v*2],t[v*2+1]);
}

int a[arr];

void build(int v,int l,int r)
{
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m+1,r);
    t[v]=__gcd(t[v*2],t[v*2+1]);
}

int x;
bool ok;
int bad;
int L,R;

void gama(int v,int l,int r,int tl,int tr)
{
//    cerr<<"gama :: "<<v<<" || "<<l<<" "<<r<<"\n";
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
//        cerr<<"i am here"<<"\n";
        if (t[v]%x!=0){
            if (bad!=-1){
                ok=0;
            }
            bad=v;
            L=l;
            R=r;
        }
        return;
    }
    int m=(l+r)/2;
    gama(v*2,l,m,tl,tr);
    gama(v*2+1,m+1,r,tl,tr);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    n=read_int();
    for (int i=1;i<=n;i++){
        a[i]=read_int();
    }
    build(1,1,n);
    int q;
    q=read_int();
    while (q--){
        int type;
        type=read_int();
//        cerr<<type<<"\n";
        if (type==1){
            int l,r;
            l=read_int();
            r=read_int();
            x=read_int();

            ok=1;
            bad=-1;
            gama(1,1,n,l,r);

//            cerr<<ok<<" "<<bad<<" !!!!\n";

            if (!ok){
                cout<<"NO"<<"\n";
                continue;
            }
            if (bad==-1){
                cout<<"YES"<<"\n";
                continue;
            }
            bool flag=1;
            while (L!=R){
                if (t[bad*2]%x!=0&&t[bad*2+1]%x!=0){
                    flag=0;
                    break;
                }
                int m=(L+R)/2;
                if (t[bad*2]%x!=0){
                    bad=bad*2;
                    R=m;
                }
                else{
                    bad=bad*2+1;
                    L=m+1;
                }
            }
            cout<<(flag?"YES":"NO")<<"\n";
        }
        else{
            int id,y;
            id=read_int();
            y=read_int();
            upd(1,1,n,id,y);
        }
    }
}