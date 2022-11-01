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

const int maxn=(1<<20);
const int64 oo=(1LL<<60);

int n,m;
int a[maxn];
int64 f[maxn];
int x[maxn];
int y[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		for (int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int length=n/m;
		for (int i=0;i<n;i++) x[i]=a[i+length-1]-a[i];
		for (int i=0;i<n;i++) y[i]=a[i+length]-a[i];
		int c=n%m;
		for (int i=0;i<=c;i++) f[i]=oo;
		f[0]=0;
		for (int d=0;d<m;d++)
		{
			int w=d*length;
			for (int i=c;i>=1;i--) f[i]=min(f[i]+x[w+i],f[i-1]+y[w+i-1]);
			f[0]+=x[w];
		}
		printf("%d\n",(int)f[c]);
	}
	return 0;
}