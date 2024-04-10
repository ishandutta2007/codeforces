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
#define maxn 200200			
#define mod 1000000007
 
using namespace std;

vector<int> v[maxn];

struct cyc {
	int u;
	bool operator<(cyc comp)const{
		return v[u].size() < v[comp.u].size();
	}

};

int foi[maxn];
int pi[maxn];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",pi+i), pi[i]--;

		int cont = 0;

		for(int i=0;i<n;i++) if(!foi[i]){

			int pos = i;
			while(!foi[pos]){
				v[cont].pb(pos);
				foi[pos] = 1;
				pos = pi[pos];
			}
			debug("ok + %d\n",v[cont].size());
			cont++;

		}

		vector<cyc> r;
		for(int i=0;i<cont;i++){
			cyc ss;
			ss.u = i;
			r.pb(ss);
		}
		sort(r.begin(),r.end());

		int ok = 1;
		if(v[r[0].u].size() == 1){
			printf("YES\n");
			int y = v[r[0].u][0];
			for(int i=0;i<n;i++) if(i != y)
				printf("%d %d\n",y+1,i+1);
			return 0;
		}

		if(v[r[0].u].size() != 2) ok = 0;

		for(int i=0;i<r.size()-1;i++)
			if(v[r[i+1].u].size() % v[r[0].u].size() != 0) ok = 0;

		if(!ok){
			printf("NO\n");
			return 0;
		}

		printf("YES\n");

		printf("%d %d\n",v[r[0].u][0]+1,v[r[0].u][1]+1);

		for(int i=0;i<r.size()-1;i++){

			vector<int> small;
			for(int j=0;j<v[r[0].u].size();j++)
				small.pb(v[r[0].u][j]);
			vector<int> big;
			for(int j=0;j<v[r[i+1].u].size();j++)
				big.pb(v[r[i+1].u][j]);
			for(int j=0;j<big.size();j++)
				printf("%d %d\n",big[j]+1,small[j%small.size()]+1);

		}

}