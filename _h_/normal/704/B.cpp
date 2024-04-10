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

const ll inf = 1e16;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s, e;
	cin >> n >> s >> e;
	--s, --e;
	vector<ll> x(n), a(n), b(n), c(n), d(n);
	trav(y,x) cin >> y;
	trav(y,a) cin >> y;
	trav(y,b) cin >> y;
	trav(y,c) cin >> y;
	trav(y,d) cin >> y;
	vector<ll> dp(n+1, inf);
	dp[0] = 0;
	rep(i,0,n){
		vector<ll> nw(n+1, inf);
		rep(j,0,n){
			int k = min(s,e) <= i && i < max(s,e) ? (s<e ? -1 : 1) : 0;
			k += j;
			if(k < 0) continue;
			if(j == 0 && k == 0 && i+1 < n) continue;
			if(i == s){
				if(j > 0)
					nw[j] = min(nw[j], 
						dp[j-1] + d[i] +
						(i ? x[i] - x[i-1] : 0)*(j+k-1));
				nw[j] = min(nw[j],
					dp[j] + c[i] + 
					(i ? x[i] - x[i-1] : 0)*(j+k+1));
			} else if(i == e){
				if(k > 0)
					nw[j] = min(nw[j], 
						dp[j] + b[i] +
						(i ? x[i] - x[i-1] : 0)*(j+k-1));
				nw[j] = min(nw[j],
					dp[j+1] + a[i] + 
					(i ? x[i] - x[i-1] : 0)*(j+k+1));
			} else {
				if(j > 0)
					nw[j] = min(nw[j],
						dp[j] + a[i] + d[i] + 
						(i ? x[i] - x[i-1] : 0)*(j + k));
				if(k > 0)
					nw[j] = min(nw[j],
						dp[j] + c[i] + b[i] + 
						(i ? x[i] - x[i-1] : 0)*(j + k));
				if(j > 0 && k > 0){
					nw[j] = min(nw[j],
						dp[j-1] + d[i] + b[i] + 
						(i ? x[i] - x[i-1] : 0)*(j + k - 2));
				}	
				nw[j] = min(nw[j],
					dp[j+1] + a[i] + c[i] + 
					(i ? x[i] - x[i-1] : 0)*(j + k + 2));
			}
		}
		dp = nw;
	}
	cout << dp[0] << endl;
}