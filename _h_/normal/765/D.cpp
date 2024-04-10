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
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	int n;
	cin >> n;
	vi f(n+1);
	rep(i,1,n+1) cin >> f[i];
	vector<bool> isfix(n+1);
	rep(i,1,n+1)
		if(f[f[i]] != f[i]){
			cout << -1 << endl;
			return 0;
		}
	vi g(n+1);
	rep(i,1,n+1) isfix[f[i]] = 1;
	vi h(1,0);
	rep(i,1,n+1) if(isfix[i]){
		g[i] = sz(h);
		h.push_back(i);
	}
	rep(i,1,n+1) g[i] = g[f[i]];
	int m = sz(h)-1;
	cout << m << endl;
	rep(i,1,n+1) cout << g[i] << ' ';
	cout << endl;
	rep(i,1,m+1) cout << h[i] << ' ';
	cout << endl;
}