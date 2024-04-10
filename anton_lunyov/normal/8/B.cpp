#include <stdio.h>
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

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

#define N 111
#define M 222

int a[M][M];
int t[M][M];
int bfsx[M*M],bfsy[M*M];
int len;

void add(int x,int y,int txy)
{
	if(t[x][y]<0 && a[x][y])
	{
		t[x][y]=txy;
		bfsx[len]=x;
		bfsy[len++]=y;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	char c[N];
	while(gets(c))
	{
		fill(a,0);
		int x=N,y=N;
		a[x][y]=1;
		int i,k;
		for(i=0;c[i];i++)
		{
			int dx,dy;
			if(c[i]=='U') dx=-1,dy=0;
			if(c[i]=='D') dx=1,dy=0;
			if(c[i]=='L') dx=0,dy=-1;
			if(c[i]=='R') dx=0,dy=1;
			x+=dx;y+=dy;
			a[x][y]=1;
		}
		int n=i;
		int ex=x,ey=y;
		fill(t,255);
		len=0;
		add(N,N,0);
		for(k=0;k<len;k++)
		{
			x=bfsx[k];
			y=bfsy[k];
			int txy=t[x][y]+1;
			add(x+1,y,txy);
			add(x-1,y,txy);
			add(x,y+1,txy);
			add(x,y-1,txy);
		};
		puts(t[ex][ey]==n?"OK":"BUG");
	}
	return 0;
}