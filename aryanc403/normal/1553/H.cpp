/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

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
// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}
vi gen(lli n){
    if(n==0){
        return {0,1};
    }
    auto b=gen(n-1);
    vi a;
    for(auto x:b)
        a.pb(2*x);
    reverse(all(b));
    for(auto x:b)
        a.pb(2*x+1);
    return a;
}

struct Node{
    Node *l,*r;
    lli L,R,ans;
    lli size;
    Node(lli s=0):l(NULL),r(NULL),L(INF),R(-INF),ans(INF),size(s){};
};

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli n,k;
    cin>>n>>k;
    const lli lim=(1LL<<k);
    vector<bool> vis(lim);
    for(lli i=0;i<n;++i){
        lli in;
        cin>>in;
        vis[in]=true;
    }

    auto merge=[&](Node *nd,Node *l,Node *r)->Node*{
        nd->l=l;
        nd->r=r;
        nd->ans=min({l->ans,r->ans,(r->L)+(l->size)-(l->R)});
        nd->L=min(l->L,(r->L)+(l->size));
        nd->R=max(l->R,(r->R)+(l->size));
        return nd;
    };

    auto root=y_combinator([&](const auto &build,lli l,lli r)->Node*{
        Node *nd=new Node(r-l+1);
        if(l==r){
            if(vis[l])
                nd->L=nd->R=0;
            nd->ans=INF;
            // dbg(l,nd->L,nd->R);
            return nd;
        }
        const lli mid=(l+r)>>1;
        nd->l=build(l,mid);
        nd->r=build(mid+1,r);
        nd=merge(nd,nd->l,nd->r);
        return nd;
    })(0,lim-1);

    auto lazyFlip=y_combinator([&](const auto &flip,Node *nd,lli depth)->Node*{
        if(depth==k-1)
        {
            swap(nd->l,nd->r);
            nd=merge(nd,nd->l,nd->r);
            return nd;
        }
        nd->l=flip(nd->l,depth+1);
        nd->r=flip(nd->r,depth+1);
        nd=merge(nd,nd->l,nd->r);
        return nd;
    });

    vi cc;
    auto prtRun=y_combinator([&](const auto &build,Node *nd,lli l,lli r)->void{
        if(l==r){
            if(nd->L==0)
                cc.pb(l);
            return;
        }
        const lli mid=(l+r)>>1;
        build(nd->l,l,mid);
        build(nd->r,mid+1,r);
        return;
    });

    auto prt=[&](Node *nd)->void{
        cc.clear();
        prtRun(nd,0,lim-1);
    };


    vi height(lim,-1);
    for(lli i=0;i<k;++i)
        height[1<<i]=i;

    const auto a=gen(k-1);
    vi ans(lim,INF);
    ans[0]=root->ans;
    // root=lazyFlip(root,0);
    prt(root);
    // dbg(a);
    for(lli i=1;i<lim;++i){
        const lli xr=a[i]^a[i-1];
        root=lazyFlip(root,height[xr]);
        // prt(root);
        // dbg(a[i],cc);
        ans[a[i]]=root->ans;
    }

    for(auto x:ans)
        cout<<x<<" ";
    cout<<endl;

}   aryanc403();
    return 0;
}