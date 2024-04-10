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
#define pi 3.1415926535897932385
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
//typedef long long LL;

int bfsx[64];
int bfsy[64];
int len;
int t[8][8];
int prevx[8][8];
int prevy[8][8];
string move[8][8];

void check(int x,int y,int xx,int yy,int txy,string s)
{
	if(0<=x && x<8 && 0<=y && y<8 && t[x][y]<0)
	{
		bfsx[len]=x;
		bfsy[len++]=y;
		t[x][y]=txy;
		prevx[x][y]=xx;
		prevy[x][y]=yy;
		move[x][y]=s;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	char a[3],b[3];
	while(scanf("%s%s",a,b)>0)
	{
		int y1=a[0]-'a';
		int x1=a[1]-'1';
		int y2=b[0]-'a';
		int x2=b[1]-'1';
		fill(t,255);
		len=0;
		check(x2,y2,0,0,0,"");
		int x,y,xx,yy,k;
		for(k=0;k<len;k++)
		{
			x=bfsx[k];
			y=bfsy[k];
			int tt=t[x][y]+1;
			check(x-1,y-1,x,y,tt,"RU");
			check(x-1,y,x,y,tt,"U");
			check(x-1,y+1,x,y,tt,"LU");
			check(x,y-1,x,y,tt,"R");
			check(x,y+1,x,y,tt,"L");
			check(x+1,y-1,x,y,tt,"RD");
			check(x+1,y,x,y,tt,"D");
			check(x+1,y+1,x,y,tt,"LD");
		};
		printf("%d\n",t[x1][y1]);
		for(x=x1,y=y1;x!=x2 || y!=y2;x=xx,y=yy)
		{
			printf("%s\n",move[x][y].data());
			xx=prevx[x][y];
			yy=prevy[x][y];
		}
	}
	return 0;
}