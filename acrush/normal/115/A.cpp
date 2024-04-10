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

const int maxn=2000+5;

int n;
vector<int> g[maxn];
int deg[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) deg[i]=0;
	for (int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		if (p<0) continue;
		deg[i]++;
		g[p-1].push_back(i);
	}
	int R=0,left=n;
	while (left>0)
	{
		R++;
		vector<int> a;
		for (int i=0;i<n;i++) if (deg[i]==0) a.push_back(i);
		left-=SIZE(a);
		for (int i=SIZE(a)-1;i>=0;i--)
		{
			int k=a[i];
			deg[k]=-1;
			for (int j=0;j<SIZE(g[k]);j++) deg[g[k][j]]--;
		}
	}
	printf("%d\n",R);
	return 0;
}