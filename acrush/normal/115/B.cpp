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

const int maxn=150+5;

int n,m;
int L[maxn],R[maxn];
char s[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		L[i]=R[i]=-1;
		for (int j=0;j<m;j++) if (s[j]=='W')
		{
			if (L[i]<0) L[i]=j;
			R[i]=j;
		}
	}
	for (;n>0 && L[n-1]<0;n--);
	int ret=0;
	int current=0,direction=1;
	for (int i=0;i<n;i++)
	{
		int next=current;
		if (direction==1) 
		{
			if (R[i]>=0) checkmax(next,R[i]);
			if (i+1<n && R[i+1]>=0) checkmax(next,R[i+1]);
		}
		else
		{
			if (L[i]>=0) checkmin(next,L[i]);
			if (i+1<n && L[i+1]>=0) checkmin(next,L[i+1]);
		}
		ret+=abs(current-next);
		if (i+1<n) ret++;
		current=next;
		direction=-direction;
	}
	printf("%d\n",ret);
	return 0;
}