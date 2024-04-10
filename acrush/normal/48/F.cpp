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

const int maxn=500000+5;

int m,n,sc,c[maxn],w[maxn],d[maxn];
int64 r1;
double r2;

void split(int H,int T,int sp)
{
	if (H>=T) return;
	if (sp<=0) return;
	int kw=w[(H+T)/2];
	int kc=c[(H+T)/2];
	int i=H,j=T;
	for (;i<=j;)
	{
		for (;(int64)w[i]*kc<(int64)kw*c[i];i++);
		for (;(int64)w[j]*kc>(int64)kw*c[j];j--);
		if (i<=j)
		{
			swap(c[i],c[j]);
			swap(w[i],w[j]);
			swap(d[i],d[j]);
			i++;
			j--;
		}
	}
	int total=0;
	for (int k=H;k<=j;k++) 
	{
		total+=c[k];
		if (total>sp) 
		{
			total=sp+1;
			break;
		}
	}
	if (sp<total) split(H,j,sp);
	for (int k=j+1;k<i;k++) 
	{
		total+=c[k];
		if (total>sp) 
		{
			total=sp+1;
			break;
		}
	}
	if (sp>total) split(i,T,sp-total);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&m,&n,&sc);
	for (int i=0;i<n;i++) scanf("%d",&c[i]);
	for (int i=0;i<n;i++) scanf("%d",&w[i]);
	for (int i=0;i<n;i++) scanf("%d",&d[i]);
	r1=0;
	r2=0;
	for (;m>0;m--)
	{
		split(0,n-1,sc);
		int left=sc;
		for (int i=0;i<n && left>0;i++)
		{
			int cnt=min(left,c[i]);
			if (cnt==c[i]) 
				r1+=w[i];
			else 
			{
				int64 a=(int64)cnt*w[i];
				int64 b=c[i];
				r1+=a/b;
				r2+=(double)(a%b)/(double)b;
			}
			left-=cnt;
		}
		for (int i=0;i<n;i++) w[i]-=d[i];
	}
	double e=floor(r2);
	r1+=(int)(e+0.5);
	r2-=e;
	printf("%I64d",r1);
	char str[1024];
	sprintf(str,"%.18lf",r2);
	printf("%s",str+1);
	printf("\n");
	return 0;
}