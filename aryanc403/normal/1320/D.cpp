/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1500000767;
const lli B = 107L;
const lli Binv = 981308913;

vi pw;

lli po(lli a,lli n)
{
    if(n==0)
        return 1;
    if(n%2)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

struct node{
    lli fs,ls;
    lli h,len;
    node():h(0),fs(0),ls(0),len(0){};
    node(char x){
        h=fs=ls=x;
        len=1;
    }
    void rmf(){
        assert(len>0);
        assert(fs=='1');
        fs=0;
        len--;
        h-='1'*pw[len];
        h=(h%mod+mod)%mod;
    }
    
    void rml(){
        assert(len>0);
        assert(ls=='1');
        h-='1';
        h=(h*Binv)%mod;
        h=(h+mod)%mod;
        ls=0;
        len--;
    }
};

node merge(node a,node b)
{
    if(a.len==0)
        return b;
    if(b.len==0)
        return a;
    node ans;
    if(a.ls=='1'&&b.fs=='1')
    {
        a.rml();
        b.rmf();
    }


    if(a.len==0)
        return b;
    if(b.len==0)
        return a;

    ans.h=(a.h*po(B,b.len)%mod+b.h)%mod;
    ans.h=(ans.h+mod)%mod;
    ans.len=a.len+b.len;
    ans.fs=a.fs;
    ans.ls=b.ls;
    return ans;
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s,te,to;
    vi a;
    vector<node> f;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

// string gt(lli l,lli r)
// {
//     string t="#";
//     lli i;
//     repA(i,l,r)
//     {
//         if(t.back()=='1'&&s[i]=='1')
//             t.pop_back();
//         else
//             t+=s[i];
//     }

//     return t;
// }

void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        f[id]=node(s[l]);
        return;
    }

    lli m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    f[id]=merge(f[2*id],f[2*id+1]);
}

node query(lli id,lli l,lli r,lli L,lli R)
{
    if(r<L||R<l)
        return node();
    if(L<=l&&r<=R)
        return f[id];
    lli m=(l+r)/2;
    return merge(query(2*id,l,m,L,R),query(2*id+1,m+1,r,L,R));
}

lli gt(lli l,lli r)
{
    lli h=query(1,0,n+1,l,r).h;
    h=(h%mod+mod)%mod;
    return h;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;

    pw.pb(1);
    repA(i,1,n+10)
        pw.pb(pw.back()*B%mod);

    a.resize(n+1,-1);
    cin>>s;
    s="#"+s+"#";

    f.resize(4*n+10);
    build(1,0,n+1);

    lli q;
    cin>>q;
    while(q--)
    {
        lli l1,l2,len;
        cin>>l1>>l2>>len;
        cout<<(gt(l1,l1+len-1)==gt(l2,l2+len-1)?"YES":"NO")<<endl;
    }

}   aryanc403();
    return 0;
}