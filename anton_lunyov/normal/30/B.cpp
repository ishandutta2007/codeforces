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

int days[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	//freopen("in.txt","r",stdin);
	int d,m,y;
	while(scanf("%d.%d.%d",&d,&m,&y)>0)
	{
		int a[3];
		scanf("%d.%d.%d",a,a+1,a+2);
		sort(a,a+3);
		bool yes=false;
		do
		{
			int D=a[0];
			int M=a[1];
			int Y=a[2];
			if(Y%4==0) days[2]=29; else days[2]=28;
			if(1<=M && M<=12 && 1<=D && D<=days[M])
			{
				if(Y+18<y || Y+18==y && M<m || Y+18==y && M==m && D<=d) yes=true;
			}
		}
		while(next_permutation(a,a+3));
		puts(yes?"YES":"NO");
	}
	return 0;
}