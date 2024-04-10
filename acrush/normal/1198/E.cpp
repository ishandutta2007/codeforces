#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

struct Rect
{
	int x1,y1,x2,y2;
	Rect() {}
	Rect(int x1,int y1,int x2,int y2) : x1(x1),y1(y1),x2(x2),y2(y2) {}
};

template<class Int> class Dinic
{
public:
	struct Edge
	{
		int point = 0;
		Int flow = 0;
		Int capa = 0;
		Edge* next = nullptr;
		Edge* anti = nullptr;
	};
	int node = 0;
	vector<Edge*> head;
	vector<int> dist;
	vector<int> q;
	vector<Edge*> work;

	Dinic(int _node)
	{
		node = _node;
		head.resize(node);
		dist.resize(node);
		q.resize(node);
		work.resize(node);
		for (int i = 0; i < node; i++) head[i] = nullptr;
	}
	pair<Edge*, Edge*> addedge(int u, int v, Int c1, Int c2 = 0)
	{
		Edge *e1 = newedge();
		Edge *e2 = newedge();
		e1->point = v;
		e1->capa = c1;
		e1->flow = 0;
		e1->next = head[u];
		head[u] = e1;
		e1->anti = e2;
		e2->point = u;
		e2->capa = c2;
		e2->flow = 0;
		e2->next = head[v];
		head[v] = e2;
		e2->anti = e1;
		return make_pair(e1, e2);
	}

	void clear()
	{
		for (int i = 0; i < node; ++i)
			for (Edge* e = head[i]; e != nullptr; e = e->next)
				e->flow = 0;
	}

	Int flow(int src, int dest)
	{
		Int result = 0;
		while (dinic_bfs(src, dest))
		{
			for (int i = 0; i < node; ++i) work[i] = head[i];
			result += dinic_dfs(src, std::numeric_limits<Int>::max(), dest);
		}
		return result;
	}

private:
	int buffer_pos = 0;
	vector<vector<Edge>> buffer;

	Edge * newedge()
	{
		if (buffer.empty() || buffer_pos >= static_cast<int>(buffer.back().size()))
		{
			int size = (buffer.empty() ? 16 : buffer.back().size() * 2);
			buffer.emplace_back(vector<Edge>(size));
			buffer_pos = 0;
		}
		return &buffer.back()[buffer_pos++];
	}
	bool dinic_bfs(int src, int dest)
	{
		for (int i = 0; i < node; i++) dist[i] = -1;
		dist[src] = 0;
		int sizeQ = 0;
		q[sizeQ++] = src;
		for (int cl = 0; cl < sizeQ; cl++)
			for (Edge* e = head[q[cl]]; e != nullptr; e = e->next)
				if (e->flow < e->capa && dist[e->point] < 0)
				{
					dist[e->point] = dist[q[cl]] + 1;
					q[sizeQ++] = e->point;
				}
		return dist[dest] >= 0;
	}
	Int dinic_dfs(int x, Int exp, int dest)
	{
		if (x == dest) return exp;
		Int res = 0, tmp;
		for (Edge *&e = work[x]; e != nullptr; e = e->next)
			if (e->flow < e->capa && dist[e->point] == dist[x] + 1 && (tmp = dinic_dfs(e->point, min(exp, e->capa - e->flow), dest)) > 0)
			{
				e->flow += tmp;
				e->anti->flow -= tmp;
				res += tmp;
				exp -= tmp;
				if (exp == 0) break;
			}
		return res;
	}
};

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		vector<Rect> a(m);
		set<int> sx,sy;
		sx.insert(0);
		sx.insert(n);
		sy.insert(0);
		sy.insert(n);
		REP(i,m)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			--x1; --y1;
			a[i]=Rect(x1,y1,x2,y2);
			sx.insert(x1);
			sx.insert(x2);
			sy.insert(y1);
			sy.insert(y2);
		}
		VI lx(ALL(sx));
		VI ly(ALL(sy));
		int cx=SIZE(lx)-1;
		int cy=SIZE(ly)-1;
		int src=cx+cy;
		int dst=cx+cy+1;
		Dinic<int> dinic(cx+cy+2);
		REP(i,cx) dinic.addedge(src,i,lx[i+1]-lx[i]);
		REP(i,cy) dinic.addedge(i+cx,dst,ly[i+1]-ly[i]);
		REP(i,cx) REP(j,cy)
		{
			int ok=0;
			REP(k,m) if (a[k].x1<=lx[i] && a[k].x2>lx[i] && a[k].y1<=ly[j] && a[k].y2>ly[j]) ok=1;
			if (!ok) continue;
			dinic.addedge(i,j+cx,n);
		}
		int ret=dinic.flow(src,dst);
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}