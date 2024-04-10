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
string s;
int n, p, m;
int sgn = 1;
pii dp[10100][111];
int L[10100];
int sz[10100];
vector<int> g[100100];
void dfs(int v){
	if(g[v].size()){
		sz[v] = 1;
	}
	else {
		sz[v] = 0;
		dp[v][0] = mp(L[v], L[v]);
		return;
	}
	for(int i = 0; i <g[v].size(); i++){
		int to = g[v][i];
		dfs(to);
		sz[v] += sz[to];
	}
	int t1 = min(p, sz[g[v][0]]);
	for(int i = 0; i <= p+1; i++){
		dp[v][i].f = -inf;
		dp[v][i].s = inf;
	}
	int U = g[v][0];
	int V = g[v][1];
	for(int i = 0; i <= t1; i++){
		int t2 = min(p - i, sz[g[v][1]]);
		for(int j = 0; j <= t2; j++){
			dp[v][i + j].f = max(dp[v][i + j].f, dp[U][i].f - sgn * dp[V][j].f);
			dp[v][i + j].f = max(dp[v][i + j].f, dp[U][i].f - sgn * dp[V][j].s);
			dp[v][i + j].f = max(dp[v][i + j].f, dp[U][i].s - sgn * dp[V][j].f);
			dp[v][i + j].f = max(dp[v][i + j].f, dp[U][i].s - sgn * dp[V][j].s);

			dp[v][i + j].s = min(dp[v][i + j].s, dp[U][i].f - sgn * dp[V][j].f);
			dp[v][i + j].s = min(dp[v][i + j].s, dp[U][i].f - sgn * dp[V][j].s);
			dp[v][i + j].s = min(dp[v][i + j].s, dp[U][i].s - sgn * dp[V][j].f);
			dp[v][i + j].s = min(dp[v][i + j].s, dp[U][i].s - sgn * dp[V][j].s);


			dp[v][i + j + 1].f = max(dp[v][i + j + 1].f, dp[U][i].f + sgn * dp[V][j].f);
			dp[v][i + j + 1].f = max(dp[v][i + j + 1].f, dp[U][i].f + sgn * dp[V][j].s);
			dp[v][i + j + 1].f = max(dp[v][i + j + 1].f, dp[U][i].s + sgn * dp[V][j].f);
			dp[v][i + j + 1].f = max(dp[v][i + j + 1].f, dp[U][i].s + sgn * dp[V][j].s);

			dp[v][i + j + 1].s = min(dp[v][i + j+1].s, dp[U][i].f + sgn * dp[V][j].f);
			dp[v][i + j + 1].s = min(dp[v][i + j+1].s, dp[U][i].f + sgn * dp[V][j].s);
			dp[v][i + j + 1].s = min(dp[v][i + j+1].s, dp[U][i].s + sgn * dp[V][j].f);
			dp[v][i + j + 1].s = min(dp[v][i + j+1].s, dp[U][i].s + sgn * dp[V][j].s);
                                                                                        
		}
	}
}

void solve(){
	cin >> s;
	cin >> p >> m;
	if(p > m) {
		swap(p, m);
		sgn *= -1;
	}
	vector<int> st;
	vector<char> G;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ')'){
			int x = st.back();
			st.pop_back();
			int y = st.back();
			st.pop_back();
			int id = n;
			n++;
			st.pb(id);
			g[id].pb(y);
			g[id].pb(x);
		}
		else if(s[i] >= '0' && s[i] <= '9'){
			int id=  n;
			n++;
			st.pb(id);
			L[id] = s[i] - '0';
		}
	}

	dfs(st.back());
	for(int i = 0; i <= p; i++){
		//cout << dp[st.back()][i].s << endl;
	}
	printf("%d\n", dp[st.back()][p].f);
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