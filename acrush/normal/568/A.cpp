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

bool is_palindromic(int n)
{
	int m=0,a[10];
	for (;n>0;n/=10) a[m++]=n%10;
	REP(i,m/2) if (a[i]!=a[m-1-i]) return false;
	return true;
}
const int maxsize=(8<<20);
bool is_prime[maxsize];

int main()
{
	std::ios_base::sync_with_stdio(false);
	memset(is_prime,true,sizeof(is_prime));
	is_prime[1]=false;
	FOR(n,2,maxsize) if (is_prime[n]) for (int m=n+n;m<maxsize;m+=n) is_prime[m]=false;
	int p,q;
	cin>>p>>q;
	int ret=1;
	int c1=0,c2=0;
	FOR(n,1,maxsize)
	{
		if (is_prime[n]) c1++;
		if (is_palindromic(n)) c2++;
		if ((int64)c1*q<=(int64)p*c2) ret=n;
	}
	printf("%d\n",ret);
	return 0;
}