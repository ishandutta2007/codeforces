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
#define mod 1000000009
#define maxn 100100

using namespace std;

vector<int> L[maxn];
vector<int> hld[maxn];
set<int> hold[maxn];
vector<int> inv [maxn];

vector<int> bro[maxn];

int foi[maxn];

int ok[maxn];
int x[maxn];
int y[maxn];

bool can(int x){
	for(vector<int> :: iterator it = inv[x].begin(); it < inv[x].end(); it++)
		if(!foi[*it] && hold[*it].size() == 1) return 0;
	return 1;
}

main(){

		int n;
		scanf("%d",&n);

		map<pii,int> mp;

		for(int i=0;i<n;i++){
			scanf("%d%d",x+i,y+i);
			mp[pii(x[i],y[i])] = i;
		}

		for(int i=0;i<n;i++) if(y[i]){
			if(mp.find(pii(x[i]-1,y[i]-1)) != mp.end())
				hold[i].insert(mp[pii(x[i]-1,y[i]-1)]),
				hld[i].pb(mp[pii(x[i]-1,y[i]-1)]),
				inv[mp[pii(x[i]-1,y[i]-1)]].pb(i);
			if(mp.find(pii(x[i],y[i]-1)) != mp.end())
				hold[i].insert(mp[pii(x[i],y[i]-1)]),
				hld[i].pb(mp[pii(x[i],y[i]-1)]),
				inv[mp[pii(x[i],y[i]-1)]].pb(i);
			if(mp.find(pii(x[i]+1,y[i]-1)) != mp.end())
				hold[i].insert(mp[pii(x[i]+1,y[i]-1)]),
				hld[i].pb(mp[pii(x[i]+1,y[i]-1)]),
				inv[mp[pii(x[i]+1,y[i]-1)]].pb(i);
			if(mp.find(pii(x[i]+1,y[i])) != mp.end())
				bro[i].pb(mp[pii(x[i]+1,y[i])]);
			if(mp.find(pii(x[i]-1,y[i])) != mp.end())
				bro[i].pb(mp[pii(x[i]-1,y[i])]);
		}

		set<int> pode;
		vector<int> ans;

		int pmen = 0;
		int last=-1;
		int qnt=0;

		oi:
		pode.clear();

		for(int i=0;i<n;i++) ok[i] = 1;
		for(int i=0;i<n;i++) if(hold[i].size() == 1 && !foi[i]) ok[*(hold[i].begin())] = 0;

		for(int i=0;i<n;i++) if(ok[i] && !foi[i]) pode.insert(i);
		
		while(pode.size()){

			int u;
			if(pmen) u = *(pode.begin());
			else u = *(--(pode.end()));
			pode.erase(u);
			debug("bota %d\n",u);
			if(foi[u]) continue;
			last=u;
			qnt++;

			if(y[u]){
				/*int o = 0;
				for(vector<int> :: iterator it = hld[u].begin(); it < hld[u].end(); it++)
					{debug("it %d\n",*it);if(!foi[*it]) o = 1;}
				assert(o);*/
				for(vector<int> :: iterator it = inv[u].begin(); it < inv[u].end(); it++)
					if(!foi[*it]) assert(hold[*it].size() > 1);
				int t = u;
				/*for(int i=0;i<n;i++) if(!foi[i] && can(i)){
					if(pmen)t = min(t,i);
					else t = max(t,i);
				}*/
				//assert(u==t);
				//u = t;
			}
			foi[u] = 1;
			ans.pb(u);

			for(vector<int> :: iterator it = inv[u].begin(); it < inv[u].end(); it++){
				if(foi[*it]) continue;
				assert(hold[*it].find(u) != hold[*it].end());
				hold[*it].erase(u);
				if(hold[*it].size() != 1) continue;
				if(pode.find(*(hold[*it].begin())) != pode.end()){
				pode.erase(*(hold[*it].begin())); debug("tira %d\n",*(hold[*it].begin()));}
			}

			for(vector<int> :: iterator it = hld[u].begin(); it != hld[u].end(); it++){

				debug("tenta liberar %d\n",*it);
				int ok = 1;
				for(vector<int> :: iterator it2 = inv[*it].begin(); it2 < inv[*it].end(); it2++)
					if(!foi[*it2] && hold[*it2].size() <= 1){debug("merda %d\n",*it2); ok = 0;}
				debug("\n\n");
				if(ok)
					pode.insert(*it);

			}

			

			

			pmen = 1 - pmen;

		}

		//for(int i=0;i<n;i++) assert(foi[i]);
		if(qnt != n){debug("!!!");
			//goto oi;

		
		}

		for(int i=0;i<n;i++)
			debug("%d ",ans[i]);
		debug("\n");

		long long r = 0;
		for(int i=0;i<n;i++)
			r = (r*n+ans[i])%mod;
		cout << r << endl;

}