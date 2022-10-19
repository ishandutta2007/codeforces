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
#define maxn 200200

using namespace std;

int pai[maxn];
int len[maxn];

int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

void merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	pai[a] = b;
	len[b] += len[a];
}

int ans[maxn];
int foi[maxn];

main(){

		int n;
		scanf("%d",&n);

		vector<pii> v;

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			pai[i] = i;
			len[i] = 1;
			v.pb(pii(u,i));
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		int maior = 0;

		for(int i=0;i<n;i++){

			int u = v[i].second;

			debug("processa %d\n",u);
	
			if(u)
				if(foi[u-1])
					merge(u,u-1);
			if(u != n-1)
				if(foi[u+1])
					merge(u,u+1);

			int t = len[find(u)];
			debug("t = %d\n",t);

			foi[u] = 1;

			while(maior < t){
				maior++;
				ans[maior] = v[i].first;
			}

		}

		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");

}