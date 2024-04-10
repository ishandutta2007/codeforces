/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#ifdef ARYANC403
    #include "/home/aryan/codes/PastCodes/template/header.h"
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<iostream>
    #include<bits/stdc++.h>
    #define dbg(args...)
#endif

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

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,iden;
    set<ii> fail;
    vector<bool> act;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool fl;

void dfs1(const vector<vi> &e,vi &col,lli u,lli c)
{
    if(col[u]!=-1)
    {
        if(col[u]==c)
            return;
        fl=false;
        return;
    }
    col[u]=c;
    for(auto x:e[u])
        dfs1(e,col,x,c^1);
}


bool bipartite(const vector<vi> &e)
{
    fl=true;
    const lli n=sz(e);
    vi col(n,-1);
    for(lli i=0;i<n;++i)
    {
        if(col[i]!=-1)
            continue;
        dfs1(e,col,i,0);
    }
    dbg(fl,e);
    return fl;
}

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

bool check2(const vii &ee)
{
    vi a;
    for(auto x:ee)
    {
        a.pb(iden[x.X]);
        a.pb(iden[x.Y]);
        a.pb(iden[x.X]^1);
        a.pb(iden[x.Y]^1);
    }
    a.pb(-INF);a.pb(INF);
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    auto get=[a](lli x){
        return lower_bound(all(a),x)-a.begin();
    };
    const lli n=sz(a);
    // UF aa(n);
    vector<vi> e(n);
    for(auto x:ee)
    {
        // dbg(iden[x.X],iden[x.Y]);
        x.X=get(iden[x.X]);
        x.Y=get(iden[x.Y]);
        // aa.join(x.X,x.Y);
        e[x.X].pb(x.Y);
        e[x.Y].pb(x.X);
    }
    dbg(a);
    for(auto x:a)
    {
        if(abs(x)==INF)
            continue;
        e[get(x)].pb(get(x^1));
        // dbg(x,aa.sameSet(get(x),get(x^1)));
        // if(aa.sameSet(get(x),get(x^1)))
        //     return true;
    }
    return !bipartite(e);
}

void check(const vii &ee)
{
    lli i;
    act.resize(k);
    vector<vi> e(n),mem(k);
    for(auto x:ee)
    {
        e[x.X].pb(x.Y);
        e[x.Y].pb(x.X);
    }

    fo(i,n)
        mem[a[i]].pb(i);
    lli c=0;
    iden.resize(n,-1);
    fo(i,k)
    {
        fl=true;
        dbg(mem[i]);
        for(auto x:mem[i])
        {
            if(iden[x]!=-1)
                continue;
            dfs1(e,iden,x,c);
            dbg(x,e[x]);
            c+=2;
        }
        act[i]=fl;
    }
    dbg(act,iden,c);
}

lli bf(const vii &ee)
{
    lli i=0,j=2,cnt=0;
    fo(i,k) repA(j,i+1,k-1)
    {
        vector<vi> e(n);
        for(auto x:ee)
        {
            if(a[x.Y]!=i&&a[x.Y]!=j)
                continue;
            if(a[x.X]!=i&&a[x.X]!=j)
                continue;
            e[x.X].pb(x.Y);
            e[x.Y].pb(x.X);
        }
        const lli v=bipartite(e);
        dbg(i,j,v);
        cnt+=v;
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k;
    fo(i,n)
    {
        cin>>in;
        in--;
        a.pb(in);
    }
    dbg(a);
    //check same. Check bipartite pair. Check edges.
    vii edges,ebf;
    map<ii,vii> mm;
    while(m--)
    {
        cin>>u>>v;
        u--;v--;
        if(a[u]>a[v])
            swap(u,v);
        if(a[u]!=a[v])
            mm[{a[u],a[v]}].pb({u,v});
        else
            edges.pb({u,v});
        ebf.pb({u,v});
    }

    check(edges);
    for(const auto &v:mm)
    {
        if((!act[v.X.X])||(!act[v.X.Y]))
            continue;
        if(check2(v.Y))
            fail.insert(v.X);
        dbg(v);
    }
    dbg(mm);
    lli ans=0;
    for(auto x:act)
        ans+=x;
    ans=ans*(ans-1)/2;
    for(auto x:fail)
        ans-=(act[x.X]&&act[x.Y]);
    dbg(fail);
    cout<<ans<<endl;return 0;
    lli eans;
    cin>>eans;
    if(ans==eans)
        cerr<<"Pass"<<endl;
    else
    {
        cerr<<"Fail"<<endl;
        cerr<<ans<<" "<<eans<<endl;
        while(true);
    }
}   aryanc403();
    return 0;
}