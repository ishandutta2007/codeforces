#define _USE_MATH_DEFINES
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
#include <ctime>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

#define FOR(i,n) for(int i = 0 ;i < (n); i++)


int n;
vector<Pii> e[2*100000];
int d[2*100000];

int dfs(int p,int dp){
	int ret = 0;
	d[p] = dp;
	FOR(i,(int)e[p].size()){
		if(d[e[p][i].first] != -INF) continue;
		ret +=( e[p][i].second == -1) ? 0 : 1;
		ret += dfs(e[p][i].first,dp+e[p][i].second);
	}
	return ret;
}

int main()
{
	FOR(i,2*100000) d[i] = -INF;
	d[0] = 0;
	cin >> n;
	FOR(i,n-1){
		int x,y; cin>>x>>y;
		x--; y--;
		e[x].push_back(Pii(y,-1));
		e[y].push_back(Pii(x,1));
	}

	int zero_ans = dfs(0,0);
	int mx = *max_element(d,d+n);

	int ans = zero_ans - mx;
	cout << ans << endl;
	bool b = false;
	FOR(i,n){
		if(mx == d[i]){
			if(b) cout << " ";
			b = true;
			cout << i+1;
		}
	}
	cout << endl;
	return 0;
}