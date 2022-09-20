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

#define M 26
#define N 55
char a[N][N];

int main()
{
#ifdef MY_DEBUG
	freopen("c.in","r",stdin);
#endif
	int n,m,q;
	while(scanf("%d%d%d",&n,&m,&q)>0)
	{
		int x1,y1,x2,y2;
		int i,j,k,h;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='S') x1=i,y1=j;
				if(a[i][j]=='T') x2=i,y2=j;
			}
		}
		int dx[4]={1,-1,0,0};
		int dy[4]={0,0,1,-1};
		int p[M]={0};
		for(i=M-q;i<M;i++) p[i]=1;
		string res="-1";
		int best=N*N;
		do
		{
			int t[N][N];
			fill(t,1);
			PII bfs[N*N];
			int len=0;
			bfs[len++]=mp(x2,y2);
			t[x2][y2]=0;
			for(k=0;k<len;k++)
			{
				int x=bfs[k].X;
				int y=bfs[k].Y;
				if(x==x1 && y==y1) break;
				int T=t[x][y]+1;
				for(h=0;h<4;h++)
				{
					int i=x+dx[h];
					int j=y+dy[h];
					if(0<=i && i<n && 0<=j && j<m && t[i][j]>T)
					{
						char c=a[i][j];
						if(c=='S' || p[c-'a'])
						{
							t[i][j]=T;
							bfs[len++]=mp(i,j);
						}
					}
				}
			}
			int curt=t[x1][y1];
			if(best<curt) continue;
			string cur="";
			vector<PII> b;
			b.pb(mp(x1,y1));
			for(;;)
			{
				vector<PII> c;
				char minc='z'+1;
				for(int it=0;it<b.sz;it++)
				{
					int x=b[it].X;
					int y=b[it].Y;
					int T=t[x][y]-1;
					for(h=0;h<4;h++)
					{
						int i=x+dx[h];
						int j=y+dy[h];
						if(0<=i && i<n && 0<=j && j<m && t[i][j]==T)
						{
							c.pb(mp(i,j));
							MIN(minc,a[i][j]);
						}
					}
				}
				if(minc=='T') break;
				cur+=minc;
				sort(all(c));
				b.cl;
				for(i=0;i<c.sz;i++)
				{
					int x=c[i].X;
					int y=c[i].Y;
					if(a[x][y]==minc && (i==0 || c[i]!=c[i-1]))
						b.pb(c[i]);
				}
			}
			if(best>curt || best==curt && res>cur)
			{
				res=cur;
				best=curt;
			}
		}
		while(next_permutation(p,p+M));
		printf("%s\n",res.c_str());
	}
	return 0;
}