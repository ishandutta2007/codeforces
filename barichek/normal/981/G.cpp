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

//#define cout cerr

#define md (int)(998244353)

int mult(int a,int b)
{
    return a*b%md;
}

int sum(int a,int b)
{
    return (a+b)%md;
}

struct segment_tree
{
    int n;
    vi t;
    vi to_add;
    vi to_mult;

    segment_tree()
    {
        n=0;
        t.clear();
        to_add.clear();
        to_mult.clear();
    }
    segment_tree(int n)
    {
        n++;
        this->n=n;
        t.assign(4*n,0);
        to_add.assign(4*n,0);
        to_mult.assign(4*n,1);
    }

    void push(int v,int l,int r)
    {
        int m=(l+r)/2;

        /// left
        t[v*2]=mult(t[v*2],to_mult[v]);
        to_mult[v*2]=mult(to_mult[v*2],to_mult[v]);

        to_add[v*2]=mult(to_add[v*2],to_mult[v]);

        t[v*2]=sum(t[v*2],mult(to_add[v],(m-l+1)));

        to_add[v*2]=sum(to_add[v*2],to_add[v]);

        /// right
        t[v*2+1]=mult(t[v*2+1],to_mult[v]);
        to_mult[v*2+1]=mult(to_mult[v*2+1],to_mult[v]);

        to_add[v*2+1]=mult(to_add[v*2+1],to_mult[v]);

        t[v*2+1]=sum(t[v*2+1],mult(to_add[v],(r-(m+1)+1)));

        to_add[v*2+1]=sum(to_add[v*2+1],to_add[v]);

        to_add[v]=0;
        to_mult[v]=1;
    }

    void upd_add(int v,int l,int r,int tl,int tr,int val)
    {
//        cout<<"upd_add :: "<<v<<" || "<<l<<" "<<r<<" || "<<tl<<" "<<tr<<"\n";
        if (l>tr||r<tl){
            return;
        }
        if (l>=tl&&r<=tr){
            t[v]=sum(t[v],mult((r-l+1),val));
            to_add[v]=sum(to_add[v],val);
            return;
        }
        push(v,l,r);
        int m=(l+r)/2;
        upd_add(v*2,l,m,tl,tr,val);
        upd_add(v*2+1,m+1,r,tl,tr,val);
        t[v]=sum(t[v*2],t[v*2+1]);
    }

    void upd_add(int tl,int tr,int val)
    {
        if (tl>tr){
            return;
        }
        upd_add(1,1,n,tl,tr,val);
    }

    void upd_mult(int v,int l,int r,int tl,int tr,int val)
    {
        if (l>tr||r<tl){
            return;
        }
        if (l>=tl&&r<=tr){
            t[v]=mult(t[v],val);
            to_add[v]=mult(to_add[v],val);
            to_mult[v]=mult(to_mult[v],val);
            return;
        }
        push(v,l,r);
        int m=(l+r)/2;
        upd_mult(v*2,l,m,tl,tr,val);
        upd_mult(v*2+1,m+1,r,tl,tr,val);
        t[v]=sum(t[v*2],t[v*2+1]);
    }

    void upd_mult(int tl,int tr,int val)
    {
        if (tl>tr){
            return;
        }
        upd_mult(1,1,n,tl,tr,val);
    }

    int get(int v,int l,int r,int tl,int tr)
    {
        if (l>tr||r<tl){
            return 0;
        }
        if (l>=tl&&r<=tr){
            return t[v];
        }
        push(v,l,r);
        int m=(l+r)/2;
        return sum(
                   get(v*2,l,m,tl,tr),
                   get(v*2+1,m+1,r,tl,tr)
                   );
    }

    int get(int tl,int tr)
    {
        return get(1,1,n,tl,tr);
    }
};

segment_tree S(arr);

struct kek
{
    set<pii> seg;

    kek()
    {
        seg.clear();
    }

    void add(pii cur)
    {
        auto it=seg.lower_bound({cur.fir,-1e9});
        int L=cur.fir;
        int R=cur.sec;
        int add_L=L;
        int add_R=R;
        int last=L-1;
        vector<pii> to_del(0);
        if (it!=seg.begin()&&prev(it)->sec>=L){
            if (prev(it)->sec>=R){
                S.upd_mult(L,R,2);
                return;
            }
            S.upd_mult(L,prev(it)->sec,2);
            to_del.pb(*prev(it));
            add_L=prev(it)->fir;
            last=prev(it)->sec;
        }
        while (last+1<=R){
//            cout<<"last R :: "<<last<<" "<<R<<"\n";
            if (it==seg.end()){
                S.upd_add(last+1,R,+1);
                last=R;
            }
            else{
                if (last+1<it->fir){
                    if (R<it->fir){
                        S.upd_add(last+1,R,+1);
                        last=R;
                    }
                    else{
                        S.upd_add(last+1,it->fir-1,+1);
                        last=it->fir-1;
                    }
                }
                else{
                    if (R<it->sec){
                        S.upd_mult(last+1,R,2);
                        last=R;
                        add_R=it->sec;
                        to_del.pb(*it);
                        it++;
                    }
                    else{
                        S.upd_mult(last+1,it->sec,2);
                        last=it->sec;
                        to_del.pb(*it);
                        it++;
                    }
                }
            }
        }
        for (auto i:to_del){
            seg.erase(i);
        }
        seg.insert({add_L,add_R});
    }
};

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

kek KEK[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,q;
    n=read_int();
    q=read_int();
    while (q--){
        int type;
        type=read_int();
//        cout<<"type :: "<<type<<"\n";
        if (type==1){
            int l,r,x;
            l=read_int();
            r=read_int();
            x=read_int();
            KEK[x].add({l,r});
        }
        else{
            int l,r;
            l=read_int();
            r=read_int();
            int ans=S.get(l,r);
            cout<<ans<<"\n";
        }
    }
}