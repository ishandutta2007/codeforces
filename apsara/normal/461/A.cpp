#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clr_1(x) memset(x,-1,sizeof(x));
#define clrmax(x) memset(x,0x3f,sizeof(x));
#define clrvec(x,siz) for(int xx=0;xx<=siz;xx++)  x[xx].clear();
#define fop2   freopen(".in","r",stdin); //freopen(".out","w",stdout);
#define fop   freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
int num[400044];
priority_queue<long long>Q;
int main()
{
	int n;
	scanf("%d",&n);
	long long ss=0;
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]),ss+=num[i],Q.push(num[i]);
	// for(int i=0;i<n;i++)
	while(1)
	{
		long long a=Q.top();
		Q.pop();
		if(Q.empty())
			break;
		long long b=Q.top();
		Q.pop();
		ss+=a+b;
		Q.push(a+b);
	}
	printf("%I64d\n",ss);
}