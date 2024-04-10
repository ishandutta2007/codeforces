#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdi pair<double,int>
#define eps 1e-9


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1010
using namespace std;
typedef long long ll;

vector<int> L[maxn];
int dist[maxn];
int foi0[maxn];
int foi[maxn];
int n,m;

int solve(int a){

	vector<int> v;
	queue<int> Q;
	Q.push(a);
	foi0[a] = 1;
	while(Q.size()){
		int b = Q.front();
		v.pb(b);
		Q.pop(); 
		for(int i=0;i<L[b].size();i++)
			if(!foi0[L[b][i]]){
				foi0[L[b][i]] = 1;
				Q.push(L[b][i]);
			}
	}

	int ret = -1;

	for(int i=0;i<v.size();i++){

		for(int j=0;j<v.size();j++)
			foi[v[j]] = 0;
		int b = v[i];
		foi[b] = 1;
		while(Q.size())
			Q.pop();
		Q.push(b);
		dist[b] = 0;
		int dmax = 0;
		int ok = 1;
		while(Q.size()){
			int c = Q.front();
			Q.pop();
			for(int j=0;j<L[c].size();j++)
				if(!foi[L[c][j]]){
					foi[L[c][j]] = 1;
					dist[L[c][j]] = 1 + dist[c];
					dmax = dist[L[c][j]];
					Q.push(L[c][j]);
				}
				else {
					if(abs(dist[c]-dist[L[c][j]]) != 1)
						ok = 0;
				}
		}
		if(ok)
			ret = max(ret, dmax);
	}

	return ret;
}

main(){

	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
	}

	int ans = 0;

	for(int i=0;i<n;i++){
		if(foi0[i])
			continue;
		int u = solve(i);
		if(u == -1){
			printf("-1\n");
			return 0;
		}
		ans += u;
	}

	printf("%d\n",ans);

}