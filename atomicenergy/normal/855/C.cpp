#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;


long long  a[100005][3][11];
vector<vector<long long> > g;
long long mod = 1000000007;
long long  lessCols;
long long  moreCols;

void solve(long long  v, long long  f){

	
	for(long long  i = 0; i < g[v].size(); i++){
		if(g[v][i] == f) continue;
		solve(g[v][i], v);
	}
	
	for(long long  i=0; i<11; i++){
		a[v][0][i] = 0;
		a[v][1][i] = 0;
		a[v][2][i] = 0;
	}
	a[v][0][0] = lessCols;
	a[v][1][1] = 1;
	a[v][2][0] = moreCols;
	for(long long  i=0; i<g[v].size(); i++){
		if(g[v][i] == f) continue;
		
		for(long long  sum = 10; sum>=0; sum--){
			long long  ans1 = 0;
			long long  ans2 = 0;
			long long  ans3 = 0;
			for(long long  k=0; k<=sum; k++){
				ans1 += (a[v][0][sum-k] * (a[g[v][i]][2][k] + a[g[v][i]][1][k]+ a[g[v][i]][0][k]))%mod;
				ans2 += (a[v][1][sum-k] * a[g[v][i]][0][k])%mod; 
				ans3 += (a[v][2][sum-k] * (a[g[v][i]][2][k] + a[g[v][i]][0][k]))%mod; 
				ans1%=mod;
				ans2%=mod;
				ans3%=mod;
			}
			a[v][0][sum] = ans1;
			a[v][1][sum] = ans2;
			a[v][2][sum] = ans3;
		}
	}


}

int main() {
	long long  n, m, k, x;
	
	cin >> n >> m;
	for(long long  i=0; i<n; i++){
		vector<long long > u;
		g.push_back(u);
	}
	
	for(long long  i=0; i<(n-1); i++){
		long long  x, y;
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
	cin >> k >> x;
	lessCols = k-1;
	moreCols = m-k;
	
	solve(0, -1);
	long long  tot = 0;
	for(long long  i=0; i<=x; i++){
		tot+=a[0][0][i];
		tot+=a[0][1][i];
		tot+=a[0][2][i];
		tot%=mod;
	}
	cout << tot << endl;
}