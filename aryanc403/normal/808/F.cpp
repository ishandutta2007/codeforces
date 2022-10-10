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


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
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
const lli N = 2*100000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<array<lli,3>> a;
    vector<bool> pri,vis;
    vector<vi> e;
    vii b;
    lli gv[2];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

struct edge
{
	lli from, to, cap, flow, index;
	edge(lli from, lli to, lli cap, lli flow, lli index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	lli n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<lli> height, active, count;
	queue<lli> Q;

	PushRelabel(lli n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(lli from, lli to, lli cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}

	void enqueue(lli v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e)
	{
		lli amt=(lli)min(excess[e.from], (long long)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(lli v)
	{
		count[height[v]]--;
		lli d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(lli k)
	{
		for(lli v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(lli v)
	{
		for(lli i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}

	long long max_flow(lli source, lli dest)
	{
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &it:g[source])
		{
			excess[source]+=it.cap;
			push(it);
		}

		while(!Q.empty())
		{
			lli v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}

		long long max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

bool chk(lli lvl)
{
    b.clear();
    lli on=-1;
    for(auto v:a)
    {
        if(v[2]>lvl)
            continue;
        if(v[1]==1)
            on=max(on,v[0]);
        else
            b.pb({v[0],v[1]});
    }

    if(on>0)
        b.pb({on,1});
    const lli n=sz(b);
    dbg(lvl,b);
    if(n==0)
        return false;

    e.clear();
    e.resize(n);
    vis.clear();
    vis.resize(n,false);

    PushRelabel flow(n+2);

    lli i,j;
    lli ans=0;
    for(auto x:b)
        ans+=x.X;
    
    fo(i,n)
    {
        if(b[i].Y%2)
            flow.addEdge(n,i,b[i].X);
        else
            flow.addEdge(i,n+1,b[i].X);
        
        repA(j,i+1,n-1)
        {
            if(pri[b[i].Y+b[j].Y])
            {
                if(b[i].Y%2)
                    flow.addEdge(i,j,1e9);
                else
                    flow.addEdge(j,i,1e9);
            }
        }
    }

    ans-=flow.max_flow(n,n+1);
    dbg(lvl,ans,k);
    return ans>=k;
}

void pre(lli n)
{
    pri.clear();
    pri.resize(n+1,true);
    pri[0]=pri[1]=false;
    for(lli i=2;i<=n;++i)
    {
        if(!pri[i])
            continue;
        for(lli j=i*i;j<=n;j+=i)
            pri[j]=false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    pre(N);
    cin>>n>>k;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        lli p,c,l;
        cin>>p>>c>>l;
        a.pb({p,c,l});
    }

    lli l=0,r=n+2;
    while(r-l>1)
    {
        lli m=(l+r)/2;
        if(chk(m))
            r=m;
        else
            l=m;
    }
    dbg(r);
    // for(lli r=1;r<=n;++r)
    // {
    //     if(chk(r))
    //     {
    //         cout<<r<<endl;
    //         return 0;
    //     }
    // }
    if(r>n)
        r=-1;
    cout<<r<<endl;

}   aryanc403();
    return 0;
}