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

const int maxsize=1<<20;

int n;
char p[maxsize];
int val[maxsize],key[maxsize];
map<int,int> ID;
int c[maxsize];
int64 s[maxsize][5];

void update(int v,int H,int T,int key,int cd)
{
	if (H==T)
	{
		c[v]+=cd;
		for (int i=0;i<5;i++)
			s[v][i]=0;
		if (c[v])
			s[v][0]+=val[H];
	}
	else
	{
		int M=(H+T)/2;
		int v1=v*2+1;
		int v2=v*2+2;
		if (key<=M)
			update(v1,H,M,key,cd);
		else
			update(v2,M+1,T,key,cd);
		c[v]=c[v1]+c[v2];
		for (int i=0;i<5;i++)
			s[v][i]=s[v1][i]+s[v2][(i+5-c[v1]%5)%5];
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	set<int> S;
	for (int i=0;i<n;i++)
	{
		char str[10];
		scanf("%s",str);
		p[i]=str[0];
		if (p[i]!='s')
		{
			scanf("%d",&key[i]);
			S.insert(key[i]);
		}
	}
	vector<int> P(S.begin(),S.end());
	int m=SIZE(P);
	for (int i=0;i<m;i++)
	{
		val[i]=P[i];
		ID[P[i]]=i;
	}
	memset(s,0,sizeof(s));
	memset(c,0,sizeof(c));
	for (int i=0;i<n;i++)
		if (p[i]=='a')
			update(0,0,m-1,ID[key[i]],1);
		else if (p[i]=='d')
			update(0,0,m-1,ID[key[i]],-1);
		else
			printf("%I64d\n",s[0][2]);
	return 0;
}