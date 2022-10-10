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
#define sz(x) (int)(x).size()
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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;

static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < N) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}
	T query(int a, int b) {
        b++;
        if(a==b)
            return INF;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    RMQ<lli> *rr;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

struct node{
    lli mn;
    lli lz;
    node *l,*r;
    node(lli c=0):mn(c),lz(INF),l(NULL),r(NULL){};
};

node* rmqQuery(lli l,lli r)
{
    lli v=l/n;
    l-=v*n;r-=v*n;
    r=min(r,2*n-1);
    return new node(rr->query(l,r));
}

void push(node *nd)
{
    const lli x=nd->lz;
    
    if(x==INF)
        return;
    
    if(nd->l==NULL)
        nd->l=new node(x);
    
    if(nd->r==NULL)
        nd->r=new node(x);
    
    nd->l->mn=min(nd->l->mn,x);
    nd->l->lz=min(nd->l->lz,x);
    nd->r->mn=min(nd->r->mn,x);
    nd->r->lz=min(nd->r->lz,x);

    nd->lz=INF;
}

node* update(node* nd,lli l,lli r,lli L,lli R,lli x)
{
    if(nd==NULL)
        nd=rmqQuery(l,r);

    if(r<L||R<l)
        return nd;
    
    if(L<=l&&r<=R)
    {
        nd->mn=nd->lz=x;
        dbg("up",l,r);
        nd->l=nd->r=NULL;
        return nd;
    }

    push(nd);
    lli m=(l+r)/2;
    nd->l=update(nd->l,l,m,L,R,x);
    nd->r=update(nd->r,m+1,r,L,R,x);
    nd->mn=min( nd->l==NULL?INF:nd->l->mn , nd->r==NULL?INF:nd->r->mn);
    return nd;
}

lli query(node* &nd,lli l,lli r,lli L,lli R)
{
    if(R<l||r<L)
        return INF;

    if(nd==NULL)
        nd=rmqQuery(l,r);

    if(L<=l&&r<=R)
    {
        dbg(l,r,nd->mn);
        return nd->mn;
    }

    push(nd);
    lli m=(l+r)/2;
    return min(query(nd->l,l,m,L,R),query(nd->r,m+1,r,L,R));
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    fo(i,n)
        a.pb(a[i]);

    rr=new RMQ<lli>(a);
    lli q;
    cin>>q;

    node *rt=NULL;

    while(q--){
        cin>>T>>l>>r;
        l--;r--;
        if(T==1)
        {
            cin>>x;
            dbg(l,r,x);
            rt=update(rt,0,n*k-1,l,r,x);
        }
        else
        {
            dbg(l,r);
            cout<<query(rt,0,n*k-1,l,r)<<endl;
        }
    }

}   aryanc403();
    return 0;
}