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

#define inf (999999999)
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
#define maxn 100100

using namespace std;

vector<int> L[maxn];
int v[maxn];

pll dfs(int x){

	debug("dfs %d\n",x);
	if(x != 0 && L[x].size() == 0){

		if(v[x]) return pll(1,0);
		return pll(0,1);

	}

	pll ret;
	

	if(v[x] == 0){

		 ret = pll(0,1);

		vector<pll> u;

		for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
			u.pb(dfs(*it));

		vector<pll> pi;
		long long cur = 1;

		for(int i=0;i<u.size();i++){
			cur *= (u[i].first + u[i].second);
			cur %= mod;
			pi.pb(pll(cur,0));
		}

		cur = 1;
		for(int i=u.size()-1;i>=0;i--){
			cur *= (u[i].first+u[i].second);
			cur %= mod;
			pi[i].second = cur;
		}

		ret.second = pi[0].second;

		for(int i=0;i<u.size();i++){

			long long pp = 1;
			if(i != u.size()-1)pp *= pi[i+1].second;
			pp %= mod;
			if(i)pp *= pi[i-1].first;
			pp %= mod;
			ret.first += u[i].first * pp;
			ret.first %= mod;
		}

		

	}

	if(v[x]){

	    ret = pll(1,0);
		vector<pll> u;

		for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
			u.pb(dfs(*it));

		for(int i=0;i<u.size();i++){
			ret.first *= (u[i].first+u[i].second);
			ret.first %= mod;
		}


	
	}

	ret.first %= mod;
	ret.second %= mod;
	return ret;

}


main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int p;
			scanf("%d",&p);
			L[p].pb(i);
		}

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		printf("%I64d\n",dfs(0).first);

}