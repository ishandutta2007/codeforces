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
vector<int> g[200200];
vector<int> gg[200200];
int n;
int sz[200200];
void dfs(int v, int pa=0){
	
	sz[v] = 0;
	forit(it, g[v]){
		if(pa != *it) {
			dfs(*it, v);
			sz[v] += sz[*it] + 1;
		}
	}
}
int  dfs2(int v, int pa=0){
	int ok = 0;
	int cur = 0;
	forit(it, g[v]){
		if(*it != pa){
			if(dfs2(*it, v)){
				cur++;
				gg[v].pb(*it);
			}
			else{
				gg[*it].pb(v);
			}
		}
	}
	if(cur % 2 == 0){
		gg[pa].pb(v);
		return 1;
	}
	else return 0;
}
int u[200200];
vector<int> ans;
void dfs3(int v){
	u[v] = 1;
	forit(it, gg[v]){
		if(!u[*it]) dfs3(*it);
	}
	ans.pb(v);
}
void solve(){
	scanf("%d", &n);
	for(int i = 1, x; i <= n; i++){
		scanf("%d", &x);
		if(x != 0){
			g[i].pb(x);
			g[x].pb(i);
		}
	}
	if(n % 2 == 0){
		cout << "NO\n";
		return;
	}
	//cout << "Yes\n";
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(sz[i] % 2 == 0){
			dfs2(i);
			dfs3(i);
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(!u[i]) dfs3(i);
	}
	reverse(all(ans));
	cout << "YES\n";
	forit(it, ans) printf("%d\n", *it);
	
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