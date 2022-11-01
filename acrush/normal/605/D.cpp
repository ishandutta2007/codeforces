#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=200000+16;

int n;
int sx[maxn],sy[maxn],tx[maxn],ty[maxn];
set<ipair> p[maxn];
int sizeq;
int d[maxn],q[maxn],pw[maxn];

void preprocess(int s[],int t[])
{
	set<int> w;
	w.insert(0);
	REP(i,n) w.insert(s[i]);
	REP(i,n) w.insert(t[i]);
	vector<int> l(w.begin(),w.end());
	map<int,int> p;
	REP(i,SIZE(l)) p[l[i]]=i+1;
	REP(i,n) s[i]=p[s[i]];
	REP(i,n) t[i]=p[t[i]];
}
void update(int x,int y,int id,bool add)
{
	if (add)
		for (;x<maxn;x=(x|(x-1))+1) p[x].insert(MP(y,id));
	else
		for (;x<maxn;x=(x|(x-1))+1) p[x].erase(MP(y,id));
}
void expand(int x,int y,int ed,int ew)
{
	int start_sizeq=sizeq;
	for (;x>0;x&=(x-1))
	{
		if (p[x].empty()) continue;
		set<ipair>::iterator it=p[x].lower_bound(MP(y+1,-1));
		while (it!=p[x].begin())
		{
			--it;
			int id=it->second;
			if (d[id]<0)
			{
				d[id]=ed;
				pw[id]=ew;
				q[sizeq++]=id;
			}
		}
	}
	FOR(cl,start_sizeq,sizeq)
	{
		int id=q[cl];
		update(sx[id],sy[id],id,false);
	}
}
void solve()
{
	REP(i,maxn) p[i].clear();
	REP(i,n) update(sx[i],sy[i],i,true);
	REP(i,n) d[i]=-1;
	sizeq=0;
	expand(1,1,1,-1);
	REP(cl,sizeq)
	{
		int id=q[cl];
		if (id==n-1) 
		{
			vector<int> ret;
			for (;id>=0;id=pw[id]) ret.push_back(id);
			reverse(ALL(ret));
			printf("%d\n",SIZE(ret));
			REP(i,SIZE(ret)) printf("%d ",ret[i]+1);
			printf("\n");
			return;
		}
		expand(tx[id],ty[id],d[id]+1,id);
	}
	printf("-1\n");
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n)
	{
		REP(i,n) cin>>sx[i]>>sy[i]>>tx[i]>>ty[i];
		preprocess(sx,tx);
		preprocess(sy,ty);
		solve();
	}
	return 0;
}