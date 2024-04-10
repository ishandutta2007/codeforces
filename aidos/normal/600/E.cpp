#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

map < int, int > m[100100];
set < pll > S[100100];
int n;
int c[100100];
int id[100100];
int sz = 1;
vector < int > g[100100];
ll ans[100100];
int mx[100100];
void dfs(int v, int p=0){
	int cur=0;
	for(int x: g[v]){
		if(p == x) continue;
		dfs(x, v);
		if(cur == 0 || m[id[cur]].size() < m[id[x]].size()) cur = x;
	}
	if(cur == 0) id[v] = sz++;
	else {
		id[v] = id[cur];
		mx[v] = mx[cur];
		ans[v] = ans[cur];
	}
	if(m[id[v]][c[v]] + 1> mx[v]){
		mx[v] = m[id[v]][c[v]] + 1;
		ans[v] = c[v];
	}
	else if(m[id[v]][c[v]] + 1== mx[v]){
		ans[v] += c[v];
	}
	m[id[v]][c[v]]++;
	for(int x: g[v]){
		if(x == p || x == cur) continue;
		for(map <int, int> :: iterator it = m[id[x]].begin(); it != m[id[x]].end(); it++){
			int cc = it->f;
			int cnt = it->s;
			
			if(cnt + m[id[v]][cc] > mx[v]){
				mx[v] = cnt + m[id[v]][cc];
				ans[v] = cc;
			}
			else if(cnt + m[id[v]][cc]== mx[v]){
				ans[v] += cc;
			}
			m[id[v]][cc]+=cnt;
		}
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> c[i];
	for(int i = 1, x, y; i < n; i++){
		cin >> x >> y;
		g[x].pb( y );
		g[y].pb( x );
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}