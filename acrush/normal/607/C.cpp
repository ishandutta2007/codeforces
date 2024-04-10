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

const uint MOD=1000000009;
const int maxn=(1<<20);

int n;
int l[2];
int a[2][maxn];
char str[maxn];

bool solve()
{
	for (int i=0;i<l[0];i++) a[0][i]^=1;
	reverse(a[0],a[0]+l[0]);
	reverse(a[1],a[1]+l[1]);
	uint w0=0,w1=0,pw=1;
	int c1[4],c2[4];
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	for (int x=1;x<=min(l[0],l[1]);x++)
	{
		c1[a[0][x-1]]++;
		c2[a[1][x-1]]++;
		w0=(w0*4+a[0][x-1])%MOD;
		w1=(w1+a[1][x-1]*pw)%MOD;
		pw=(pw*4)%MOD;
		if (w0!=w1) continue;
		bool ok=true;
		REP(i,4) if (c1[i]!=c2[i]) { ok=false; break; }
		if (ok) for (int i=0;i<x;i++) if (a[0][i]!=a[1][x-1-i]) { ok=false; break; }
		if (ok) return false;
	}
	return true;
}

int encode(char c)
{
	if (c=='N') return 0;
	if (c=='S') return 1;
	if (c=='W') return 2;
	if (c=='E') return 3;
	return -1;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	--n;
	l[0]=l[1]=n;
	cin>>str;
	REP(i,n) a[0][i]=encode(str[i]);
	cin>>str;
	REP(i,n) a[1][i]=encode(str[i]);
	if (solve())
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}