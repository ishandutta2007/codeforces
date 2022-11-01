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

const int maxn=200000+16;

int n,m;
vector<int> g[maxn];
vector<int> c[maxn];
vector<int> s[maxn];
int h[maxn];
int r[maxn];
int deg[maxn];
int q[maxn];

int sign(int x)
{
	return x<0?-1:1;
}
void dfs(int cid)
{
	if (h[cid]) return;
	h[cid]=1;
	for (int i=0;i<SIZE(c[cid]);i++)
	{
		int sid=abs(c[cid][i]);
		if (r[sid]!=0 || SIZE(s[sid])!=2) continue;
		int p=((abs(s[sid][0])==cid)?1:0);
		r[sid]=sign(s[sid][p]);
		dfs(abs(s[sid][p]));
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		for (int i=1;i<=n;i++) c[i].clear();
		for (int i=1;i<=m;i++) s[i].clear();
		for (int w,d,i=1;i<=n;i++) for (cin>>w;w>0;w--) 
		{
			cin>>d; 
			int e=sign(d);
			d=abs(d);
			s[d].push_back(i*e);
			c[i].push_back(d*e);
		}
		for (int i=1;i<=n;i++) h[i]=0;
		for (int i=1;i<=m;i++) r[i]=0;
		for (int i=1;i<=m;i++) 
			if (SIZE(s[i])==1)
			{
				r[i]=sign(s[i][0]);
				dfs(abs(s[i][0]));
			}
			else if (SIZE(s[i])==2 && sign(s[i][0])==sign(s[i][1]))
			{
				r[i]=sign(s[i][0]);
				dfs(abs(s[i][0]));
				dfs(abs(s[i][1]));
			}
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=m;i++) if (SIZE(s[i])==2 && r[i]==0)
		{
			int a=abs(s[i][0]),b=abs(s[i][1]);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i=1;i<=n;i++) deg[i]=SIZE(g[i]);
		set<int> allc;
		for (int i=1;i<=n;i++) if (h[i]==0) allc.insert(i);
		int sizeq=0;
		for (int i=1;i<=n;i++) if (h[i]==0 && deg[i]<=1) { q[sizeq++]=i; allc.erase(i); }
		bool ok=true;
		for (int cl=0;;cl++)
		{
			if (cl==sizeq)
			{
				if (allc.empty()) break;
				int cid=*allc.begin();
				q[sizeq++]=cid;
				allc.erase(cid);
			}
			int cid=q[cl];
			if (h[cid]==1) continue;
			for (int k=0;k<SIZE(c[cid]);k++)
			{
				int sid=abs(c[cid][k]);
				if (r[sid]!=0) continue;
				r[sid]=sign(c[cid][k]);
				h[cid]=1;
				for (int l=0;l<SIZE(s[sid]);l++)
				{
					int p=abs(s[sid][l]);
					if ((--deg[p])<=1 && allc.count(p)) { q[sizeq++]=p; allc.erase(p); }
				}
				break;
			}
			if (h[cid]==0) { ok=false; break; }
		}
		if (!ok)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for (int i=1;i<=m;i++) printf("%d",(int)(r[i]==1));
			printf("\n");
		}
	}
	return 0;
}