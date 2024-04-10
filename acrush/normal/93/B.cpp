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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int n,w,m;
	scanf("%d%d%d",&n,&w,&m);
	int s=n*w;
	w*=m;
	for (int step=0;step<2;step++)
	{
		int left=w,idx=1,counter=0;
		if (step==1) printf("YES\n");
		for (int i=0;i<m;i++)
		{
			int space=s;
			bool first=true;
			while (space>0)
			{
				if (left==0)
				{
					left=w;
					idx++;
					counter=0;
				}
				int cnt=min(left,space);
				left-=cnt;
				space-=cnt;
				if (step==1) 
				{
					if (!first) printf(" ");
					first=false;
					printf("%d %.12lf",idx,(double)cnt/m);
				}
				if ((++counter)>2)
				{
					printf("NO\n");
					return 0;
				}
			}
			if (step==1) printf("\n");
		}
	}
	return 0;
}