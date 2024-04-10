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
template<class T> void checkmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void checkmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=200000+16;

int n,m;
char s[maxn];
int64 g[2][2][2],f[2][2][2];

void solve(char c0,char c1,char c2)
{
	memset(g,0,sizeof(g));
	int w[2][2][2];
	memset(w,0,sizeof(w));
	for (char c='a';c<'a'+m;c++) w[(int)(c==c0)][(int)(c==c1)][(int)(c==c2)]++;
	for (int w0=0;w0<2;w0++) for (int w1=0;w1<2;w1++) for (int w2=0;w2<2;w2++) if (w[w0][w1][w2])
		for (int s0=0;s0<2;s0++) for (int s1=0;s1<2;s1++) for (int s2=0;s2<2;s2++) if (f[s0][s1][s2])
		{
			int t0=(w0?s0:s1);
			int t1=0;
			if (w1) t1=s1;
			else if (t0==0 && s2==0) continue;
			int t2=(w2?s2:t1);
			g[t0][t1][t2]+=f[s0][s1][s2]*w[w0][w1][w2];
		}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m>>s)
	{
		memset(f,0,sizeof(f));
		for (char c='a';c<'a'+m;c++)
		{
			int s0=1;
			int s1=(int)(c==s[0]);
			int s2=(int)(c==s[0] || c==s[1]);
			f[s0][s1][s2]++;
		}
		s[n]=s[n+1]=0;
		for (int k=1;k<n;k++)
		{
			solve(s[k-1],s[k],s[k+1]);
			memcpy(f,g,sizeof(f));
		}
		int64 ret=0;
		REP(i,2) REP(j,2) REP(k,2) ret+=f[i][j][k];
		cout<<ret-1<<endl;
	}
	return 0;
}