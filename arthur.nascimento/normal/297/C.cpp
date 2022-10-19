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
#define max3(a,b,c) max(max(a,b),c)

using namespace std;

int ans[2][maxn];

main(){

		int n;
		scanf("%d",&n);

		vector<pii> v;
		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			v.pb(pii(u,i));
		}

		sort(v.begin(),v.end());

		int t = n - 2*(n/3);
		for(int i=0;i<t;i++){
			ans[1][v[i].second] = 0, ans[0][v[i].second] = v[i].first;
			if(i%2) ans[0][v[i].second] = 0, ans[1][v[i].second] = v[i].first;
		}

		int a = 0;
		if(n%3==2)a = 1;

		for(int i=t;i<n;i+=2){
			ans[0][v[i].second] = ans[1][v[i+1].second] = a;
			ans[1][v[i].second] = v[i].first-a;
			ans[0][v[i+1].second] = v[i+1].first-a;
			a++;
		}

		printf("YES\n");

		for(int i=0;i<n;i++)
			printf("%d ",ans[0][i]);
		printf("\n");
		for(int i=0;i<n;i++)
			printf("%d ",ans[1][i]);
		printf("\n");

}