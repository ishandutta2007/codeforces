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
#define maxn 500500

using namespace std;

int f[maxn];

int v[maxn];

vector<int> divs[maxn];
vector<int> sqfdivs[maxn];

int ord[maxn];

int sieve[maxn];

int legal[maxn];

int state[maxn];

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		long long ans = 0;

		for(int i=2;i<=500000;i++) if(sieve[i] == 0){

			sieve[i] = i;

			for(int j=2*i;j<=500000;j+=i) sieve[j] = i;

		}
		ord[1] = 1;
		sieve[1] = 1;
		legal[1] = 1;

		for(int i=2;i<=500000;i++){
		
			long long p = sieve[i];
			if(i % (p*p) != 0 && legal[i/p]) legal[i] = 1;

			if(i == 2) assert(legal[i]);
			if(!legal[i]) continue;
			

			ord[i] = -ord[i/p];

			for(int j=i;j<=500000;j+=i) sqfdivs[j].pb(i);

		}


		int on = 0;

		while(q--){

			int u;
			scanf("%d",&u), u--;

			if(state[u] == 0){

				state[u] = 1;
				long long inc = on;
				int t = v[u];
		
				for(vector<int> :: iterator it = sqfdivs[t].begin(); it < sqfdivs[t].end(); it++)
					inc += f[*it] * ord[*it];
					
				for(vector<int> :: iterator it = sqfdivs[t].begin(); it < sqfdivs[t].end(); it++)
					f[*it]++;

				//debug("inc = %I64d\n",inc);
				ans += inc;
				printf("%I64d\n",ans);
				on++;
				continue;
			}

			state[u] = 0;
			on--;
			long long inc = on;
			int t = v[u];
			//debug("tira %d\n",t);

			for(vector<int> :: iterator it = sqfdivs[t].begin(); it < sqfdivs[t].end(); it++)
				f[*it]--;
		
			for(vector<int> :: iterator it = sqfdivs[t].begin(); it < sqfdivs[t].end(); it++)
					inc += f[*it] * ord[*it];

			ans -= inc;
			//debug("inc = %I64d\n",inc);
			printf("%I64d\n",ans);

		}

}