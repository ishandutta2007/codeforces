#define _USE_MATH_DEFINES
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


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

const int MAX_M = 2 * 100000;
int n,m,k;
bool h[MAX_M];
vector<int> edges[MAX_M];

int tbl[MAX_M];

typedef Pii P;

int solve(){
	int s,t;
	cin>>s>>t; s--,t--;
	if(!h[s]) return -1;

	fill(tbl,tbl + MAX_M,INF);
	int ret = 0;

	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,s));
	tbl[s] = 0;
	while(!q.empty()){
		int pre = q.top().second;
		int point = q.top().first;
		q.pop();
		FOREACH(it,edges[pre]){
			int next_point= (h[*it]) ? 0 : point + 1;
			if(tbl[*it] <= point + 1) continue;
			ret = max(ret,point + 1);
			if(t == *it) 
				return ret;
			tbl[*it] = next_point;
			q.push(P(next_point,*it));
		}
	}

	return -1;
}

int main(){
	cin>>n>>m>>k;
	FOR(i,k){
		int x;
		cin>>x;
		h[x - 1] = true;
	}
	FOR(i,m){
		int u,v;
		cin>>u>>v; u--,v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans = solve();

	cout << ans << endl;
	return 0;
}