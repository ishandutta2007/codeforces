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

int dp[300100];

int n;
vector<int> g[200200];
int a[200200];
int p[200200];
int pos[200200];
void dfs(int v, int pa){
	dp[v] = dp[pa]+1;
	p[v] = pa;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == pa) continue;
		dfs(to, v);
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for(int i = 1; i < n; i++){
		if(dp[a[i]] < dp[a[i-1]]){
			printf("No\n");
			return;
		}
	}
	for(int i = 0; i < n; ){
		int j = i;
		while(i < n && dp[a[j]]==dp[a[i]]) i++;
		set<int> S;
		int last = 0;
		while(j<i){
			int k = j;
			while(j < i && p[a[j]] == p[a[k]]) j++;
			if(S.count(p[a[k]])){
				printf("No\n");
				return;
			}
			if(last != 0){
				if(pos[last] > pos[p[a[k]]]){
					cout << "No\n";
					return;
				}
			}
			S.insert(p[a[k]]);
			last = p[a[k]];
		}
	}
	printf("Yes\n");
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