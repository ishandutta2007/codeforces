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
int n;
vector<int> g[1000100];

int a[1000100];
int t[1000100];
int sum = 0;
int cur[1000100];
void dfs(int v){
	cur[v] = a[v];
	t[v] = 0;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		dfs(to);

		cur[v] += cur[to];
		if(cur[to] * 3 == sum){
			if(3*(sum - cur[to]) == sum && t[to]){
				cout << t[to] << " "<< to << endl;
				exit(0);
			}
			t[to] = to;
		}
		else if(abs(cur[to]) % 2 == 0 && 3 * (cur[to] / 2 )== sum){
			if(t[to]){
				cout << to << " "<< t[to] << endl;
				exit(0);
			}
		}
		if(t[v] && t[to]){
			cout << t[v] << " "<< t[to] << endl;
			exit(0);
		}
		if(t[to])
			t[v] = t[to];
	}
}
void solve(){
	scanf("%d", &n);
	int root = 0;
	
	for(int i = 1, x; i <= n; i++){
		scanf("%d%d", &x, &a[i]);
		if(x) g[x].pb(i);
		else root = i;
		sum += a[i];
	}
	if(abs(sum) % 3 != 0){
		cout << -1 << endl;
		return;
	}
	dfs(root);
	cout << -1 << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}