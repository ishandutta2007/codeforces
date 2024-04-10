#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	vi us(2*k), par(n,-1), w(n);
	trav(x, us) cin >> x, --x;
	trav(x, us) w[x] = 1;
	vector<vi> gr(n);
	rep(_,0,n-1){
		int x,y;
		cin >> x >> y;
		--x,--y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	function<void(int)> dfs = [&](int v){
		trav(u, gr[v]) if(u != par[v]){
			par[u] = v;
			dfs(u);
			w[v] += w[u];
		}
	};
	dfs(0);
	int v = 0;
	begin:
	trav(u, gr[v]){
		int res;
		if(u == par[v])
			res = w[0] - w[v];
		else
			res = w[u];
		if(2*res > w[0]){
			v = u;
			goto begin;
		}
	}
	vi d(n, -1);
	d[v] = 0;
	stack<int> st;
	st.push(v);
	while(!st.empty()){
		int x = st.top();
		st.pop();
		trav(y, gr[x]) if(d[y] == -1){
			d[y] = 1 + d[x];
			st.push(y);
		}
	}
	long long ans = 0;
	trav(x, us) ans += d[x];
	cout << ans << endl;
}