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
#define maxn 100100
#define mod 1000000007

using namespace std;

int mrk[maxn];
int deg[maxn];
int need[maxn];
int see[maxn];
int foi[maxn];

vector<int> L[maxn];

int upp(double d){

	d += eps;
	if(abs(d-(int)d) < 2*eps) return (int)d;
	return 1+(int)d;

}

main(){

		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);

		for(int i=0;i<k;i++){
			int u;
			scanf("%d",&u), u--;
			mrk[u] = 1;
		}

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			deg[a]++;
			deg[b]++;
			if(!mrk[a] && !mrk[b])
				L[a].pb(b), L[b].pb(a);
		}

		double low=0, up=1;

		vector<int> ans;
		vector<int> cur;
		
		for(int t=0;t<50;t++){

			double mid = (low+up)/2;
			debug("mid = %lf\n",mid);
			cur.clear();

			for(int i=0;i<n;i++) if(!mrk[i]){
				need[i] = upp(mid*deg[i]);
				debug("%d needs %d\n",i,need[i]);
			}

			queue<int> Q;
			int tirou = 0;

			for(int i=0;i<n;i++) if(!mrk[i]){
				see[i] = L[i].size();
				if(see[i] < need[i]) Q.push(i);
			}

			for(int i=0;i<n;i++)
				foi[i] = 0;

			while(Q.size()){
				int u = Q.front();
				Q.pop();
				if(foi[u]) continue;
				debug("go %d\n",u);
				foi[u] = 1;
				tirou++;
				for(vector<int> :: iterator it = L[u].begin(); it < L[u].end(); it++){
					see[*it]--;
					if(see[*it] < need[*it]) Q.push(*it);
				}
			}

			for(int i=0;i<n;i++) if(!mrk[i] && !foi[i]) cur.pb(i);

			if(tirou + k == n)
				up = mid;
			else
				low = mid, ans = cur;

		}

		printf("%d\n",ans.size());
		for(vector<int> :: iterator it = ans.begin(); it < ans.end(); it++)
			printf("%d ",1+*it);
		printf("\n");

}