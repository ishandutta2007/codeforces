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

const int M=two(7);
const int MOD=1000000007;
int n;

int f0[M],f1[M];
int a[M][M];

void multiply(int c[M][M],int _a[M][M],int _b[M][M])
{
	int a[M][M],b[M][M];
	memcpy(a,_a,sizeof(a));
	memcpy(b,_b,sizeof(b));
	for (int i=0;i<M;i++) for (int j=0;j<M;j++)
	{
		int64 t=0;
		for (int k=0;k<M;k++)
		{
			t+=(int64)a[i][k]*b[k][j];
			if ((k&7)==0) t%=MOD;
		}
		c[i][j]=(int)(t%MOD);
	}
}

void init()
{
	memset(a,0,sizeof(a));
	for (int set=0;set<two(n);set++) for (int set2=0;set2<two(n);set2++)
	{
		if ((set|set2)!=two(n)-1) continue;
		for (int set3=0;set3<two(n-1);set3++) ++a[set][set2|set3|(set3<<1)];
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	memset(f0,0,sizeof(f0));
	int w=0;
	f0[0]=1;
	int ret=1;
	for (n=1;n<=7;n++)
	{
		init();
		int m;
		scanf("%d",&m);
		if (m==0) continue;
		memset(f1,0,sizeof(f1));
		for (int set=0;set<two(w);set++) if (f0[set]>0) for (int set2=0;set2<two(w);set2++)
		{
			if ((set|set2)!=two(w)-1) continue;
			for (int set3=0;set3<two(n-1);set3++) 
			{
				int x=(set2|set3|(set3<<1));
				f1[x]+=f0[set];
				if (f1[x]>=MOD) f1[x]-=MOD;
			}
		}
		memcpy(f0,f1,sizeof(f0));
		m--;
		for (;m>0;m/=2)
		{
			if (m&1)
			{
				memset(f1,0,sizeof(f1));
				for (int i=0;i<M;i++)
				{
					int64 s=0;
					for (int j=0;j<M;j++) s=(s+(int64)f0[j]*a[j][i])%MOD;
					f1[i]=(int)s;
				}
				memcpy(f0,f1,sizeof(f0));
			}
			multiply(a,a,a);
		}
		ret=f0[two(n)-1];
		w=n;
	}
	printf("%d\n",ret);
	return 0;
}