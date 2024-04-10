#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

typedef long long ll;
using namespace std;

int a[maxn];

double p[2*maxn];
double p2[2*maxn];

double acc[2*maxn];

main(){	

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	sort(a,a+n);

	int ev = 0;

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[j] > a[i])
				ev++;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[j] > a[i])
				p[a[j]-a[i]] += 1.0/ev;

	for(int i=0;i<=5000;i++)
		for(int j=0;j<=5000;j++)
			p2[i+j] += p[i]*p[j];

	acc[0] = p2[0];
	for(int i=1;i<=10000;i++)
		acc[i] = acc[i-1] + p2[i];

	double ans = 0;

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[j] > a[i])
				ans += (1.0/ev) * acc[a[j]-a[i]-1];

	printf("%.10lf\n",ans);

}