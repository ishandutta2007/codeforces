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
char c[1000500];
int n;
int m;
int nxt[1000500][27];
int sz[1000500];
int en[1000500];
int V = 1;
void del(int v, int x){
	
	sz[x]+= sz[v];
	sz[v] = 0;
	en[x] += en[v];
	en[v] = 0;
	for(int i = 0;  i < 26; i++){
		int cc = nxt[v][i];
		if(cc && sz[cc]){
			del(cc, x);
		}
	}
}
void add(int ind){
	int v = 0;
	for(int i = 1; i < m; i++){
		int cur = c[i] - 'a';
		sz[v]++;
		bool ok = 0;
		for(int j = cur+1; j < 26; j++){
			int to = nxt[v][j];
			if(to == 0) continue;
			if(sz[to] > 0) {
				ok = 1;
				del(to, v);
			}
		}
		if(ok){
			for(int j = 0; j < 26; j++){
				int to = nxt[v][j];
				if(to == 0) continue;
				if(sz[to] > 0) {
					del(to, v);
				}
			}
		}
		if(nxt[v][cur] == 0){
			nxt[v][cur] = V;
			V++;
		}
		v = nxt[v][cur];
	}
	sz[v]++;
	en[v]++;
	for(int j = 0; j < 26; j++){
		int to = nxt[v][j];
		if(to == 0) continue;
		if(sz[to] > 0) del(to, v);
	}
}
char tmp[500500];

void dfs(int v, int len){
	tmp[len] = 0;
	for(int i = 0; i < en[v]; i++){
		printf("#");
		for(int j = 0; j < len; j++)
			printf("%c", tmp[j]);
		printf("\n");
	}
	for(int i = 0; i < 26; i++){
		if(nxt[v][i]) {
			tmp[len] = i + 'a';
			dfs(nxt[v][i], len+1);
		}
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", c);
		m = strlen(c);
		add(i);
	}
	dfs(0, 0);
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