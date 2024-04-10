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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int col[300100];
vector<int> g[300300];
queue<int> S[300300];
int cnt[300300];

void norm(){
	for(int j = 0; j <= 3; j++){
		while(S[j].size()) {
			int v=S[j].front();
			if(cnt[v] != j) {
				S[j].pop();
			}else break;
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i = 1; i<=n; i++){
		cnt[i] = g[i].size();
		S[cnt[i]].push(i);
	}
	while(S[3].size() > 0 || S[2].size() > 0) {
		int v;
		if(S[3].size()) {
			v = S[3].front();
		}
		else {
			v = S[2].front();
		}
		col[v] ^= 1;
		cnt[v] = 0;
		for(int i=0; i < g[v].size(); i++){
			int to = g[v][i];
			//S[cnt[to]].erase(to);
			if(col[v] == col[to]) {
				cnt[to]++;
				cnt[v]++;
			}else {
				cnt[to]--;
			}
			S[cnt[to]].push(to);
		}
		S[cnt[v]].push(v);
		norm();
	}
	for(int i = 1; i <= n; i++) printf("%d", col[i]);
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