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

#define L 101010
#define N 26

char s[L],t[L];

int main()
{
	//freopen("b.in","r",stdin);
	while(scanf("%s%s",s,t)>0)
	{
		int n,i,j,k;
		scanf("%d\n",&n);
		int a[N][N];
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				a[i][j]=inf;
		for(i=0;i<N;i++)
			a[i][i]=0;
		while(n--)
		{
			char ci,cj;
			int w;
			scanf("%c %c %d\n",&ci,&cj,&w);
			i=ci-'a';
			j=cj-'a';
			MIN(a[i][j],w);
		}
		for(k=0;k<N;k++)
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
					MIN(a[i][j],a[i][k]+a[k][j]);
		int minc[N][N];
		int minw[N][N];
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				minw[i][j]=inf;
				for(k=0;k<N;k++)
					if(minw[i][j]>a[i][k]+a[j][k])
					{
						minw[i][j]=a[i][k]+a[j][k];
						minc[i][j]=k;
					}
			}
		int sL=strlen(s);
		int tL=strlen(t);
		if(sL!=tL){puts("-1");continue;}
		int ans=0;
		for(i=0;i<sL;i++)
		{
			int si=s[i]-'a';
			int ti=t[i]-'a';
			if(minw[si][ti]==inf) break;
			ans+=minw[si][ti];
			s[i]=minc[si][ti]+'a';
		}
		if(i<sL) puts("-1"); else 
			printf("%d\n%s\n",ans,s);
	}
	return 0;
}