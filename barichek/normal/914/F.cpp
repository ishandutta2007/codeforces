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

char s[arr];
char t[arr];
int sz;
ll h[11][arr];

void read_t()
{
    sz=0;
    char c=read_char();
    while (c!=-1&&c>32){
        t[sz++]=c;
        c=get_char();
    }
}

ll p[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    p[0]=1;
    for (int i=1;i<arr;i++){
        p[i]=p[i-1]*35%md;
    }

    read_t();
    int n=sz;
    for (int i=0;i<n;i++){
        s[i]=t[i];
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=10&&i+j-1<n;j++){
            h[j][i]=(h[j-1][i]+1ll*(s[i+j-1]-'a'+1)*p[j-1])%md;
        }
    }
    int q;
    q=read_int();
    while (q--){
        int type;
        type=read_int();
        if (type==1){
            int id;
            char c;
            id=read_int();
            id--;
            c=read_char();
            s[id]=c;
            for (int i=max(0,id-9);i<=id;i++){
                h[1][i]=s[i]-'a'+1;
                for (int j=2;j<=10;j++){
                    h[j][i]=(h[j-1][i]+1ll*(s[i+j-1]-'a'+1)*p[j-1])%md;
                }
            }
        }
        else{
            int l,r;
            l=read_int();
            r=read_int();
            l--;
            r--;
            read_t();
            int n=r-l+1;
            if (sz<=10){
                ll want_hash=0;
                int ans=0;
                for (int i=0;i<sz;i++){
                    want_hash=(want_hash+1ll*(t[i]-'a'+1)*p[i])%md;
                }
                ll* p=h[sz]+l;
                int cnt=(r-sz+1)-l+1;
                for (int i=0;i<cnt;i++){
                    ans+=(p[i]==want_hash);
                }
                cout<<ans<<"\n";
            }
            else{
                n=n-sz+1;
                int ans=0;
                char* ss=s+l;
                for (int i=0;i<n;i++){
                    bool ok=1;

                    int* sss=(int*)ss;
                    int* ttt=(int*)t;
                    for (int j=0;j<sz/4;j++){
                        if (sss[j]!=ttt[j]){
                            ok=0;
                            break;
                        }
                    }
                    for (int j=sz-sz%4;j<sz;j++){
                        if (ss[j]!=t[j]){
                            ok=0;
                        }
                    }
                    if (ok){
                        ans++;
                    }
                    ss++;
                }
                cout<<ans<<"\n";
            }
        }
    }
}