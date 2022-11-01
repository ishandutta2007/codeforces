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

const int MOD=1000000007;

const int maxsize=(4<<20);

int n,l,m;
int p[26],f[26];
char s[maxsize];

void update(int at,int key)
{
	int ret=1;
	REP(i,m) { ret+=f[i]; if (ret>=MOD) ret-=MOD; }
	f[key]=ret;
	p[key]=at;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	int l=strlen(s);
	memset(p,255,sizeof(p));
	REP(i,l) update(i,s[i]-'a');
	int o[26];
	REP(i,m) o[i]=i;
	REP(i,m) FOR(j,i+1,m) if (p[o[j]]<p[o[i]]) swap(o[i],o[j]);
	REP(d,n) update(l+d,o[d%m]);
	int ret=1;
	REP(i,m) { ret+=f[i]; if (ret>=MOD) ret-=MOD; }
	printf("%d\n",ret);
	return 0;
}