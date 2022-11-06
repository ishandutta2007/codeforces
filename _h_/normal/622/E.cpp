#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const ll inf = 1LL<<60;

int n;
vector<vi> cs;
vi par, h, pp;

int ans = 0;

void dfs(int v){
	for(int c : cs[v])
		if(c != par[v]){
			pp[c] = v ? pp[v] : c;
			h[c] = 1+h[v];
			par[c] = v;
			dfs(c);
		}
}

int main(){
	scanf("%d",&n);
	cs.resize(n);
	par.resize(n);
	h.resize(n);
	pp.resize(n);
	par[0] = -1;
	rep(_,0,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		cs[x].pb(y),cs[y].pb(x);
	}
	dfs(0);
	vector<vi> ls(n);
	rep(i,1,n) if(cs[i].size() == 1){
		ls[pp[i]].pb(h[i]-1);
	}
	rep(i,1,n) if(pp[i] == i){
		int sz = ls[i].size();
		if(sz == 0) continue;
		sort(allof(ls[i]));
		int res = 0;
		rep(j,0,sz)
			res = max(res, ls[i][j] + sz - j - 1);
		ans = max(ans, res+1);
	}
	printf("%d\n",ans);
}