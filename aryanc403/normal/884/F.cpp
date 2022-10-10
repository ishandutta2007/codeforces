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
        dbg(source,to,capacity,cost)
		edge a = {to, 0, capacity, cost, (lli)graph[to].size()};
		edge b = {source, 0, 0, -cost, (lli)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(lli source, vector<lli> &dist)
	{
		fill(dist.begin(), dist.end(), INT_MAX);
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
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
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
			if(prio[dest] == INT_MAX)
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
        // dbg(flow)
		return {flow, flow_cost};
	}
};

const lli C=26;

    lli T,n,i,j,k,in,cnt[C],l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n);
    cin>>s;
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    for(auto x:s)
        cnt[x-'a']++;

    //0 src, 1 sink,2-27 alphabets 28 to 27+n/2 positions.
    MinCostMaxFlow ans(28+n/2);
    for(lli i=0;i<n-1-i;++i)
    {
        vi b(C,0);
        if(s[i]==s[n-1-i])
            b[s[i]-'a']=max(a[i],a[n-i-1]);
        else
        {
            b[s[i]-'a']=a[i];
            b[s[n-i-1]-'a']=a[n-i-1];
        }

        fo(j,C)
            ans.addEdge(j+2,i+28,1,-b[j]);
        ans.addEdge(i+28,1,2,0);
    }

    fo(j,C)
        ans.addEdge(0,j+2,cnt[j],0);
    // dbg(ans.minCostFlow(0,1,n))
    cout<<-ans.minCostFlow(0,1,n).Y<<endl;
}   aryanc403();
    return 0;
}