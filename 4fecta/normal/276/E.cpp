#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <memory.h>
#include <stdio.h>
#include <ctime>
#include <cmath>


using namespace std;


char ch_ch_ch[1<<20];
inline int gi() {int a; scanf("%d",&a); return a;}
inline string gs() {scanf("%s",ch_ch_ch); return string(ch_ch_ch);}
inline string gl() {gets(ch_ch_ch); return string(ch_ch_ch);}
const int inf = 2000000000;

#define LL long long
#define U unsigned
#define pnt pair<int,int>
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (((a)>=(0))?(a):(-(a)))
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(),a.end()
#define FI(i,b) FOR(i,0,b)
#define V(t) vector < t > 
#define sz size()

vector<vector<int> > g;
int inTree[100100];
int depth[100100];
vector<vector<int> > t;
void dfs(int v, int d, int num, int p)
{
	inTree[v]=num;
	depth[v]=d;
	t[num].push_back(0);
	FOR(i,0,g[v].size())
	{
		int to=g[v][i];
		if (to==p)
			continue;
		dfs(g[v][i],d+1,num,v);
	}
}
void add(int p, int v, int num)
{
	for (int i=p; i<t[num].size(); i+=(i&(-i)))
		t[num][i]+=v;
}
int find(int p, int num)
{
	int res=0;
	for (int i=p; i>0; i-=(i&(-i)))
		res+=t[num][i];
	return res;
}
int main()
{
#ifdef Fcdkbear
	double beg=clock();
	freopen("in.txt","r",stdin);
#endif

	int n,q;
	scanf("%d%d",&n,&q);
	g.resize(n);
	FOR(i,0,n-1)
	{
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		v1--;
		v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	t.resize(g[0].size()+1);
	int inRoot=0;
	FOR(i,0,g[0].size())
	{
		t[i].push_back(0);
		dfs(g[0][i],1,i,0);
	}
	t[t.size()-1].resize(n+10);
	FOR(i,0,q)
	{
		int ty;
		scanf("%d",&ty);
		if (ty==0)
		{
			int v,val,dist;
			scanf("%d%d%d",&v,&val,&dist);
			v--;
			if (v==0)
			{
				inRoot+=val;
				add(1,val,t.size()-1);
				add(dist+1,-val,t.size()-1);
			}
			else
			{
				if (dist>=depth[v])
				{
					int left=dist-depth[v];
					inRoot+=val;
					add(1,val,t.size()-1);
					add(left+1,-val,t.size()-1);
					add(left+1,val,inTree[v]);
					add(depth[v]+dist+1,-val,inTree[v]);
				}
				else
				{
					add(depth[v]-dist,val,inTree[v]);
					add(depth[v]+dist+1,-val,inTree[v]);
				}
			}
		}
		else
		{
			int v;
			scanf("%d",&v);
			v--;
			if (v==0)
				printf("%d\n",inRoot);
			else
			{
				int res=find(depth[v],inTree[v])+find(depth[v],t.size()-1);
				printf("%d\n",res);
			}
		}
	}
#ifdef Fcdkbear
	double end=clock();
	fprintf(stderr,"*** Time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
	return 0;
}