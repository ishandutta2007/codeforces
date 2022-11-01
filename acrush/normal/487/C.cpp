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

const int maxn=200000+5;

int n;
int w;
int a[maxn];
int r[maxn];
int p[maxn];

bool v1[maxn],v2[maxn];

int main()
{
	scanf("%d",&n);
	if (n==1) { printf("YES\n1\n"); return 0; }
	if (n==2) { printf("YES\n1\n2\n"); return 0; }
	if (n==3) { printf("YES\n1\n2\n3\n"); return 0; }
	if (n==4) { printf("YES\n1\n3\n2\n4\n"); return 0; }
	for (int m=2;m*m<=n;m++) if (n%m==0) { printf("NO\n"); return 0; }
	for (w=2;;w++)
	{
		bool ok=true;
		for (int pw=1,i=1;i<n-1;i++)
		{
			pw=(int)(((int64)pw*w)%n);
			if (pw==1) { ok=false; break; }
		}
		if (ok) break;
	}
	p[0]=1;
	for (int i=1;i<n;i++) p[i]=(int)(((int64)p[i-1]*w)%n);
	int c=0;
	for (int i=1;i<=(n-1)/2-1;i++) a[c++]=((i&1)?i:(n-1-i));
	a[c++]=(n-1)/2;
	for (int i=(n-1)/2-1;i>=1;i--) a[c++]=((i&1)?(n-1-i):i);	
	int d=0;
	r[d++]=1;
	for (int i=0;i<c;i++) r[d++]=p[a[i]];
	r[d++]=n;
/*
	memset(v1,false,sizeof(v1));
	memset(v2,false,sizeof(v2));
	for (int x=1,i=0;i<n;i++)
	{
		x=(int)(((int64)x*r[i])%n);
		if (v1[r[i]] || v2[x])
		{
			printf("ERROR\n");
			exit(0);
		}
		v1[r[i]]=v2[x]=true;
	}
*/
	printf("YES\n");
	for (int i=0;i<n;i++) printf("%d\n",r[i]);
	return 0;
}