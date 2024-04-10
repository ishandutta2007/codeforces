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

#define pb push_back

using namespace std;

vector<int> L[1001000];

int q[1001000];

bool cmp(pii a,pii b){
	return a.second < b.second;}

vector<int> dfs(int x){

	if(L[x].size() == 0){
		vector<int> u;
		u.pb(x);
		return u;
	}

	vector<pii> u;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		vector<int> v = dfs(*it);
		for(vector<int> :: iterator it2 = v.begin(); it2 < v.end(); it2++)
			u.pb(pii(*it,*it2));
		v.clear();
	}

	sort(u.begin(), u.end(), cmp);

	vector<int> ret;
	ret.pb(x);

	int cur = 1;

	int A = 1000001;
	int B = A+1;

	debug("x = %d\n",x+1);

	int sum = x ? 1 : 0;

	for(vector<pii> :: iterator it = u.begin(); it < u.end(); it++){

		q[it->first]++;
		debug("+ %d (t = %d)\n",1+it->first,it->second+1);

		if(q[it->first] > q[B] && A != it->first)
			B = it->first;
		if(q[B] > q[A])
			swap(A,B);

		if(A == B)
			B = 1000001;

		debug(": %d\n",(max(q[A],sum+q[B])));

		if(max(q[A],sum+q[B]) > cur)
			cur = max(q[A],sum+q[B]),
			ret.pb(it->second);

	}

	debug("x = %d\n",x+1);
	for(int i=0;i<ret.size();i++)
		debug("%d ",ret[i]+1);
	debug("\n");

	return ret;

}

int get(int x,int t){

	if(L[x].size() == 0)
		return 0;

	vector<int> u;

	for(int i=0;i<L[x].size();i++)
		if(L[x][i] <= t)
			u.pb(get(L[x][i],t));

	sort(u.begin(), u.end());
	reverse(u.begin(), u.end());

	if(u.size() == 0) return 0;

	int ret = u[0];
	if(x != 0 && u.size() > 1 && u[0] == u[1])
		ret++;

	debug("x = %d ret = %d\n",x+1,ret);
	return ret;

}

main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<=n;i++){
			int p;
			scanf("%d",&p), p--;
			L[p].pb(i);
		}

		vector<int> v = dfs(0);

		vector<int> :: iterator it = v.begin();
		it++;

		int t = 0;
		for(int i=1;i<=n;i++){
			if(*it == i && it < v.end())
				it++, t++;
			printf("%d ",t+1);
			debug("i = %d\n",i);
			//printf("%d ",get(0,i)+1);
		}
		//printf("%d",get(0)+1);

		printf("\n");
			
}