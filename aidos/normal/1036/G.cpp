#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, m;
vector<int> g[1000100];
vector<int> gr[1000100];
int dp[1000100];
map<int, int> X;
int used[1000100];
int cc=0;
void dfs(int v, int cur){
	used[v] = 1;
	if(g[v].size() == 0){
		if(X.count(v) == 0){
			X[v] = cc++;
		}
		dp[cur] |= (1<<X[v]);
	}
	
	forit(it, g[v]){
		if(!used[*it]) dfs(*it, cur);
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		gr[y].pb(x);
	}
	int sz = 0;
	for(int i = 1; i<=n;i++){
		if(gr[i].size()==0){
			memset(used, 0, sizeof used);
			dfs(i, sz);
			sz++;
		}
	}
	for(int i = 1; i+1 < (1<<sz); i++){
		int sum = 0;
		for(int j =0;j < sz; j++){
			if(i&(1<<j))
				sum |= dp[j];
		}
		if(__builtin_popcount(i) == __builtin_popcount(sum)){
			cout <<"NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}