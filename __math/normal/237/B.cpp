#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
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
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

int d[50];
int c[10000];

Pii make_index(int x){
	int a = 0;
	while(d[a+1] <= x) a++;
	return Pii(a+1,x-d[a]+1);
}

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>d[i+1];
	for(int i = 1; i <= n; i++) d[i] += d[i-1];
	int m = d[n];
	FOR(i,d[n]) cin>>c[i];

	typedef pair<Pii,Pii> P;
	vector<P> ans;
	FOR(i,m){
		int idx = find(c+i,c+m,i+1) - c;
		Pii p = make_index(i);
		Pii q = make_index(idx);
		swap(c[i],c[idx]);
		if(p != q)
			ans.push_back(P(p,q));
	}

	cout << ans.size() << endl;
	FOR(i,sz(ans)){
		printf("%d %d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
	}

	return 0;
}