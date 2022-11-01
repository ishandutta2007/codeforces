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

int h;
char z[500];
int n,m;
int n2;
bool g[500][500];
bool d[500][500];
char w[500];

int anti(int p)
{
	return (p<n)?(p+n):(p-n);
}
bool solve(int pos,char c)
{
	int s=pos,t=pos+n;
	if (z[c-'a']=='V') swap(s,t);
	REP(i,n) if ((g[i][i+n] || g[i][s] && g[t][i+n]) && (g[i+n][i] || g[i+n][s] && g[t][i])) return false;
	return true;
}
void update(int pos,char c)
{
	int s=pos,t=pos+n;
	if (z[c-'a']=='V') swap(s,t);
	REP(i,n2) if (g[i][s]) REP(j,n2) if (g[t][j]) g[i][j]=true;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>z;
	h=strlen(z);
	cin>>n>>m;
	n2=n+n;
	memset(g,false,sizeof(g));
	REP(i,n2) g[i][i]=true;
	REP(cl,m)
	{
		int p1,p2;
		char e1[10],e2[10];
		cin>>p1>>e1>>p2>>e2;
		--p1;
		--p2;
		if (e1[0]=='C') p1+=n;
		if (e2[0]=='C') p2+=n;
		g[p1][p2]=true;
		g[anti(p2)][anti(p1)]=true;
	}
	bool h0=false,h1=false;
	REP(i,h) 
		if (z[i]=='V') h0=true;
		else h1=true;
	if (!h0) REP(i,n) g[i][i+n]=true;
	if (!h1) REP(i,n) g[i+n][i]=true;
	REP(k,n2) REP(i,n2) REP(j,n2) if (g[i][k] && g[k][j]) g[i][j]=true;
	bool ok=true;
	REP(k,n) if (g[k][n+k] && g[n+k][k]) ok=false;
	if (!ok) { printf("-1\n"); return 0; }
	memcpy(d,g,sizeof(d));
	cin>>w;
	int last_at=-1;
	char last_c=0;
	REP(i,n) 
	{
		for (char c=w[i]+(int)(i<n-1);c<'a'+h;c++) if (solve(i,c)) { last_at=i; last_c=c; break; }
		update(i,w[i]);
	}
	if (last_at<0) { printf("-1\n"); return 0; }
	memcpy(g,d,sizeof(g));
	REP(i,last_at) update(i,w[i]);
	w[last_at]=last_c;
	update(last_at,last_c);
	FOR(i,last_at+1,n) for (char c='a';c<'a'+h;c++) if (solve(i,c)) { update(i,c); w[i]=c; break; }
	printf("%s\n",w);
	return 0;
}