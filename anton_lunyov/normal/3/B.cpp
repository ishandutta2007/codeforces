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
#define pi 3.1415926535897932385
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
//typedef long long LL;

#define N 111111
PII a[N],b[N];
int sa[N],sb[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,v;
	while(scanf("%d%d",&n,&v)>0)
	{
		int i,j;
		int alen=0;
		int blen=0;
		for(i=0;i<n;i++)
		{
			int t,vi;
			scanf("%d%d",&t,&vi);
			if(t==1) a[alen++]=mp(vi,i+1); else b[blen++]=mp(vi,i+1);
		}

		sort(a,a+alen);
		reverse(a,a+alen);
		sa[0]=0;
		for(i=0;i<alen;i++)
			sa[i+1]+=sa[i]+a[i].first;

		sort(b,b+blen);
		reverse(b,b+blen);
		sb[0]=0;
		for(i=0;i<blen;i++)
			sb[i+1]+=sb[i]+b[i].first;

		int maxi=-1;
		int maxj=-1;
		int maxv=0;
		for(i=0;i<=blen && 2*i<=v;i++)
		{
			j=min(v-2*i,alen);
			if(maxv<sb[i]+sa[j])
			{
				maxv=sb[i]+sa[j];
				maxi=i;
				maxj=j;
			}
		}
		printf("%d\n",maxv);
		bool first=true;
		for(i=0;i<maxi;i++)
		{
			if(first) first=false; else printf(" ");
			printf("%d",b[i].second);
		}
		for(i=0;i<maxj;i++)
		{
			if(first) first=false; else printf(" ");
			printf("%d",a[i].second);
		}
		printf("\n");
	}
	return 0;
}