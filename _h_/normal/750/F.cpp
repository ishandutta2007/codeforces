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
#define sz(v) int((v).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

vector<vi> mem(128);

bool done = 0;

void say(int x){
	done = 1;
	cout << "! " << x << endl;
}

int CNT;

int ask(int x){
	if(sz(mem[x])) return sz(mem[x]);
	if(++CNT > 16){
		for(int i = 1; i; i += 2);
	}
	cout << "? " << x << endl;
	int ans;
	cin >> ans;
	if(ans == 0) exit(0);
	else if(ans == 2){
		say(x);
	}
	mem[x].resize(ans);
	trav(y, mem[x]) cin >> y;
	return ans;
}

void solve(){
	CNT = 0;
	done = 0;
	mem.assign(128, vi());
	int h;
	cin >> h;
	if(h == 0) exit(0);
	vi path;
	function<bool(int,int,int)> reachLeaf = [&](int v, int par, int steps){
		ask(v);
		if(done) return false;
		if(sz(mem[v]) == 1) return true;
		if(steps == 0) return false;
		int nx = mem[v][0];
		if(nx == par) nx = mem[v][1];
		return reachLeaf(nx, v, steps-1);
	};
	function<void(int,int)> rek = [&](int v, int par){
		path.push_back(v);
		int deg = ask(v);
		if(done) return;
		if(deg == 1) return;
		int u = mem[v][0];
		if(u == par) u = mem[v][1];
		rek(u, v);
	};
	function<void(int,int,int)> f = [&](int v, int h, int child){
		cerr << "nod " << v << " har hjd " << h << " och nod " << child << " under sig." << endl;

		ask(v);
		if(done) return;

		vi ab;
		trav(u, mem[v]) if(u != child) ab.push_back(u);

		assert(sz(ab) == 2);

		if(h >= 4){
			trav(u, ab){
				ask(u);
				if(done) return;
			}
			trav(u, ab)
				trav(w, mem[u]) if(w != v){
					if(CNT == 16){
						say(w);
					} else
						ask(w);
					if(done) return;
				}
			assert(done);
		} else {
			int u;
			if(reachLeaf(ab[0],v,h-1))
				u = ab[1];
			else
				u = ab[0];
			if(done) return;
			f(u, h+1, v);
		}
	};
	rek(1+(123123%((1<<h)-1)),-1);
	if(done) return;
	if(sz(path) == 1){
		f(mem[path[0]][0], 1, path[0]);
	} else {
		reverse(all(path));
		int h = (sz(path)+1)/2;
		f(path[h], h, path[h-1]);
	}
	assert(done);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
		cerr << "bra!" << endl;
	}
}