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

const int maxn=5000+5;

int n;
int father[maxn],capa[maxn];
vector<ipair> g[maxn];
int p[maxn],R[maxn],sizeq,q[maxn];
priority_queue<int> h[maxn];

void DFS(int p,int last)
{
	q[sizeq++]=p;
	for (int i=0;i<SIZE(g[p]);i++)
	{
		int other=g[p][i].first;
		if (other!=last)
		{
			father[other]=p;
			capa[other]=g[p][i].second;
			DFS(other,p);
		}
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for (int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;
		b--;
		g[a].push_back(MP(b,c));
		g[b].push_back(MP(a,c));
	}
	father[0]=-1;
	capa[0]=0;
	sizeq=0;
	DFS(0,-1);
	map<int,int> M;
	for (int i=0;i<n;i++)
	{
		M[-p[i]]=i;
		h[i].push(-p[i]);
	}
	for (int step=0;step<=n;step++)
	{
		while (!h[0].empty())
		{
			int other=h[0].top();
			h[0].pop();
			R[M[other]]=step;
		}
		for (int o=1;o<n;o++)
		{
			int key=q[o];
			for (int d=capa[key];!h[key].empty() && d>0;d--)
			{
				int other=h[key].top();
				h[key].pop();
				h[father[key]].push(other);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		if (i>0)
			printf(" ");
		printf("%d",R[i]);
	}
	printf("\n");
	return 0;
}