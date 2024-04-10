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

struct node
{
    int val;
    int push;

    node* l;
    node* r;

    node()
    {
        val=0;
        push=0;
        l=0;
        r=0;
    }
};

node* copy(node* u)
{
    node* buf=new node();
    node*& v=buf;
    v->val=u->val;
    v->push=u->push;
    v->l=u->l;
    v->r=u->r;
    return buf;
}

int get_val(node* v)
{
    return v?v->val:0;
}

void make_push(node*& v,int l,int r)
{
    if (!v->push){
        return;
    }

    int m=(l+r)/2;

    if (!v->l){
        v->l=new node();
    }
    else{
        v->l=copy(v->l);
    }
    v->l->val=(m-l+1)-get_val(v->l);

    if (!v->r){
        v->r=new node();
    }
    else{
        v->r=copy(v->r);
    }
    v->r->val=(r-(m+1)+1)-get_val(v->r);

    v->l->push^=1;
    v->r->push^=1;

    v->push=0;
}

void upd1(node*& v,int l,int r,int pos,int val)
{
    if (l==r){
        v->val=val;
        return;
    }

    make_push(v,l,r);
    int m=(l+r)/2;

    if (pos<=m){
        if (!v->l){
            v->l=new node();
        }
        else{
            v->l=copy(v->l);
        }
        upd1(v->l,l,m,pos,val);
    }
    else{
        if (!v->r){
            v->r=new node();
        }
        else{
            v->r=copy(v->r);
        }
        upd1(v->r,m+1,r,pos,val);
    }

    v->val=get_val(v->l)+get_val(v->r);
}

void upd2(node*& v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        v->val=(r-l+1)-v->val;
        v->push^=1;
        return;
    }

    if (!v->l){
        v->l=new node();
    }
    else{
        v->l=copy(v->l);
    }
    if (!v->r){
        v->r=new node();
    }
    else{
        v->r=copy(v->r);
    }

    make_push(v,l,r);
    int m=(l+r)/2;

    upd2(v->l,l,m,tl,tr);
    upd2(v->r,m+1,r,tl,tr);

    v->val=get_val(v->l)+get_val(v->r);
}

node* roots[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<arr;i++){
        roots[i]=new node();
    }

    int n,m,q;
    n=read_int();
    m=read_int();
    q=read_int();
    for (int i=1;i<=q;i++){
        int type;
        type=read_int();
        if (type==1){
            int x,y;
            x=read_int();
            y=read_int();
            int pos=(x-1)*m+y;

            roots[i]=copy(roots[i-1]);

            upd1(roots[i],1,n*m,pos,+1);
        }
        elif (type==2){
            int x,y;
            x=read_int();
            y=read_int();
            int pos=(x-1)*m+y;

            roots[i]=copy(roots[i-1]);

            upd1(roots[i],1,n*m,pos,0);
        }
        elif (type==3){
            int x;
            x=read_int();
            int l=(x-1)*m+1;
            int r=x*m;

            roots[i]=copy(roots[i-1]);

            upd2(roots[i],1,n*m,l,r);
        }
        elif (type==4){
            int x;
            x=read_int();

            roots[i]=copy(roots[x]);
        }
        cout<<get_val(roots[i])<<"\n";
    }
}