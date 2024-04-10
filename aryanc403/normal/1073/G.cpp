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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;


template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

struct UF {
	vi e;
    vii aa;
	// UF(int n) : e(n, -1) {}
    UF(int n,const vi &_a) : e(n, -1) {
        aa.clear();
        for(auto x:_a)
        {
            if(x&1)
                aa.pb({0,1});
            else
                aa.pb({1,0});
        }
        // dbg(aa);
        // dbg(_a);
    }
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	lli join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        lli cnt=aa[a].X*aa[b].Y+aa[a].Y*aa[b].X;
        aa[a].X+=aa[b].X;aa[a].Y+=aa[b].Y;
        dbg(cnt);
		return cnt;
	}
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi id;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    lli q;
    cin>>n>>q;
    cin>>s;

    SuffixArray ss(s);
    RMQ<lli> rmq(ss.lcp);

    id.clear();id.resize(n+2);
    dbg(n,ss.sa);
    dbg(ss.lcp);

    repA(i,0,n)
        id[ss.sa[i]+1]=i;

    auto query = [&](lli l,lli r){
        if(l==r)
            return n-ss.sa[l];
        // if(l>r)
        //     swap(l,r);
        // dbg(l,r);
        return rmq.query(l+1,r+1);
    };

    while(q--)
    {
        cin>>k>>l;
        vi a;
        fo(i,k)
        {
            cin>>in;
            // dbg(in,id[in],ss.sa[id[in]]+1);
            // assert(in==ss.sa[id[in]]+1);
            in=id[in];
            a.pb(2*in);
        }
        
        fo(i,l)
        {
            cin>>in;
            in=id[in];
            a.pb(2*in+1);
        }

        sort(all(a));
        const lli m=sz(a);
        vector<pair<lli,ii>> ed;
        fo(i,m-1)
            ed.pb({-query(a[i]/2,a[i+1]/2),{i,i+1}});
            // dbg(s.substr(ss.sa[a[i]/2]),s.substr(ss.sa[a[i+1]/2]),query(a[i]/2,a[i+1]/2));
        sort(all(ed));
        dbg(ed);
        UF uf(m,a);
        lli ans=0;
        for(auto x:ed)
            ans+=(-x.X)*uf.join(x.Y.X,x.Y.Y);
        cout<<ans<<endl;
    }

}   aryanc403();
    return 0;
}