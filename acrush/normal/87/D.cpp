#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=200000+5;

int n,m;
pair<ipair,ipair> e[maxn];
int father[maxn],cnt[maxn];
int64 resultc;
vector<int> result;
map<int,int> M;
vector<ipair> g[maxn];
int size[maxn],sum[maxn];
bool visited[maxn];

int getfather(int p)
{
	return (father[p]<0)?p:(father[p]=getfather(father[p]));
}
int get_id(int p)
{
	p=getfather(p);
	if (M.find(p)!=M.end()) return M[p];
	int id=SIZE(M);
	size[id]=cnt[p];
	return M[p]=id;
}
void merge(int a,int b)
{
	a=getfather(a);
	b=getfather(b);
	if (a==b) return;
	if (cnt[a]>cnt[b]) swap(a,b);
	father[a]=b;
	cnt[b]+=cnt[a];
}
void DFS(int p)
{
	if (visited[p]) return;
	visited[p]=true;
	sum[p]=size[p];
	for (int i=0;i<SIZE(g[p]);i++)
	{
		int other=g[p][i].first;
		if (!visited[other]) 
		{
			DFS(other);
			sum[p]+=sum[other];
		}
	}
}
void DFS2(int p,int prev,int all)
{
	for (int i=0;i<SIZE(g[p]);i++)
	{
		int other=g[p][i].first;
		if (other==prev) continue;
		int64 c=(int64)sum[other]*(all-sum[other]);
		if (c>resultc) 
		{
			resultc=c;
			result.clear();
		}
		if (c==resultc)
			result.push_back(g[p][i].second);
		DFS2(other,p,all);
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("D.in","r",stdin);
#endif
	scanf("%d",&n);
	m=n-1;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[i]=MP(MP(c,i+1),MP(a-1,b-1));
	}
	sort(e,e+m);
	resultc=-1;
	for (int i=0;i<n;i++) father[i]=-1,cnt[i]=1;
	for (int i=0;i<m;i++) if (i==0 || e[i].first.first!=e[i-1].first.first)
	{
		M.clear();
		int j=i;
		for (;j<m && e[j].first.first==e[i].first.first;j++);
		for (int k=i;k<j;k++) 
		{
			get_id(e[k].second.first);
			get_id(e[k].second.second);
		}
		for (int k=0;k<SIZE(M);k++) g[k].clear();
		for (int k=i;k<j;k++) 
		{
			int v1=get_id(e[k].second.first);
			int v2=get_id(e[k].second.second);
			g[v1].push_back(MP(v2,e[k].first.second));
			g[v2].push_back(MP(v1,e[k].first.second));
		}
		for (int k=0;k<SIZE(M);k++) visited[k]=false;
		for (int k=0;k<SIZE(M);k++) if (!visited[k])
		{
			DFS(k);
			DFS2(k,-1,sum[k]);
		}
		for (int k=i;k<j;k++) merge(e[k].second.first,e[k].second.second);
	}
	cout<<resultc*2<<" "<<SIZE(result)<<endl;
	sort(result.begin(),result.end());
	for (int i=0;i<SIZE(result);i++)
	{
		if (i>0) cout<<" ";
		cout<<result[i];
	}
	cout<<endl;
	return 0;
}