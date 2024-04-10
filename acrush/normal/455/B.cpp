#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxsize=100000+16;

int n,m;
int L[maxsize];
char *s[maxsize];
char buf[maxsize];
int o[maxsize],e[maxsize];
int *f[16][maxsize];

int cmp(const void* a, const void* b)
{
	return strcmp(s[*((int*)a)],s[*((int*)b)]);
}
int solve(int m,int p,int d)
{
	int &ret=f[m][o[p]][d];
	if (ret>=0) return ret;
	char last=0;
	for (int i=p;i<n;i++)
	{
		if (d<L[o[i]] && s[o[i]][d]!=last)
		{
			last=s[o[i]][d];
			if (!solve(m,i,d+1)) return ret=1;
		}
		if (e[i]<d) break;
	}
	if (last==0) return ret=((m==0)?0:solve(m-1,0,0));
	return ret=0;
}
int solve()
{
	m--;
	if (m<16) return solve(m,0,0);
	int x[16];
	for (int i=0;i<16;i++) x[i]=solve(i,0,0);
	for (int d=1;d<=8;d++)
	{
		bool ok=true;
		for (int i=8;i<16;i++) if (x[i]!=x[i-d]) ok=false;
		if (!ok) continue;
		m-=(m-16)/d*d;
		for (;m>=16;m-=d);
		return x[m];
	}
	while (1);
	return 0;
}
int main()
{
#ifdef _MSC_VER
	//freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",buf);
		L[i]=strlen(buf);
		s[i]=new char[L[i]+1];
		strcpy(s[i],buf);
	}
	for (int i=0;i<n;i++) o[i]=i;
	qsort(o,n,sizeof(int),cmp);
	for (int k=0;k<16;k++) for (int i=0;i<n;i++)
	{
		f[k][i]=new int[L[i]+1];
		memset(f[k][i],255,(L[i]+1)*sizeof(int));
	}
	for (int i=0;i<n-1;i++) 
	{
		int d=0;
		for (;d<L[o[i]] && d<L[o[i+1]] && s[o[i]][d]==s[o[i+1]][d];d++);
		e[i]=d;
	}
	e[n-1]=-1;
	if (solve())
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}