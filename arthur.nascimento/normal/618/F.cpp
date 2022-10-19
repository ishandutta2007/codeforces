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
#define maxn 1001000

typedef long long ll;
using namespace std;

int a[maxn];
int b[maxn];

ll sa[maxn];
ll sb[maxn];

pii foi[maxn];

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	for(int i=0;i<n;i++)
		scanf("%d",b+i);

	int flip = 0;

	sa[0] = a[0];
	sb[0] = b[0];

	for(int i=1;i<n;i++){
		sa[i] = sa[i-1] + a[i];
		sb[i] = sb[i-1] + b[i];
	}

	if(sa[n-1] < sb[n-1]){
		flip = 1;
		for(int i=0;i<n;i++)
			swap(sa[i],sb[i]);
	}

	int p = 0;

	for(int i=0;i<n;i++)
		foi[i] = pii(-1,-1);

	for(int i=0;i<n;i++){

		while(sa[p] < sb[i])
			p++;

		int r = sa[p]-sb[i];

		if(foi[r].first+1){
			int a1 = foi[r].second, a2 = p, b1 = foi[r].first, b2 = i;
			if(flip)
				swap(a1,b1), swap(a2,b2);
			printf("%d\n",a2-a1);
			for(int j=a1+1;j<=a2;j++)
				printf("%d ",j+1);
			printf("\n%d\n",b2-b1);
			for(int j=b1+1;j<=b2;j++)
				printf("%d ",j+1);
			return 0;	
		}
		if(r == 0){
			int a1 = -1, a2 = p, b1 = -1, b2 = i;
			if(flip)
				swap(a1,b1), swap(a2,b2);
			printf("%d\n",a2-a1);
			for(int j=a1+1;j<=a2;j++)
				printf("%d ",j+1);
			printf("\n%d\n",b2-b1);
			for(int j=b1+1;j<=b2;j++)
				printf("%d ",j+1);
			return 0;
		}
		foi[r] = pii(i,p);

	}

}