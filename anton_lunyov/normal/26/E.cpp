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

bool first=true;
int s;

void print(int i)
{
	if(first) first=false; else printf(" ");
	printf("%d",i+1);
}

void print2(int i)
{
	s++;
	print(i);
	print(i);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,w;
	while(scanf("%d%d",&n,&w)>0)
	{
		int a[111];
		int mini=0;
		int sum=0;
		int i,j,k;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[mini]>a[i]) mini=i;
			sum+=a[i];
		}
		first=true;
		if(n==1)
		{
			if(w!=a[0]) puts("No"); else
			{
				puts("Yes");
				for(i=0;i<a[0];i++) print2(0);
				printf("\n");
			}
			continue;
		}
		if(w<=0 || w>sum){puts("No");continue;}
		k=mini;
		int cur[111]={0};
		if(w>=a[k])
		{
			puts("Yes");
			s=0;
			for(i=0;i<a[k]-1;i++) print2(k);
			for(i=0;i<n;i++) if(i!=k)
			{
				for(j=0;j<a[i] && s<w-1;j++) print2(i);
				cur[i]=j;
			}
			print(k);
			for(i=0;i<n;i++) if(i!=k)
				for(j=cur[i];j<a[i];j++) print2(i);
			print(k);
			printf("\n");
			continue;
		}
		if(w==1){puts("No");continue;}
		puts("Yes");
		int h=!k;
		print(h);
		for(i=0;i<a[k]-1;i++) print2(k);
		print(h);
		cur[h]=1;
		s=1;
		for(i=0;i<n;i++) if(i!=k)
		{
			for(j=cur[i];j<a[i] && s<w-1;j++) print2(i);
			cur[i]=j;
		}
		print(k);
		for(i=0;i<n;i++) if(i!=k)
			for(j=cur[i];j<a[i];j++) print2(i);
		print(k);
		printf("\n");
	}
	return 0;
}