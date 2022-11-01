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

int n,m,d;
char a[512][512];
bool v[512][512];

void DFS(int x,int y)
{
	if (x<0 || y<0 || x>=n || y>=m || v[x][y] || a[x][y]=='#') return;
	v[x][y]=true;
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y-1);
	DFS(x,y+1);
	if ((d--)>0) a[x][y]='X';
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&d);
	for (int i=0;i<n;i++) scanf("%s",a[i]);
	memset(v,false,sizeof(v));
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (!v[i][j]) DFS(i,j);
	for (int i=0;i<n;i++) printf("%s\n",a[i]);
	return 0;
}