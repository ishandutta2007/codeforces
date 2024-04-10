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
char c[1000100];
int n;
vector<int> g[2000100];
int used[2000100];
string txts[1000100];
int mx = 0;
vector<int> lev[2000100];
void dfs(int v, int len){
	lev[len].pb(v);
	mx = max(len, mx);
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(used[to]) continue;
		dfs(to, len + 1);
	}
}
void solve(){
	scanf("%s", c);
	n = strlen(c);
	int sz= 0;
	vector<pii> vv;
	int txt = 1;
	for(int i = 0; i < n; ){
		if(c[i] == ','){
			i++;
			txt ^= 1;
			continue;
		}
		if(txt){
			while(c[i] != ','){
				txts[sz]+=c[i];
				i++;
			}
			if(vv.size() > 0){
				g[vv.back().s].pb(sz);
				vv.back().f--;
				if(vv.back().f == 0) vv.pop_back();
			}
			sz++;
		}
		else{
			int num = 0;
			while(c[i] != ','){
				num = num * 10 + c[i] - '0';
				i++;
			}
			if(num!= 0)vv.pb(mp(num,sz-1));
		}
	}
	for(int i = 0; i < sz; i++){
		if(used[i]) continue;
		dfs(i, 0);
	}
	printf("%d\n", mx+1);
	for(int i = 0; i <= mx; i++){
		for(int j = 0; j < lev[i].size(); j++){
			if(j) printf(" ");
			int to = lev[i][j];
			printf("%s", txts[to].c_str());
		}
		printf("\n");
	}
		

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