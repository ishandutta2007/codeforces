#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=100000+16;

int n;
int deg[maxn];
set<int> g[maxn];
bool f[maxn];
set<ipair> edges;

bool solve()
{
	for (int key=0;key<n;key++) if (deg[key]==2)
	{
		int a=*g[key].begin();
		int b=*(++g[key].begin());
		g[a].erase(key);
		g[b].erase(key);
		g[a].insert(b);
		g[b].insert(a);
		deg[key]=0;
	}
	int m=0;
	for (int i=0;i<n;i++) if (deg[i]>0) m++;
	if (m<=2) return true;
	memset(f,false,sizeof(f));
	for (int i=0;i<n;i++) if (deg[i]==1) f[i]=true;
	for (int i=0;i<n;i++) if (deg[i]==3) 
	{
		int c=0;
		for (set<int>::iterator it=g[i].begin();it!=g[i].end();++it) if (deg[*it]==1) c++;
		if (c>=2) f[i]=true;
	}
	for (int i=0;i<n;i++) if (deg[i]>2 && !f[i])
	{
		int c=0;
		for (set<int>::iterator it=g[i].begin();it!=g[i].end();++it) if (deg[*it]>2 && (!f[*it] || !edges.count(MP(i,*it)))) c++;
		if (c>2) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt","r",stdin);
	std::ios_base::sync_with_stdio(false);
	memset(deg,0,sizeof(deg));
	for (int i=0;i<n;i++) g[i].clear();
	cin>>n;
	for (int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].insert(b);
		g[b].insert(a);
		edges.insert(MP(a,b));
		edges.insert(MP(b,a));
		deg[a]++;
		deg[b]++;
	}
	if (solve())
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}