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

const int maxsize=5000000+5;

int p[maxsize],a[maxsize];
bool visited[maxsize*3];

int main()
{
	int mb,mc;
	scanf("%d%d",&mb,&mc);
	memset(p,255,(mc+1)*sizeof(int));
	for (int k=2;k<=mc;k++) if (p[k]<0)
		for (int i=k;i<=mc;i+=k)
			p[i]=k;
	int64 R=0;
	for (int b=1;b<=mb;b++) R+=min((int64)b*b,(int64)mc);
	memset(visited,false,sizeof(visited));
	for (int c=1;c<=mc;c++)
	{
		a[0]=1;
		int n=1;
		for (int d=c;d>1;)
		{
			int g=p[d],e=0;
			for (;d%g==0;d/=g) e++;
			int new_n=n*(e+1);
			for (int i=n;i<new_n;i++) a[i]=a[i-n]*g;
			n=new_n;
		}
		for (int i=0;i<n;i++)
		{
			int x=a[i];
			int b=c/x+x;
			if (b&1) continue;
			b/=2;
			if (b<=mb && b>=x && b>=1)
			{
				visited[-b+(b-x)+maxsize+maxsize]=visited[-b-(b-x)+maxsize+maxsize]=true;
				R--;
			}
		}
	}
	R*=2;
	for (int i=0;i<maxsize*3;i++) if (visited[i]) R++;
	cout<<R<<endl;
	return 0;
}