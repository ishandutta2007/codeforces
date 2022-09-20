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

#define N 1010101
char s[N];
int a[N];
VI lst[2*N];
int L[N];

int main()
{
	//freopen("in.txt","r",stdin);
	while(gets(s+1))
	{
		int n=strlen(s+1);
		int i,j,k;
		for(i=0;i<=2*n;i++) lst[i].cl;
		a[0]=0;
		lst[n+0].pb(0);
		for(i=1;i<=n;i++)
		{
			if(s[i]=='(') a[i]=a[i-1]+1; else a[i]=a[i-1]-1;
			lst[n+a[i]].pb(i);
		}
		L[0]=-1;
		for(i=1;i<=n;i++)
		{
			for(j=i-1;j>=0 && a[j]>=a[i];j=L[j])
				;
			L[i]=j;
		};
		int ans=0;
		int cnt=1;
		for(i=1;i<=n;i++)
		{
			if(L[i]<=lst[n+a[i]][0]) k=lst[n+a[i]][0]; else
			{
				int l=0;
				int r=lst[n+a[i]].sz;
				while(l+1<r)
				{
					int m=(l+r)/2;
					if(lst[n+a[i]][m]<L[i]) l=m; else r=m;
				}
				k=lst[n+a[i]][r];
			};
			if(ans<i-k)
			{
				ans=i-k;
				cnt=1;
			}
			else
				if(ans==i-k) cnt++;
		}
		if(ans==0) cnt=1;
		printf("%d %d\n",ans,cnt);
	}
	return 0;
}