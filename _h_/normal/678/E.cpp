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
	int n;
	cin >> n;
	vector<vector<double> > p(n, vector<double>(n));
	rep(i,0,n) rep(j,0,n) 
		cin >> p[i][j];
	int t = 1<<n;
	vector<vector<double> > dp(n, vector<double>(t,-1));
	function<double(int,int)> calc = [&](int w, int m){
		if(dp[w][m] == -1){
			if(!(m&1)) return dp[w][m] = 0;
			if(m == 1) return dp[w][m] = 1;
			rep(i,0,n) if(i != w && ((m>>i)&1)){
				double pr = p[w][i];
				dp[w][m] = max(dp[w][m], 
					calc(w, m^(1<<i))*pr + (1-pr)*calc(i, m^(1<<w)));
			}
		}
		return dp[w][m];
	};
	double ans = 0;
	rep(i,0,n)
		ans = max(ans, calc(i, t-1));
	cout.precision(10);
	fixed(cout);
	cout << ans << endl;
}