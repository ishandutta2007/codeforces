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

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,a,b,c;
	while(scanf("%d%d%d%d%d",&n,&m,&a,&b,&c)>0)
	{
		char s[111][111]={0};
		int i,j;
		if(n%2 && m%2){puts("IMPOSSIBLE");continue;}
		if(n%2)
		{
			if(a<m/2){puts("IMPOSSIBLE");continue;}
			i=--n;
			for(j=0;j<m;j+=2) s[i][j]=s[i][j+1]=j/2%2+'m',a--;
		}
		if(m%2)
		{
			if(b<n/2){puts("IMPOSSIBLE");continue;}
			j=--m;
			for(i=0;i<n;i+=2) s[i][j]=s[i+1][j]=i/2%2+'m',b--;
		}
		if(c+a/2+b/2<m*n/4){puts("IMPOSSIBLE");continue;}
		for(i=0;i<n;i+=2)
			for(j=0;j<m;j+=2)
			{
				int x=i/2%2;
				int y=j/2%2;
				char ch=2*(2*x+y)+'a';
				if(c)
				{
					s[i][j]=s[i][j+1]=s[i+1][j]=s[i+1][j+1]=ch;
					c--;
				}
				else
				{
					if(a>1)
					{
						s[i][j]=s[i][j+1]=ch;
						s[i+1][j]=s[i+1][j+1]=ch+1;
						a-=2;
					}
					else
					{
						s[i][j]=s[i+1][j]=ch;
						s[i][j+1]=s[i+1][j+1]=ch+1;
						b-=2;
					}
				}
			}
		for(i=0;s[i][0];i++)
			puts(s[i]);
	}
	return 0;
}