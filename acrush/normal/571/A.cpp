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

int64 C2(int64 n)
{
	return n*(n-1)/2;
}
int64 calc(int64 s,int64 d,int64 t)
{
	t-=s;
	if (t>d) return 0;
	if (t<-d) return C2(d+2);
	int64 m=(t+d)/2;
	return C2(m-t+2)-(t<0?C2(-t+1):0)+C2(d-m+1);
}
int64 solve(int64 a,int64 b,int64 c,int64 d)
{
	int64 ret=C2(d+2);
	if (b+c<=a) ret-=C2(min(a-b-c,d)+2);
	ret-=calc(b-c,d,a);
	ret-=calc(c-b,d,a);
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int64 ret=0;
	for (int i=0;i<=d;i++) ret+=solve(a+i,b,c,d-i);
	cout<<ret<<endl;
	return 0;
}