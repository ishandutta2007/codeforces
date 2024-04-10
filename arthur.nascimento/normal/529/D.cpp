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
#define maxn 20200

using namespace std;

vector<int> tira[200100];
vector<int> bota[200200];

int ans[200200];

main(){

		int n,m,T;
		scanf("%d%d%d",&n,&m,&T);

		vector<pii> v;
		int free = 1;

		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d:%d:%d",&a,&b,&c);
			int d = (60*a+b)*60+c;
			v.pb(pii(d,i));
		}

		sort(v.begin(), v.end());


		int pm = 0;
		int pcur = 0;
		for(int i=0;i<n;i++)
			bota[v[i].first].pb(i);	

		int imp = 0;		

		int last = 1;
		int tira_last;

		for(int i=0;i<200200;i++){

			for(vector<int> :: iterator it = tira[i].begin(); it < tira[i].end();it++)
				pcur--;

			for(vector<int> :: iterator it = bota[i].begin(); it < bota[i].end(); it++){
				if(pcur == m){
					tira[tira_last].pop_back();
					ans[v[*it].second] = last;
					tira[i+T].pb(last);
					tira_last = i+T;
					continue;
				}
				int u  = free++;
				
				ans[v[*it].second] = u;
				last = u;
				pcur++;
				pm = max(pm,pcur);
				tira[i+T].pb(u);
				tira_last = i+T;
			}

		}

		if(imp || pm != m){
			 printf("No solution\n");
			 return 0;
		}
		printf("%d\n",free-1);
		for(int i=0;i<n;i++)
			printf("%d\n",ans[i]);
		
}