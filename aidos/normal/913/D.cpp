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
vector<int> g[200100];
int a[200100];
int t[200200];
int n, T;
int ans = 0;
int ind = 0;
void solve(){
	scanf("%d%d", &n, &T);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i], &t[i]);
		g[a[i]].pb(i);
	}
	int G = 0;
	set<pii> S;
	for(int i = n; i > 0; i--){
		for(int j = 0; j < g[i].size(); j++){
			S.insert(mp(-t[g[i][j]], g[i][j]));
			G += t[g[i][j]];
		}
		while(S.size() > i || G > T){
			G += S.begin()->f;
			S.erase(S.begin());
		}
		if(ans < S.size()){
			ans = S.size();
			ind = i;
		}
	}
	printf("%d\n", ans);
	if(ans == 0){
		printf("0\n");
		return;
	}
	S.clear();
	G = 0;
	for(int i = n; i > 0; i--){
		for(int j = 0; j < g[i].size(); j++){
			S.insert(mp(-t[g[i][j]], g[i][j]));
			G += t[g[i][j]];
		}
		while(S.size() > i || G > T){
			G += S.begin()->f;
			S.erase(S.begin());
		}
		if(i == ind){
			int ok = 0;
			printf("%d\n", (int) S.size());
			forit(it, S){
				if(ok) printf(" ");
				printf("%d", it->s);
				ok = 1;
			}
			printf("\n");
			return;
		}
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