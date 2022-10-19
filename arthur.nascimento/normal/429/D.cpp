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

#define min3(a,b,c) min(min(a,b),c)
#define pb push_back
#define sq(x) (((long long)x)*(x))
#define d(a,b) (sq(a.first-b.first)+sq(a.second-b.second))

using namespace std;

int select(vector<int> v,int k){

	if(v.size() == 1)
		return v[0];
	
	int u = rand()%v.size();

	vector<int> a,b;

	for(int i=0;i<v.size();i++)
		if(v[i] < v[u] || (v[i] == v[u] && i < u))
			a.pb(v[i]);
		else
			b.pb(v[i]);

	int ret;

	if(a.size() >= k-1)
		ret = select(a,k);
	else
		ret = select(b,k-a.size());

	a.clear();
	b.clear();

	return ret;

} 

long long get(vector<pll> v,int a,int b){

	if(v.size() < 2)
		return 1LL<<60;
	if(v.size() == 2)
		return d(v[0],v[1]);
	if(v.size() == 3)
		return min3(d(v[0],v[1]), d(v[0],v[2]), d(v[1],v[2]));

	//vector<int> x;

	//for(int i=0;i<v.size();i++)
		//x.pb(v[i].second);

	//int t = select(x,x.size()/2);

	//x.clear();

	int t = (a+b)/2;

	vector<pll> l,r,c;

	for(int i=0;i<v.size();i++)
		if(v[i].second <= t)
			l.pb(v[i]);
		else
			r.pb(v[i]);

	long long u = min(get(l,a,t), get(r,t+1,b));
	
	l.clear();
	r.clear();

	for(int i=0;i<v.size();i++)
		if(sq(v[i].second-t) <= u)
			c.pb(v[i]);

	for(int i=0;i<c.size();i++)
		for(int j=i+1;j<min(i+2,(int)c.size());j++)
			u = min(u,d(c[i],c[j]));

	c.clear();

	return u;

}

main(){

		srand(time(0));

		int n;
		scanf("%d",&n);

		scanf("%*d");

		vector<pll> v;
		v.pb(pll(0,0));

		for(int i=1;i<n;i++){
			int u;
			scanf("%d",&u);
			v.pb(pll(v[v.size()-1].first+u,i));
		}

		sort(v.begin(),v.end());

		printf("%I64d\n",get(v,0,n-1));

}