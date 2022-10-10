/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    //#pragma GCC optimize ("Ofast")
    //#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    //#pragma GCC optimize ("-ffloat-store")
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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

struct DATA
{
	//Use required attributes
	lli mn;

	//Default Values
	DATA() : mn(INF) {};
};
struct SegTree
{
	lli N;
	vector<DATA> st;
	vector<bool> cLazy;
	vector<lli> lazy;

	void init(lli n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, INF);
	}

	//Write reqd merge functions
	void merge(DATA &cur, DATA &l, DATA &r)
	{
		cur.mn = min({l.mn, r.mn,cur.mn});
	}

	//Handle lazy propagation appriopriately
	void propagate(lli node, lli L, lli R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = min(lazy[node*2],lazy[node]);
			lazy[node*2 + 1] = min(lazy[node*2+1],lazy[node]);
		}
		st[node].mn = min(st[node].mn,lazy[node]);
		cLazy[node] = 0;
	}

	void build(lli node, lli L, lli R)
	{
		if(L==R)
		{
			st[node].mn = INF;
			return;
		}
		lli M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	DATA Query(lli node, lli L, lli R, lli i, lli j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return DATA();
		if(i<=L && R<=j)
			return st[node];
		lli M = (L + R)/2;
		DATA left=Query(node*2, L, M, i, j);
		DATA right=Query(node*2 + 1, M + 1, R, i, j);
		DATA cur;
		merge(cur, left, right);
		return cur;
	}

	DATA pQuery(lli node, lli L, lli R, lli pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		lli M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}

	void Update(lli node, lli L, lli R, lli i, lli j, lli val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = min(lazy[node],val);
			propagate(node, L, R);
			return;
		}
		lli M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(lli node, lli L, lli R, lli pos, lli val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		lli M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	DATA query(lli pos)
	{
		return pQuery(1, 1, N, pos);
	}

	DATA query(lli l, lli r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(lli pos, lli val)
	{
		pUpdate(1, 1, N, pos, val);
	}

	void update(lli l, lli r, lli val)
	{
		Update(1, 1, N, l, r, val);
	}
};

//Problem 1 (Max Query - Point Update with Coordinate Compression): http://codeforces.com/gym/100733/problem/F
//Solution 1: http://codeforces.com/gym/100733/submission/41643795

//Problem 2 (Min Query - Offline processing): https://codeforces.com/problemset/problem/522/D
//Solution 2: https://codeforces.com/contest/522/submission/45493164
    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b,idx,nxt,pvr;
    SegTree seg;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli query(lli l,lli r)
{
    return -seg.query(l+1,r+1).mn;
}

void update(lli l,lli r,lli v)
{
    seg.update(l+1,r+1,-v);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n;
    idx=pvr=nxt=vi(n);
    fo(i,n)
    {
        cin>>in;
        in--;
        a.pb(in);
        idx[a[i]]=i;
    }

    fo(i,n)
    {
        cin>>in;
        b.pb(in);
    }
    seg.init(n+2);

    stack<ii> pq;
    pq.push({-INF,n+1});
    repD(i,n-1,0)
    {
        while(pq.top().X>a[i])
            pq.pop();
        nxt[i]=pq.top().Y-1;
        pq.push({a[i],i+1});
    }

    while(!pq.empty())  pq.pop();
    pq.push({-INF,0});
    fo(i,n)
    {
        while(pq.top().X>a[i])
            pq.pop();
        pvr[i]=pq.top().Y+1;
        pq.push({a[i],i+1});
    }

    dbg(pvr);
    dbg(nxt);
    dbg(a);
    dbg(b);
    update(0,0,0);
    for(int i=0;i<n;++i)
    {
        // dbg(pvr[i],nxt[i]);
        lli cur=query(pvr[i]-1,i);
        cur+=b[i];
        dbg(a[i],cur,pvr[i]-1,nxt[i],i,query(pvr[i]-1,i));
        update(i+1,nxt[i],cur);
    }
    cout<<query(n,n)<<endl;
    dbg(query(n,n));
}   aryanc403();
    return 0;
}