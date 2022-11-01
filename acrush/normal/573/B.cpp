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

const int maxn=100000+16;

int n;
int a[maxn];
bool r1[maxn],r2[maxn];
int b[maxn];
int p[maxn];
int sk[maxn];

void solve(bool r[],int d)
{
	for (int i=0;i<n;i++) r[i]=false;
	for (int i=0;i<n;i++) b[i]=a[i]+i;
	int size=0;
	for (int i=n-1;i>=0;i--)
	{
		for (;size>0 && b[i]<=b[sk[size-1]];size--);
		p[i]=((size==0)?n:sk[size-1]);
		sk[size++]=i;
	}
	for (int k=-1,i=0;i+d<n;i++)
	{
		if (k<i) k=i;
		for (;p[k]<=i+d;k=p[k]);
		r[i]=(b[k]>d+i);
	}
}
bool solve(int d)
{
	solve(r1,d);
	reverse(a,a+n);
	solve(r2,d);
	reverse(a,a+n);
	for (int i=0;i<n;i++) if (r1[i] && r2[n-1-i]) return true;
	return false;
}
int main()
{
	//freopen("input.txt","r",stdin);
	std::ios_base::sync_with_stdio(false);
	while (cin>>n)
	{
		for (int i=0;i<n;i++) cin>>a[i];
		int H=0,T=n+2;
		for (;H+1<T;)
		{
			int M=(H+T)/2;
			if (solve(M)) H=M;
			else T=M;
		}
		printf("%d\n",T);
	}
	return 0;
}