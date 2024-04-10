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

int c[256];
char s[1<<20];
bool g[256];

int main()
{
	memset(c,0,sizeof(c));
	int m;
	scanf("%s%d",s,&m);
	for (int i=0;s[i];i++) c[s[i]]++;
	for (int i=0;i<256;i++) g[i]=(c[i]>0);
	while (m>0)
	{
		int k=-1;
		for (int i=0;i<256;i++) if (g[i] && (k<0 || c[i]<c[k])) k=i;
		if (k<0) break;
		if (c[k]>m) break;
		m-=c[k];
		g[k]=false;
	}
	int ret=0;
	for (int i=0;i<256;i++) if (g[i]) ret++;
	printf("%d\n",ret);
	for (int i=0;s[i];i++) if (g[s[i]]) printf("%c",s[i]);
	printf("\n");
	return 0;
}