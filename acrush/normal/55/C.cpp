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

const int maxsize=100+5;

int size_x,size_y,n;
int x[maxsize],y[maxsize];

bool solve()
{
	for (int i=0;i<n;i++) x[i]--,y[i]--;
	for (int i=0;i<n;i++) if (x[i]<5 || size_x-1-x[i]<5 || y[i]<5 || size_y-1-y[i]<5) return true;
	return false;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&size_x,&size_y,&n);
	for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	if (solve()) printf("YES\n");
	else printf("NO\n");
	return 0;
}