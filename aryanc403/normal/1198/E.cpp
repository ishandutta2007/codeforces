/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
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
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

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
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

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

//Push-Relabel Algorithm for Flows, Complexity: O(V^2 E)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

struct edge
{
	lli from, to, cap, flow, index;
	edge(lli from, lli to, lli cap, lli flow, lli index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

ostream& operator << (ostream& out, const edge &a) {
    return out<<"{"<<a.from<<","<<a.to<<","<<a.cap<<"}";
}

struct PushRelabel
{
	static const long long INF=1e18;

	lli n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<lli> height;

	PushRelabel(lli n):
		n(n), g(n), excess(n), height(n) {}

	void addEdge(lli from, lli to, lli cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
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
	}

	void relabel(lli u)
	{
		lli d=2e5;
		for(auto &it:g[u])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]);
		}
		if(d<INF)
			height[u]=d+1;
	}

	vector<lli> find_max_height_vertices(lli source, lli dest)
	{
		vector<lli> max_height;
		for(lli i=0;i<n;i++)
		{
			if(i!=source && i!=dest && excess[i]>0)
			{
				if(!max_height.empty() && height[i] > height[max_height[0]])
					max_height.clear();
				if(max_height.empty() || height[i] == height[max_height[0]])
					max_height.push_back(i);
			}
		}
		return max_height;
	}

	long long max_flow(lli source, lli dest)
	{
        // dbg(g);
		excess.assign(n, 0);
		height.assign(n, 0);
		height[source]=n;
		excess[source]=INF;
		for(auto &it:g[source])
			push(it);

		vector<lli> current;
		while(!(current = find_max_height_vertices(source, dest)).empty())
		{
			for(auto i:current)
			{
				bool pushed=false;
				for(auto &e:g[i])
				{
					if(excess[i]==0)
						break;
					if(e.cap - e.flow>0 && height[e.from] == height[e.to] + 1)
					{
						push(e);
						pushed=true;
					}
				}
				if(!pushed)
				{
					relabel(i);
					break;
				}
			}
		}

		long long max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

//Problem 1: http://codeforces.com/contest/546/problem/E
//Solution 1: http://codeforces.com/contest/546/submission/40528334

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi xx,yy;
    vii ed;
    vector<pair<ii,ii>> st;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .
template <typename TT>
void unq(vector<TT> &a)
{
    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end())-a.begin());
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;

    if(m==0)
    {
        cout<<0<<endl;
        return 0;
    }

    xx.pb(-INF);xx.pb(INF);
    yy.pb(-INF);yy.pb(INF);

    fo(i,m)
    {
        lli x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        st.pb({{x1,y1},{x2,y2}});
        xx.pb(x1);xx.pb(x2+1);
        yy.pb(y1);yy.pb(y2+1);
    }

    unq(xx);
    unq(yy);

    n=(lli)xx.size();n-=3;
    m=(lli)yy.size();m-=3;

    for(auto x:st)
    {
        repA(i,1,n)     repA(j,1,m)
        {
            if(x.X.X<=xx[i]&&xx[i]<=x.Y.X&&x.X.Y<=yy[j]&&yy[j]<=x.Y.Y)
                ed.pb({i,n+j});
        }
    }

    dbg(ed);
    unq(ed);
    // dbg(xx,yy,n,m);
    dbg(ed);
    PushRelabel ans(n+m+2);
    for(auto x:ed)
        ans.addEdge(x.X,x.Y,min(xx[x.X+1]-xx[x.X],yy[x.Y-n+1]-yy[x.Y-n]));

    repA(i,1,n)
        ans.addEdge(0,i,xx[i+1]-xx[i]);

    repA(j,1,m)
        ans.addEdge(n+j,n+m+1,yy[j+1]-yy[j]);

    cout<<ans.max_flow(0,n+m+1)<<endl;
}   aryanc403();
    return 0;
}