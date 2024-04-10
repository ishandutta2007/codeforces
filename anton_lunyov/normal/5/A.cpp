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
	char ss[1111];
	int chat=0;
	int ans=0;
	while(gets(ss))
	{
		if(ss[0]=='+') chat++; else
		if(ss[0]=='-') chat--; else
		{
			int i;
			for(i=0;ss[i]!=':';i++);
			ans+=chat*(strlen(ss)-i-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}