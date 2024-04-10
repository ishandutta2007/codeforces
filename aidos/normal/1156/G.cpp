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
const int mod = (int) 1e9 + 7;
using namespace std;
string s;
vector<int> g[100100];
char OP[100100];
map<string, int> id;
map<pair<pii, char>, int> comp_id;
int sz;
int N;
bool op(char c){
	return c == '$' || c == '^'||c == '#'||c == '&' || c == '=';
}
string h[100100];
int was[100100];
int ID[100100];
int get_val(string x){
	if(id.count(x) == 0) {
		id[x] = sz;
		h[sz] = x;
		sz++;
	}
	return id[x];
}
int ind;
vector<string> G, ans;
string gen_string() {
	while(id.count(G[ind])) ind++;
	return G[ind];
}
int dfs(int v, int need=1) {
	if(was[v]) return ID[v];
	if(g[v].size() == 0) {
		return v;
	}
	int x = dfs(g[v][0], 0);
	int y = dfs(g[v][1], 0);
	was[v] = 1;
	if(comp_id.count(mp(mp(x, y), OP[v]))==0) {
		
		string t = need ? "res" : gen_string();
		int u = get_val(t);
		ID[v] = u;
		ans.pb(t+"=" + h[x] + OP[v] + h[y]);
		comp_id[mp(mp(x, y), OP[v])] = u;
	}
	return ID[v] = comp_id[mp(mp(x, y), OP[v])] ;
}
void precalc(string d) {
	if(G.size() > 200200) return;
	if(d.size() == 4) {
		G.pb(d);
		return;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		precalc(d + c);
	}
}


void solve(){
	cin >> N;
	get_val("res");
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		int j = 0;
		vector<string> d;
		while(j < s.size()){
			string x;
			while(j < s.size() && !op(s[j])) {
				x += s[j];
				j++;
			}
			d.pb(x);
			j++;
		}
		if(d.size() == 2) {
			id[d[0]] = get_val(d[1]);
		} else {
			int cur_id = sz;
			sz++;
			OP[cur_id] = s[d[0].size() + d[1].size() + 1];
			int x = get_val(d[1]);
			int y = get_val(d[2]);
			id[d[0]] = cur_id;
			g[cur_id].pb(x);
			g[cur_id].pb(y);
		}
	}
	dfs(id["res"]);
	if(ans.size() == 0 && id["res"] != 0) {
		ans.pb("res=" + h[id["res"]]);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i <ans.size(); i++) cout << ans[i] << "\n";
}

int main () {
	precalc("");
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}
//