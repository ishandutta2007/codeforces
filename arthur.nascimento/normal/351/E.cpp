#include <iostream>
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

#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int T[2020];

void update(int idx){
	idx++;
	while(idx < 3030){
		T[idx]++;
		idx += idx&-idx;}
	}

int query(int idx){
	idx++;
	int ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;}
	return ret;}

map<int,int> mp;

int v[2020];
int z[2020];
int V[2020];

bool comp(int a,int b){
	return v[a] < v[b];}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			z[i] = v[i] = abs(v[i]);	
			}

		sort(z,z+n);

		mp[z[0]] = 0;
		for(int i=1;i<n;i++)
			if(z[i] != z[i-1])
				mp[z[i]] = 1 + mp[z[i-1]];

		for(int i=0;i<n;i++)
			v[i] = mp[v[i]];

		for(int i=0;i<n;i++)
			V[i] = i;

		sort(V,V+n,comp);

		int ans = 0;

		for(int i=0;i<n && v[V[i]] == v[V[0]];i++)
			update(V[i]);

		for(int i=1;i<n;i++){debug("i=%d\n",i);

			if(v[V[i]] != v[V[i-1]]){

				for(int j=i;v[V[j]] == v[V[i]] && j < n;j++){debug("j = %d V = %d\n",j,V[j]);
					ans += min(query(V[j]),query(n)-query(V[j]));}

				for(int j=i;v[V[j]] == v[V[i]] && j < n;j++)
					update(V[j]);

				
			
			}


		}

		printf("%d\n",ans);

	}