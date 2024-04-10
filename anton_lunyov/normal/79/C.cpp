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

#define N 101010
char s[N];
int L[N];
int dp[N];

int main()
{
#ifdef MY_DEBUG
	freopen("c.in","r",stdin);
#endif
	while(scanf("%s",s)>0)
	{
		int n=strlen(s);
		int i,j;
		for(i=0;i<n;i++)
			L[i]=inf;
		int m;
		for(scanf("%d",&m);m--;)
		{
			char w[15];
			scanf("%s",w);
			int k=strlen(w);
			for(i=0;i<=n-k;i++)
			{
				if(L[i]<=k) continue;
				for(j=0;j<k && w[j]==s[j+i];j++);
				if(j==k) L[i]=k;
			}
		}
		int maxi=n;
		dp[n]=0;
		for(i=n-1;i>=0;i--)
		{
			dp[i]=min(L[i]-1,dp[i+1]+1);
			if(dp[maxi]<dp[i]) maxi=i;
		}
		if(maxi==n) maxi=0;
		printf("%d %d\n",dp[maxi],maxi);
	}
	return 0;
}