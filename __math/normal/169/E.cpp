#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;

int N;
ll L,V1,V2;
typedef pair<double,double> P;

int main(){
	cin>>N>>L>>V1>>V2;
	vector<double> cho(N);
	for(int i = 0; i < N; i++) cin >> cho[i];
	double len = L * V2 / (double)(V1+V2); 
	vector<P> p;
	FOREACH(it,cho){
		double mx = *it+len;
		p.push_back(P(*it,min(2.0 * L, mx)));
		if(mx > 2 * L)
			p.push_back(P(0.0,mx - 2.0 * L));
	}

	typedef pair<double,int> Q;
	vector<Q> q;
	q.push_back(Q(0.0,0));
	FOREACH(it,p){
		q.push_back(Q((*it).first,1));
		q.push_back(Q((*it).second,-1));
	}
	sort(q.begin(),q.end());
	q.push_back(Q(2.0 * L, 0));
	int cnt = 0;
	FOREACH(it,q){
		cnt += (*it).second;
		(*it).second = cnt;
		if(cnt > N) {cout << "error" << endl; return -1;}
	}

	vector<double> ans(N+1);
	FOREACH(it,q){
		double next = (it +1 == q.end() ? 2 * L : (*(it+1)).first);
		ans[(*it).second] += (next - (*it).first);
	}

	FOREACH(it,ans){
		printf("%.20lf\n", (*it) / (2 * L));
	}

	return 0;
}