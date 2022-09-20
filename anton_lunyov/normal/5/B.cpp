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

#define N 1111

char s[N][N];
int len[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	int m=0;
	for(n=0;gets(s[n]);n++)
	{
		len[n]=strlen(s[n]);
		MAX(m,len[n]);
	}
	for(i=0;i<=m+1;i++) printf("*");
	printf("\n");
	int p=0;
	for(i=0;i<n;i++)
	{
		printf("*");
		if((len[i]+m)%2==0)
		{
			for(j=0;j<(m-len[i])/2;j++) printf(" ");
			printf("%s",s[i]);
			for(j=0;j<(m-len[i])/2;j++) printf(" ");
		}
		else
		{
			for(j=0;j<(m-len[i])/2+p;j++) printf(" ");
			printf("%s",s[i]);
			for(j=0;j<(m-len[i])/2+!p;j++) printf(" ");
			p=!p;
		}
		printf("*\n");
	}
	for(i=0;i<=m+1;i++) printf("*");
	printf("\n");
	return 0;
}