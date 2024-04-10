#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int v[maxn];
int f[maxn];

int need[maxn];
int has[maxn];

main(){

		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			f[v[i]]++;
		}

		int ok = 1;
		int qual;
		int imp = 0;

		for(int i=1;i<=n;i++){
			need[i] = f[i]/2;
			if(f[i]&1)imp++, qual = i;
		}

		need[qual]++;

		if(imp>1) ok = 0;

		int mism = 0;

		while(mism < n){
			if(v[mism] != v[n-mism-1]) break;
			mism++;
		}

		int m2 = n/2;

		while(m2 < n){
			if(v[m2] != v[n-m2-1]) break;
			m2++;
		}

		m2 = n-m2-1;

		if(imp && v[n/2] != qual) m2 = n/2;
		debug("m2 = %d\n",m2);

		if(ok==0){
			printf("0\n");
			return 0;
		}
		if(mism == n){
			printf("%I64d\n",((long long)n*(n+1))/2);
			return 0;
		}

		long long l1,r1,l2,r2;

		for(int i=0;i<(1+n)/2;i++)
			has[v[i]]++;

		int comp = 0;

		for(int i=1;i<=n;i++) if(need[i] <= has[i]) comp++;

		l1 = mism;
		r1 = m2;

		while(comp < n){
			r1++;
			if(r1 >= (n+1)/2){
				 has[v[r1]]++;
				 if(need[v[r1]] == has[v[r1]]) comp++;
			}
		}

		debug("l1 r1 = %I64d %I64d\n",l1,r1);

		memset(has,0,sizeof(has));

		r2 = n-mism-1;
		l2 = n-m2-1;

		comp = 0;

		for(int i=(n)/2;i<n;i++) has[v[i]]++;

		debug("has1 = %d\n",has[1]);

		for(int i=1;i<=n;i++) if(need[i] <= has[i]) comp++;
		
		while(comp < n){
			l2--;
			if(l2 < (n)/2){
				 has[v[l2]]++;
				 if(need[v[l2]] == has[v[l2]]) comp++;
			}
		}

		debug("l2 r2 = %I64d %I64d\n",l2,r2);

		long long ans = 0;

		ans += (l1+1) * (n-r1);
		ans += (l2+1) * (n-r2);
		ans -= (l1+1) * (n-r2);

		printf("%I64d\n",ans);

}