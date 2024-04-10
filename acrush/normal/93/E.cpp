#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

const int maxn=100+5;

int n;
int64 s;
int a[maxn];
int f[maxn][500000];

int64 solve(int d,int64 s)
{
	if (s==0 || d==n) return s;
	if (s<500000 && f[d][s]!=-1) return f[d][s];
	int64 R=solve(d+1,s)-solve(d+1,s/a[d]);
	if (s<500000) f[d][s]=(int)R;
	return R;
}
int64 solve()
{
	for (int i=0;i<n;i++) if (a[i]<=1) return 0;
	memset(f,255,sizeof(f));
	return solve(0,s);
}
int main()
{
#ifdef _MSC_VER
	freopen("big.txt","r",stdin);
#endif
	cin>>s>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	int64 ret=solve();
	cout<<ret<<endl;
	return 0;
}