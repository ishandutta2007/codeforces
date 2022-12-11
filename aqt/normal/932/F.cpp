 
// Problem : F. Escape Through Leaf
// Contest : ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/932/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
#include <bits/stdc++.h>
 
using namespace std;
 
 /*
struct line{
	mutable long long m, b, p;
	bool operator < (const line &l) const {
		return m < l.m;
	}
	bool operator < (long long x) const {
		return p < x;
	}
};
 
struct LineContainer : multiset<line, less<>>{
	const long long inf = LLONG_MAX/2;
	long long div(long long a, long long b){
		return a/b - ((a^b) < 0 && a%b);
	}
	bool inter(iterator x, iterator y){
		if(y == end()){
			x->p = inf;
			return 0;
		}
		if(x->m == y->m){
			x->p = (x->b <= y->b ? -inf : inf);
		}
		else{
			x->p = div(y->b - x->b, x->m - y->m);
		}
		return x->p >= y->p;
	}
	void add(long long m, long long b){
		auto z = insert({m, b, 0}), y = z++, x = y;
		while(inter(y, z)){
			z = erase(z);
		}
		if(x != begin() && inter(--x, y)){
			inter(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p){
			inter(x, erase(y));
		}
	}
	long long query(long long x){
		auto l = *lower_bound(x);
		return - l.m*x - l.b;
	}
};
*/

struct line{
	mutable long long m, b, p;
	bool operator < (const line &l) const{
		return m < l.m;
	}
	bool operator < (long long x) const {
		return p < x;
	}
};

struct LineContainer : multiset<line, less<>>{
	const long long inf = LLONG_MAX/2;
	bool inter(iterator x, iterator y){
		if(y == end()){
			x->p = inf;
			return 0;
		}
		if(x->m == y->m){
			x->p = (x->b <= y->b ? -inf : inf);
		}
		else{
			long long db = (y->b - x->b), dm = (x->m - y->m);
			x->p = db/dm - ((db^dm) < 0 && db%dm);
		}
		return x->p >= y->p;
	}
	void add(long long m, long long b){
		auto z = insert({m, b, 0}), y = z++, x = y;
		while(inter(y, z)){
			z = erase(z);
		}
		if(x != begin() && inter(--x, y)){
			inter(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p){
			inter(x, erase(y));
		}
	}
	long long query(long long n){
		auto l = *lower_bound(n);
		return -l.m * n - l.b;
	}
};
 
int N;
vector<int> graph[100005];
long long a[100005];
long long b[100005];
int par[100005];
long long dp[100005];
bool isleaf[100005];
 
LineContainer dfs(int n){
	isleaf[n] = 1;
	LineContainer lc1;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			auto lc2 = dfs(e);
			if(lc1.size() < lc2.size()){
				swap(lc1, lc2);
			}
			for(auto l : lc2){
				lc1.add(l.m, l.b);
			}
			isleaf[n] = 0;
		}
	}
	if(!isleaf[n]){
		dp[n] = lc1.query(a[n]);
	}
	lc1.add(-b[n], -dp[n]);
	return lc1;
}
 
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> b[i];
	}
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for(int i = 1; i<=N; i++){
		cout << dp[i] << " ";
	}
}