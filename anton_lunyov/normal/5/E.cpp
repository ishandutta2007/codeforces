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

int a[2*N];
int L[2*N];
int R[2*N];
map<int,int> ind;
VI lst[N];

int lst_fnd(int k,int x)
{
	int l=-1;
	int r=lst[k].sz;
	while(l+1<r)
	{
		int m=(l+r)/2;
		if(lst[k][m]<x) l=m; else r=m;
	}
	return r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)>0)
	{
		ind.cl;
		int cnt=0;
		int i,j,k;
		for(i=1;i<=n;i++) lst[i].cl;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[n+i]=a[i];
			if(!ind[a[i]]) ind[a[i]]=++cnt;
			lst[ind[a[i]]].pb(i);
		}
		for(i=1;i<=cnt;i++)
		{
			int len=lst[i].sz;
			for(j=0;j<len;j++) lst[i].pb(lst[i][j]+n);
		}
		for(i=0;i<2*n;i++)
		{
			for(j=i-1;j>=0 && a[i]>=a[j];j=L[j]);
			L[i]=j;
		}
		for(i=2*n-1;i>=0;i--)
		{
			for(j=i+1;j<2*n && a[i]>=a[j];j=R[j]);
			R[i]=j;
		}
		LL ans1=0;
		LL ans2=0;
		for(i=0;i<n;i++)
			if(R[i]<2*n)
			{
				if(L[n+i]>=n) L[n+i]-=n;
				if(R[i]>=n) R[i]-=n;
				if(L[n+i]==R[i])
				{
					ans1++;
					ans2+=lst[ind[a[i]]].sz/2-1;
				}
				else
				{
					ans1+=2;
					if(L[n+i]>i) R[i]+=n; else
					if(R[i]<i) R[i]+=n;
					int k=ind[a[i]];
					int l=lst_fnd(k,L[n+i]);
					int r=lst_fnd(k,R[i]);
					ans2+=r-l-1;
				}
			}
			else ans2+=lst[ind[a[i]]].sz/2-1;
		printf("%I64d\n",ans1+ans2/2);
	}
	return 0;
}