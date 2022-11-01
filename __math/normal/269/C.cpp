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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct edge{
	int t,id;
	int c,dir;
};

vector<edge> e_idx[2*100000];

int main(){
	int n,m; cin>>n>>m;
	FOR(i,m){
		int f,t;
		edge e; cin>>f>>t>>e.c;
		f--; t--;
		e.id = i;
		e.dir = -1;
		e.t = t;
		e_idx[f].push_back(e);
		e.t = f;
		e.dir = -2;
		e_idx[t].push_back(e);
	}

	vector<int> sum(n);
	FOR(i,n) FOR(j,sz(e_idx[i])){
		edge& e = e_idx[i][j];
		sum[i] += e.c;
	}
	FOR(i,n) sum[i] /= 2;

	vector<int> anses(m,-1);
	queue<int> p;
	FOR(j,sz(e_idx[0])){
		edge& e = e_idx[0][j];
		sum[e.t] -= e.c;
		anses[e.id] = e.dir == -1 ? 0 : 1;
		if(sum[e.t] == 0 && e.t != n-1){
			p.push(e.t);
		}
	}

	while(!p.empty()){
		int cur_idx = p.front(); p.pop();
		FOR(i,sz(e_idx[cur_idx])){
			edge& e = e_idx[cur_idx][i];
			if(anses[e.id] != -1) continue;
			//i ---> e.t
			anses[e.id] = e.dir == -1 ? 0 : 1;
			sum[e.t] -= e.c;
			if(sum[e.t] == 0 && e.t != n-1) p.push(e.t);
		}
	}

	FOR(i,m) cout << anses[i] << endl;

	return 0;
}