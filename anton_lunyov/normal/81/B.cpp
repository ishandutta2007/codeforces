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
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

char s[333];

bool dig(char c)
{
	return '0'<=c && c<='9';
}


int main()
{
#ifdef MY_DEBUG
	freopen("b.in","r",stdin);
#endif
	while(gets(s))
	{
		string w="";
		int i,j;
		for(i=0;s[i];)
		{
			if(s[i]==',') w+=s[i],w+=' ',i++; else
			if(s[i]=='.') w+=" ...",i+=3; else
				w+=s[i],i++;
		}
		string a="";
		char prev=' ';
		for(j=w.sz-1;j>=0 && w[j]==' ';j--);
		for(i=0;i<=j;i++)
		{
			if(w[i]==' ' && prev==' ') continue;
			prev=w[i];
			a+=w[i];
		}
		for(i=0;i<a.sz;i++)
		{
			if(a[i]==' ')
			{
				if(i>0 && a[i-1]==',') printf(" "); else
				if(i<a.sz-1 && a[i+1]=='.') printf(" "); else
				if(i>0 && i<a.sz-1 && dig(a[i-1]) && dig(a[i+1]))
					printf(" ");
			}
			else
				printf("%c",a[i]);
		}
		printf("\n");
	}
	return 0;
}