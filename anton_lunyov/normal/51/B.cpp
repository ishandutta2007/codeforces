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

#define N 5555
char tmp[N];
char s[N];
int num[N];
int ans[N];

int main()
{
	//freopen("B.in","r",stdin);
	while(gets(tmp))
		strcat(s,tmp);
	int n=strlen(s);
	int last=0;
	int len=0;
	int i;
	for(i=0;i<n;i++)
	{
		i++;
		bool close=false;
		if(s[i]=='/') i++,close=true;
		i++;
		char c=s[i];
		for(;s[i]!='>';i++);
		if(!close)
		{
			if(c=='d') num[last]++; else
			if(c=='a') num[++last]=0;
		}
		else
		{
			if(c=='a') ans[len++]=num[last--];
		}
	}
	sort(ans,ans+len);
	for(i=0;i<len;i++)
		printf("%d%c",ans[i],i<len-1?' ':'\n');
	return 0;
}