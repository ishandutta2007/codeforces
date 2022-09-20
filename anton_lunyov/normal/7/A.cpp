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

char a[8][9];

int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%s",a[0])>0)
	{
		int ans=inf;
		int i,j;
		for(i=1;i<8;i++) scanf("%s",a[i]);
		int mask1,mask2;
		for(mask1=0;mask1<256;mask1++)
			for(mask2=0;mask2<256;mask2++)
			{
				int b[8][8]={0};
				int num=0;
				for(i=0;i<8;i++)
				{
					if(mask1 & bit(i))
					{
						num++;
						for(j=0;j<8;j++) b[i][j]=1;
					}
					if(mask2 & bit(i))
					{
						num++;
						for(j=0;j<8;j++) b[j][i]=1;
					}
				}
				for(i=0;i<8;i++)
				{
					for(j=0;j<8;j++)
					{
						if(a[i][j]=='W' && b[i][j]==1) break;
						if(a[i][j]=='B' && b[i][j]==0) break;
					}
					if(j<8) break;
				}
				if(i==8 && ans>num) ans=num;
			}
		printf("%d\n",ans);
	}
	return 0;
}