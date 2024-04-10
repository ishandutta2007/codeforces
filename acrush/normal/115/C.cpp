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

const int maxsize=1000000+5;
const int MOD=1000003;

int n,m;
char *a[maxsize];
char b[maxsize];

int solve(int n,char *a,char c1,char c2)
{
	int R=0;
	for (int s=0;s<2;s++)
	{
		bool ok=true;
		for (int i=0;i<n;i++) if (a[i]!='.') 
			if (((s+i)%2==0)!=(a[i]==c1 || a[i]==c2))
				ok=false;
		if (ok) R++;
	}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) 
	{
		a[i]=new char[m+1];
		scanf("%s",a[i]);
	}
	int R=1;
	for (int i=0;i<n;i++) R=(R*solve(m,a[i],'1','2'))%MOD;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) b[j]=a[j][i];
		R=(R*solve(n,b,'1','4'))%MOD;
	}
	printf("%d\n",R);
	return 0;
}