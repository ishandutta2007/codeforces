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

int gcd(int a,int b)
{
	int c;
	while(b)c=a%b,a=b,b=c;
	return a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y,b;
	while(scanf("%d",&x)>0)
	{
		int num=0,den=0;
		for(b=2;b<x;b++)
		{
			for(y=x;y;y/=b) num+=y%b;
			den++;
		}
		int d=gcd(num,den);
		num/=d;
		den/=d;
		printf("%d/%d\n",num,den);
	}
	return 0;
}