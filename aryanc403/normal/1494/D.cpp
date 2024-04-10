/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
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

/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */

struct UF {
	vi e,c;
	UF(int n) : e(n, -1),c(n) {iota(all(c),0);}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
    int get(int x) { return c[find(x)]; }
    void set(int x,int y) { c[find(x)]=y; }
	int find(int x) { return e[x] < 0 ? x : (e[x] = find(e[x])); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		c[b] = c[a];
		return true;
	}
};

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    vector<vi> a(n,vi(n));
    for(auto &v:a)
    for(auto &x:v)
        cin>>x;

    vi c(2*n-1);
    UF uf(2*n-1);
    vii edges;
    fo(i,n)
        c[i]=a[i][i];
    vii b;
    fo(i,n) fo(j,i)
        b.pb({i,j});

    sort(all(b),[&](const ii x,const ii y){
        return a[x.X][x.Y]<a[y.X][y.Y];
    });

    auto check=[&](lli l,lli r,lli cst){
        vi aa,bb;
        lli i;
        fo(i,n)
        {
            if(uf.get(i)==l)
                aa.pb(i);
            if(uf.get(i)==r)
                bb.pb(i);
        }
        for(auto x:aa)
        for(auto y:bb)
            if(a[x][y]!=cst)
                return false;
        return true;
    };

    lli nxt=n;
    for(auto x:b)
    {
        const lli l=uf.get(x.X),r=uf.get(x.Y);
        if(l==r)
            continue;
        if(!check(l,r,a[x.X][x.Y]))
        {
            dbg(x);
            continue;
        }
        edges.pb({l,nxt});
        edges.pb({r,nxt});
        uf.join(l,nxt);
        uf.join(r,nxt);
        uf.set(nxt,nxt);
        c[nxt]=a[x.X][x.Y];
        nxt++;
    }

    UF uf2(2*n-1);
    for(auto x:edges)
        if(c[x.X]==c[x.Y])
            uf2.join(x.X,x.Y);

    vi idx;
    fo(i,2*n-1)
        idx.pb(uf2.find(i));
    sort(all(idx));
    idx.erase(unique(all(idx)),idx.end());

    auto get=[&](lli i){
        dbg(i,idx);
        return (int)(lower_bound(all(idx),i)-idx.begin());
    };
    dbg(idx);
    cout<<sz(idx)<<endl;
    for(auto x:idx)
        cout<<c[x]<<" ";
    cout<<endl;
    dbg(uf2.find(2*n-2));
    dbg(uf2.e);
    dbg(get(uf2.find(2*n-2)));
    cout<<get(uf2.find(2*n-2))+1<<endl;
    dbg(edges);
    for(auto x:edges)
    {
        if(uf2.same_set(x.X,x.Y))
            continue;
        x.X=get(uf2.find(x.X));
        x.Y=get(uf2.find(x.Y));
        cout<<x.X+1<<" "<<x.Y+1<<endl;
    }
}   aryanc403();
    return 0;
}