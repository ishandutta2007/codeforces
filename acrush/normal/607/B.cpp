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

const int maxn=512;

int n;
int a[maxn];
int f1[maxn][maxn],f2[maxn][maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	REP(i,n) cin>>a[i];
	for (int i=n-1;i>=0;i--) for (int j=i;j<n;j++)
		if (i==j)
			f1[i][j]=f2[i][j]=1;
		else
		{
			f1[i][j]=f2[i][j]=n;
			FOR(k,i,j)
			{
				ckmin(f1[i][j],f1[i][k]+f1[k+1][j]);
				ckmin(f2[i][j],f1[i][k]+f2[k+1][j]);
				ckmin(f2[i][j],f2[i][k]+f1[k+1][j]);
			}
			if (a[i]==a[j])
				if (i+1==j)
					f1[i][j]=f2[i][j]=1;
				else
				{
					ckmin(f1[i][j],f2[i+1][j-1]);
					ckmin(f2[i][j],f2[i+1][j-1]);
				}
		}
	printf("%d\n",f1[0][n-1]);
	return 0;
}