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
#include <vector>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
 
using namespace std;

int v[100100];

vector<int> L[100100];
vector<int> u;

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		if(m == 1){
			printf("0\n");
			return 0;}

		long long sum = 0;

		scanf("%d",v);
		L[v[0]].pb(0);
		
		for(int i=1;i<m;i++){
			scanf("%d",v+i);
			sum += abs(v[i]-v[i-1]);
			L[v[i]].pb(i);
		}

		long long ans = sum;
		
		for(int i=1;i<=n;i++){

			if(L[i].size() == 0)continue;

			long long cur = sum;
			
			
			for(vector<int> :: iterator it = L[i].begin(); it < L[i].end(); it++){
				if(*it == 0){
					if(v[1]-i)u.pb(v[1]);}
				else if(*it == m-1){
					if(v[m-2]-i)u.pb(v[m-2]);}
				else{
					if(v[*it-1]-i)u.pb(v[*it-1]);
					if(v[*it+1]-i)u.pb(v[*it+1]);}
			}

			if(u.size() == 0)continue;
			sort(u.begin(), u.end());

			int val = u[(u.size()-1)/2];
			debug("i=%d val=%d\n",i,val);
			 	

			for(vector<int> :: iterator it = L[i].begin(); it < L[i].end(); it++){
				debug("it%d\n",*it);
				if(*it == 0){
					 if(v[1]-v[0]) cur = cur - abs(v[1]-v[0]) + abs(v[1]-val);}
				else if(*it == m-1){
					 if(v[m-1]-v[m-2])cur = cur - abs(v[m-1]-v[m-2]) + abs(val-v[m-2]);}
				else{
					if(v[*it]-v[*it-1])cur = cur - abs(v[*it]-v[*it-1]) + abs(val-v[*it-1]);
					if(v[*it]-v[*it+1])cur = cur - abs(v[*it]-v[*it+1]) + abs(val-v[*it+1]);
					debug("!");
				}
			}

			if(n <= 10){
			cur = 0;
			for(int j=1;j<m;j++){
				int a = v[j-1];
				int b = v[j];
				if(a == i)a = val;
				if(b == i)b = val;
				cur += abs(b-a);
			}}

			ans = min(ans,cur);
			u.clear();

			}

		printf("%I64d\n",ans);



			
		}