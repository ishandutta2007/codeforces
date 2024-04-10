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

//Works for negative costs, but does not work for negative cycles
//Complexity: O(min(E^2 *V log V, E logV * flow))

struct edge
{
	lli to, flow, cap, cost, rev;
};

struct MinCostMaxFlow
{
	lli nodes;
	vector<lli> prio, curflow, prevedge, prevnode, q, pot;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(lli n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(lli source, lli to, lli capacity, lli cost)
	{
		edge a = {to, 0, capacity, cost, (lli)graph[to].size()};
		edge b = {source, 0, 0, -cost, (lli)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(lli source, vector<lli> &dist)
	{
		fill(dist.begin(), dist.end(), INF);
		dist[source] = 0;
		lli qt=0;
		q[qt++] = source;
		for(lli qh=0;(qh-qt)%nodes!=0;qh++)
		{
			lli u = q[qh%nodes];
			inqueue[u] = false;
			for(auto &e : graph[u])
			{
				if(e.flow >= e.cap)
					continue;
				lli v = e.to;
				lli newDist = dist[u] + e.cost;
				if(dist[v] > newDist)
				{
					dist[v] = newDist;
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q[qt++ % nodes] = v;
					}
				}
			}
		}
	}

	pair<lli, lli> minCostFlow(lli source, lli dest, lli maxflow)
	{
		bellman_ford(source, pot);
		lli flow = 0;
		lli flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<lli, lli>, vector<pair<lli, lli> >, greater<pair<lli, lli> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INF);
			prio[source] = 0;
			curflow[source] = INF;
			while(!q.empty())
			{
				lli d = q.top().first;
				lli u = q.top().second;
				q.pop();
				if(d != prio[u])
					continue;
				for(lli i=0;i<graph[u].size();i++)
				{
					edge &e=graph[u][i];
					lli v = e.to;
					if(e.flow >= e.cap)
						continue;
					lli newPrio = prio[u] + e.cost + pot[u] - pot[v];
					if(prio[v] > newPrio)
					{
						prio[v] = newPrio;
						q.push({newPrio, v});
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap - e.flow);
					}
				}
			}
			if(prio[dest] == INF)
				break;
			for(lli i=0;i<nodes;i++)
				pot[i]+=prio[i];
			lli df = min(curflow[dest], maxflow - flow);
			flow += df;
			for(lli v=dest;v!=source;v=prevnode[v])
			{
				edge &e = graph[prevnode[v]][prevedge[v]];
				e.flow += df;
				graph[v][e.rev].flow -= df;
				flow_cost += df * e.cost;
			}
		}
		return {flow, flow_cost};
	}
};

//Problem 1: https://www.spoj.com/problems/GREED/
//Solution 1: http://p.ip.fi/ODRk

//Problem 2 (Double Cost): https://codeforces.com/contest/277/problem/E
//Solution 2: https://codeforces.com/contest/277/submission/43180845

const lli mod = 1000000007L;
const lli maxN = 50;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,q;
    string s;
    vi a;
    lli maxi[maxN+5],mini[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>q;
    repA(i,1,n)
        tie(maxi[i],mini[i])=mp(n,1);

    while(q--)
    {
        cin>>T>>l>>r>>x;
        if(T==1)
            repA(i,l,r)
                mini[i]=max(mini[i],x);
        else
            repA(i,l,r)
                maxi[i]=min(maxi[i],x);
    }

    repA(i,1,n)
        if(maxi[i]<mini[i])
        {
            cout<<-1<<endl;
            return 0;
        }

    MinCostMaxFlow ans(2*n+2);

    repA(i,1,n)
    {
        ans.addEdge(0,i,1,0);
        repA(j,mini[i],maxi[i])
            ans.addEdge(i,n+j,1,0);
    }

    repA(i,n+1,2*n)
    repA(j,1,n)
        ans.addEdge(i,2*n+1,1,2*j-1);

    cout<<ans.minCostFlow(0,2*n+1,n).Y<<endl;
}   aryanc403();
    return 0;
}