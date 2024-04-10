#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 1111
int n;
int a[N];
int f[N][N];

int F(int i,int j)
{
	int &res=f[i][j];
	if(res>=0) return res;
	if(j==n) return res=a[i];
	if(j==n-1) return res=max(a[i],a[j]);
	int res1=F(i,j+2)+max(a[j],a[j+1]);
	int res2=F(j+1,j+2)+max(a[i],a[j]);
	int res3=F(j,j+2)+max(a[i],a[j+1]);
	return res=min(min(res1,res2),res3);
}

vector<PII> ans;
void fnd(int i,int j)
{
	int res=F(i,j);
	if(j==n)
	{
		ans.pb(mp(i,i));
		return;
	}
	if(j==n-1)
	{
		ans.pb(mp(i,j));
		return;
	}
	if(res==F(i,j+2)+max(a[j],a[j+1]))
	{
		ans.pb(mp(j,j+1));
		fnd(i,j+2);
		return;
	}
	if(res==F(j+1,j+2)+max(a[i],a[j]))
	{
		ans.pb(mp(i,j));
		fnd(j+1,j+2);
		return;
	}
	if(res==F(j,j+2)+max(a[i],a[j+1]))
	{
		ans.pb(mp(i,j+1));
		fnd(j,j+2);
		return;
	}
	assert(0);
}

void print(PII a)
{
	if(a.X!=a.Y)
		printf("%d %d\n",a.X+1,a.Y+1);
	else
		printf("%d\n",a.X+1);
}

int main()
{
#ifdef MY_DEBUG
	freopen("d.in","r",stdin);
#endif
	while(scanf("%d",&n)>0)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		fill(f,255);
		int res=F(0,1);
		printf("%d\n",res);
		ans.cl;
		fnd(0,1);
		for(i=0;i<ans.sz;i++)
			print(ans[i]);
	}
	return 0;
}