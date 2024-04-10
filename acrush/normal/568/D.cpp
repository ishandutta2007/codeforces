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

const int maxn=100000+16;

int n;
int a[maxn],b[maxn],c[maxn];
int w[maxn];
vector<ipair> ret;
map<ipair,int> m1;
vector<int> m2[1<<20];

bool dfs(int m,set<ipair> fset)
{
	int l=0,e[6];
	REP(i,n) if (!w[i]) { e[l++]=i; if (l>m) break; }
	if (l<=m)
	{
		REP(i,l) ret.push_back(MP(e[i]+1,-1));
		return true;
	}
	REP(c1,l) FOR(c2,c1+1,l)
	{
		int id1=e[c1],id2=e[c2];
		if (fset.count(MP(id1,id2))) continue;
		int64 t=(int64)a[id1]*b[id2]-(int64)a[id2]*b[id1];
		if (t==0) continue;
		int64 x=+(int64)b[id1]*c[id2]-(int64)b[id2]*c[id1];
		int64 y=-(int64)a[id1]*c[id2]+(int64)a[id2]*c[id1];
		if (!m1.count(MP(id1,id2)))
		{
			int id=SIZE(m1);
			m1[MP(id1,id2)]=id;
			REP(i,n) if (x*a[i]+y*b[i]+t*c[i]==0) m2[id].push_back(i);
		}
		int id=m1[MP(id1,id2)],size=SIZE(m2[id]),*lst=&m2[id][0];
		REP(i,size) w[lst[i]]++;
		if (dfs(m-1,fset))
		{
			ret.push_back(MP(id1+1,id2+1));
			return true;
		}
		REP(i,size) w[lst[i]]--;
		int sp=0,p[6];
		REP(i,l) if (x*a[e[i]]+y*b[e[i]]+t*c[e[i]]==0) p[sp++]=i;
		REP(i,sp) FOR(j,i+1,sp) fset.insert(MP(p[i],p[j]));
	}
	return false;
}
int main()
{
#ifdef _MSC_VER
	if (0)
	{
		freopen("large.txt","w",stdout);
		printf("100000 5\n");
		for (int i=0;i<100000;i++) printf("%d %d %d\n",rand(),rand(),rand());
		return 0;
	}
	//freopen("input.txt","r",stdin);
	freopen("large.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	int m;
	cin>>n>>m;
	REP(i,n) cin>>a[i]>>b[i]>>c[i];
	REP(i,n) w[i]=0;
	m1.clear();
	if (!dfs(m,set<ipair>())) 
		printf("NO\n");	
	else
	{
		printf("YES\n");
		printf("%d\n",SIZE(ret));
		REP(i,SIZE(ret)) printf("%d %d\n",ret[i].first,ret[i].second);
	}
	return 0;
}