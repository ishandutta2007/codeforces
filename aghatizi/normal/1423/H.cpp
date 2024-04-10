#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)

int gcd(int x,int y){ return (!y ? x : gcd(y, x%y)); }
const int maxn = 5e5 + 10;
const int SS = maxn * 4;
int par[maxn], sz[maxn], n;
vector<pii> edges[SS];
// vector<pii> adj[maxn]; // times, {u, v}
pii who[maxn];
vi get(int x,int y,int v=1,int l=0,int r=n){
	if(l >= y || r <= x)
		return vi{};
	if(l >= x && y >= r)
		return vi{v};
	int mid = (l + r) / 2;
	vi t1 = get(x, y, 2 * v, l, mid);
	vi t2 = get(x, y, 2 * v + 1, mid, r);
	for(auto t : t2)
		t1.push_back(t);
	return t1;
}
vector<pair<pii,pii> > hist;
int dad(int u){
	if(par[u] == u)
		return u;
	return dad(par[u]);
}
void mrg(int u,int v){
	u = dad(u), v = dad(v);
	if(u == v){
		hist.push_back({{-1, -1}, {-1, -1}});
		return;
	}
	if(sz[u] < sz[v])
		swap(u, v);
	hist.push_back({{u, v}, {sz[u], par[v]}});
	sz[u] += sz[v];
	par[v] = u;
}
void undo(){
	auto t = hist.back();
	hist.pop_back();
	if(t.X.X == -1)
		return;
	sz[t.X.X] = t.Y.X;
	par[t.X.Y] = t.Y.Y;
}
void add(int v,int val){
	//cout << "BIA" << v << " " << val << endl;
	if(val == 1){
		for(auto t : edges[v]){
			mrg(t.X, t.Y);
			//cout << "add edge" << " " << t.X << " " << t.Y << endl;
		}
	}
	else{
		for(int i=0; i<edges[v].size(); i++){
			undo();
			auto t = edges[v][i];
			//cout << "remove edge" << " " << t.X << " " << t.Y << endl;
		}
	}
}
map<pii, int> answer;
vi query[maxn];
void solve(int v=1,int l=0,int r=n){
	//cout << "HERE" << v << " " << l << " " << r << endl;
	if(r - l == 1){
		add(v, 1);
		for(auto x : query[l]){
			//cout << "GETTTTTT" << x << endl;
			answer[{l, x}] = sz[dad(x)];
		}
		add(v, -1);
		return;
	}
	add(v, 1);
	int mid = (l + r) / 2;
	solve(2 * v, l, mid);
	solve(2 * v + 1, mid, r);
	add(v, -1);
}
int start[maxn];
pair<int, pii> events[maxn];
int tps[maxn];
int32_t main(){
	int n2, q, k;
	cin >> n2 >> q >> k;
	for(int i=0; i<maxn; i++)
		par[i] = i, sz[i] = 1;
	int tim = 0;
	for(int i=0; i<q; i++){
		int tp;
		cin >> tp;
		tps[i] = tp;
		if(tp == 1){
			int u, v;
			cin >> u >> v;
			u--, v--;
			events[i] = {tim, {u, v} };
		}
		else if(tp == 2){
			int v; cin >> v; v--;
			query[i].push_back(v);
			who[i] = {i, v};
		}
		else{
			tim++;
			start[tim] = i;
		}
	}
	n = q;
	for(int i=0; i<q; i++){
		if(tps[i] == 1){
			int l = i, r;
			int cur_time = events[i].X;
			if(cur_time + k > tim)
				r = n;
			else
				r = start[cur_time + k];
			vi t = get(l, r);
			for(auto x : t)
				edges[x].push_back({events[i].Y});
			//cout << events[i].Y.X << " " << events[i].Y.Y << "___" << endl;
			//cout << l << " " << r << endl;
		}
	}
	//cout << "YOOO" << endl;
	solve();	
	for(int i=0; i<q; i++){
		if(tps[i] == 2){
			//cout << "***";
			cout << answer[who[i]] << endl;
		}
	}
}