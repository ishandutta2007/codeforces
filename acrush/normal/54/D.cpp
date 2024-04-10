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

const int maxn=100+5;

int n,m,a[maxn];
int L,p[maxn];
bool visited[maxn][maxn];
bool e[maxn];

int getL(int d)
{
	for (int i=min(d,L);i>0;i--) if (memcmp(a+d-i,p+L-i,i*sizeof(int))==0) return i;
	return 0;
}
bool DFS(int d)
{
	int l=getL(d);
	if (visited[d][l]) return false;
	visited[d][l]=true;
	if (l==L && !e[d]) return false;
	if (d==n) return true;
	if (a[d]>=0)
		return DFS(d+1);
	else
	{
		for (int i=0;i<m;i++) 
		{
			a[d]=i;
			if (DFS(d+1)) return true;
		}
		a[d]=-1;
		return false;
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	memset(a,255,sizeof(a));
	string s,g;
	cin>>n>>m>>s>>g;
	L=LENGTH(s);
	for (int k=0;k<L;k++) p[k]=s[k]-'a';
	memset(e,false,sizeof(e));
	for (int i=0;i<LENGTH(g);i++) if (g[i]=='1')
	{
		e[i+L]=true;
		for (int k=0;k<LENGTH(s);k++)
		{
			if (a[i+k]<0) a[i+k]=p[k];
			else if (a[i+k]!=p[k]) 
			{
				printf("No solution\n");
				return 0;
			}
		}
	}
	memset(visited,false,sizeof(visited));
	if (DFS(0))
	{
		for (int i=0;i<n;i++) printf("%c",(char)('a'+a[i]));
		printf("\n");
	}
	else
		printf("No solution\n");
	return 0;
}