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
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

int main()
{
	//freopen("A.in","r",stdin);
	int n;
	while(scanf("%d",&n)>0)
	{
		char a[1111][6];
		int i,j,k,h;
		for(i=0;i<n;i++)
		{
			if(i) scanf("%*s");
			char s1[4],s2[4];
			scanf("%s%s",s1,s2);
			a[i][0]=s1[0];
			a[i][1]=s1[1];
			a[i][2]=s2[1];
			a[i][3]=s2[0];
		}
		int ans=0;
		int mark[1111]={0};
		for(i=0;i<n;i++) if(!mark[i])
		{
			ans++;
			mark[i]=1;
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<4;k++)
				{
					for(h=0;h<4 && a[i][h]==a[j][(k+h)%4];h++);
					if(h==4) break;
				}
				if(k<4) mark[j]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}