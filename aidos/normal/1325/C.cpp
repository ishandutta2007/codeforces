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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
vector< pair<int, int> > g[maxn];
int n;
int col[maxn];


void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(mp(i, x));
		g[y].pb(mp(i, y));
		col[i] = -1;
	}
	int v = 1;
	while(v <= n && g[v].size() < 3) v++;
	if(v == n+1) {
		for(int i = 0; i < n-1; i++) {
			printf("%d\n", i);
		}
		return;
	}
	int st = 0;
	for(auto x: g[v]) {
		col[x.f] = st;
		st++;
	}
	for(int i = 1; i <= n; i++) {
		for(auto x: g[i]) {
			if(col[x.f] == -1) {
				col[x.f] = st;
				st++;
			}
		}
	}
	for(int i = 0; i < n-1; i++) {
		printf("%d\n", col[i]);
	}
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