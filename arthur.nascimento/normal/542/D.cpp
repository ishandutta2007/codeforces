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

map<long long,int> mp;
map<long long,int> mp2;

vector<long long> v[50500];
long long n;
int nd;

int cont = 0;

int dp[10100][2010];

int idx[1001000];

int get(long long d,int p){

	if(n%d != 0) return 0;
	int u;
	if(d <= 10000000 && d*d <= n) u = idx[d];
	else u = nd - idx[n/d] - 1;
	if(p == cont) return (d == n) ? 1 : 0;
	if(dp[u][p]+1) return dp[u][p];
	int ret = get(d,p+1);
	for(int i=0;i<v[p].size();i++)
		if(log(d) + log(v[p][i]) < log(n) + 1e-4)ret += get(d*v[p][i],p+1);
		else break;
	return dp[u][p] = ret;

}



main(){

		cin >> n;

		vector<long long> div;

		for(long long i=1;i*i<=n;i++) if(n%i == 0){
			div.pb(i);
			if(i*i != n)
				div.pb(n/i);
		}

		int u = 0;

		sort(div.begin(), div.end());

		nd = div.size();

		for(vector<long long> :: iterator it = div.begin(); it < div.end(); it++){

			if(*it <= 10000000 && *it**it <= n) idx[*it] = u;
			mp2[*it] = u;
			u++;
			if(*it == 1 || *it == 2) continue;	
	
			long long aux = *it-1;
			int t = 1;
			long long p;

			for(long long i=2;i*i<=aux;i++) if(aux%i == 0){
				while(aux%i == 0) aux /= i;
				if(aux != 1) t = 0;
				p = i;				
			}

			if(t == 0) continue;
			if(aux != 1) p = aux;
			if(mp.find(p) == mp.end()) mp[p] = cont++;
			//debug("v[%d].pb %I64d\n",mp[p],*it);
			v[mp[p]].pb(*it);

		}

		debug("cont %d\n",cont);

		memset(dp,-1,sizeof(dp));

		cout << get(1,0) << endl;

}