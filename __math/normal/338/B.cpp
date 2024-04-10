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
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000009; // check!!!
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }


int n,m,d;
bool evil[ten(5)],used[ten(5)];
vector<int> e[ten(5)];

int prv[ten(5)];
int depth[ten(5)];

int search_leaf(int v){
	if(used[v]) return -1;
	used[v] = true;
	FOR(i,sz(e[v])){
		int ret = search_leaf(e[v][i]);
		if(ret != -1) return ret;
	}
	if(evil[v]) return v;
	else return -1;
}

void duild_depth(int v,int l,int p){
	if(used[v]) return;
	used[v] = true;
	depth[v] = p;
	prv[v] = l;
	FOR(i,sz(e[v])){
		duild_depth(e[v][i],v,p+1);
	}
}

vector<int> ans;
void build_ans(int v,int p){
	if(used[v]) return;
	used[v] = true;
	if(p < 0) return;
	ans.push_back(v);
	FOR(i,sz(e[v])){
		build_ans(e[v][i],p-1);
	}
}

int main(){
	cin>>n>>m>>d;
	FOR(i,m) {
		int x; cin>>x; x--;
		evil[x] = true;
	}
	FOR(i,n-1){
		int x,y; cin>>x>>y; x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	memset(used,0,sizeof(used));
	int leaf = search_leaf(0);
	int most_far = leaf;
	int r;
	memset(used,0,sizeof(used));
	duild_depth(leaf,-1,0);

	FOR(i,n) if(evil[i]){
		if(depth[most_far] < depth[i]) most_far = i;
	}
	r = depth[most_far];
	while(true){
		memset(used,0,sizeof(used));
		duild_depth(most_far,-1,0);

		int tmp = most_far;
		FOR(i,n) if(evil[i]){
			if(depth[tmp] < depth[i]) tmp = i;
		}
		if(r == depth[tmp]){
			leaf = most_far;
			most_far = tmp;
			break;
		} else {
			leaf = most_far;
			most_far = tmp;
			r = depth[tmp];
		}
	}

	int center = most_far;
	FOR(i,depth[most_far]/2){
		center = prv[center];
	}
	vector<int> centers;
	centers.push_back(center);
	if(depth[most_far] % 2 != 0){
		centers.push_back(prv[center]);
	}

	int nw_depth = d-(depth[most_far]+1)/2;
	FOR(i,sz(centers)){
		memset(used,0,sizeof(used));
		build_ans(centers[i],nw_depth);
	}

	set<int> tmp(ans.begin(),ans.end());

	cout << sz(tmp) << endl;
}