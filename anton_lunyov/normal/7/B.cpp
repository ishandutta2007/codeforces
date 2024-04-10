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
	int t,m,i,j,n,x;
	while(scanf("%d%d",&t,&m)>0)
	{
		int mem[111]={0};
		int cnt=0;
		while(t--)
		{
			char com[111];
			scanf("%s",com);
			if(strcmp(com,"alloc")==0)
			{
				scanf("%d",&n);
				for(i=0;i<m;i=j)
				{
					for(j=i;j<m && mem[j]==0;j++);
					if(i==j) j++; else
					{
						if(j-i>=n)
						{
							printf("%d\n",++cnt);
							for(j=i;j<i+n;j++) mem[j]=cnt;
							break;
						}
					}
				}
				if(i==m) puts("NULL");
			}
			if(strcmp(com,"erase")==0)
			{
				scanf("%d",&x);
				if(x<=0 || x>cnt) puts("ILLEGAL_ERASE_ARGUMENT"); else
				{
					for(i=0;i<m && mem[i]!=x;i++);
					if(i==m) puts("ILLEGAL_ERASE_ARGUMENT"); else
						for(;i<m && mem[i]==x;i++) mem[i]=0;
				}
			}
			if(strcmp(com,"defragment")==0)
			{
				for(i=j=0;i<m;i++)
					if(mem[i]) mem[j++]=mem[i];
				for(;j<m;j++) mem[j]=0;
			}
		}
	}
	return 0;
}