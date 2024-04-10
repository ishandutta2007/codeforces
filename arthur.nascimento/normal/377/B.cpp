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

pii bug[100100];


int last[100100];
int ans[100100];

struct tr {
	int first,second,idx;
	bool operator<(tr comp)const{
		return first < comp.first;}
	};
	
tr v[100100];


main(){

		int n,m,s;

		scanf("%d%d%d",&m,&n,&s);

		for(int i=0;i<n;i++)
			scanf("%d",&bug[i].first),
			bug[i].second = i;

		sort(bug,bug+n);

		for(int i=0;i<m;i++)
			scanf("%d",&v[i].first);
			
		for(int i=0;i<m;i++)
			scanf("%d",&v[i].second);
			
		for(int i=0;i<m;i++)
			v[i].idx = i;

		sort(v,v+m);

		int a=0,b=100100;

		while(a != b){


			int mid = (a+b)/2;
			int ok = 1;
			int C = s;

			debug("mid = %d\n",mid);

			multiset<pii> S;

			int pa = n-1;
			int pb = m-1;

			while(pa >= 0){

				while(pb >= 0 && v[pb].first >= bug[pa].first){
						S.insert(pii(v[pb].second,v[pb].idx));
						pb--;
						}

				if(S.empty()){
					ok = 0;
					break;
					}

				pii u = *(S.begin());
				S.erase(S.begin());

				C -= u.first;

				debug("u.first = %d\n",u.first);

				if(C < 0){
					ok = 0;
					debug("!ok\n");
					}

				for(int i=0;i<mid && pa >= 0;i++){
					ans[bug[pa].second] = u.second;
					pa--;
					}

			}
	

			if(ok){
				b = mid;
				for(int i=0;i<n;i++)
					last[i] = ans[i];

				}
			else
				a = mid + 1;

		}
		
		debug("a=%d\n",a);
		if(a > 100000){
			printf("NO\n");
			return 0;}

		printf("YES\n");

		for(int i=0;i<n;i++)
			printf("%d\n",last[i]+1);

		}