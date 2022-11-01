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

const int maxn=1000000+5;

int n,leftc[maxn],rightc[maxn],key[maxn],father[maxn];
int sizeq,dfqueue[maxn];
double R[maxn];
int v1[maxn],v2[maxn];

void DFS(int p)
{
	if (p<0) return;
	if (leftc[p]<0)
	{
		dfqueue[sizeq++]=p;
		v1[p]=v2[p]=key[p];
	}
	else
	{
		DFS(leftc[p]);
		dfqueue[sizeq++]=p;
		DFS(rightc[p]);
		v1[p]=v1[leftc[p]];
		v2[p]=v2[rightc[p]];
	}
}
void DFS2(int p,double c1,double c2)
{
	if (leftc[p]<0)
	{
		R[p]=c2/c1;
		return;
	}
	DFS2(leftc[p],c1+1,c2+v1[rightc[p]]);
	DFS2(rightc[p],c1+1,c2+v2[leftc[p]]);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&father[i],&key[i]);
		father[i]--;
	}
	for (int i=0;i<n;i++) leftc[i]=rightc[i]=-1;
	int root=-1;
	for (int i=0;i<n;i++)
		if (father[i]<0)
			root=i;
		else if (leftc[father[i]]<0)
			leftc[father[i]]=i;
		else
			rightc[father[i]]=i;
	for (int i=0;i<n;i++)
		if (leftc[i]>=0 && key[rightc[i]]<key[leftc[i]])
			swap(leftc[i],rightc[i]);
	sizeq=0;
	DFS(root);
	map<int,int> ID;
	ID[-2000000000]=-1;
	for (int i=1;i<sizeq;i+=2)
		ID[key[dfqueue[i]]]=i;
	ID[+2000000000]=sizeq;
	DFS2(root,0,0);
	int nq;
	for (scanf("%d",&nq);nq>0;nq--)
	{
		int other;
		scanf("%d",&other);
		int pos=ID.lower_bound(other)->second-1;
		printf("%.18lf\n",R[dfqueue[pos]]);
	}
	return 0;
}