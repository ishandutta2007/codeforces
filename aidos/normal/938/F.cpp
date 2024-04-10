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
bool used[5050][5050];
string s;
int n;
vector<pii> g[5050];
void solve(){
	cin >> s;
	n = s.size();
	if(n==1){cout<<s;return;}
	int k = 0;
	int mask = 0;
	int lev = 0;
	for(int i = 0; k + (1<<i) < n; i++){
		k += (1<<i);
		mask |= (1<<i);
		lev = i;
	}
	k = n-k;
	g[0].pb(mp(0, 0));
	used[0][0] = 1;
	string t ="";
	for(int j = 0; j < k; j++){
		char sym = 'z';
		for(int t=0; t < g[j].size(); t++){
			int pos = g[j][t].f;
			int m = g[j][t].s;
			for(int x= 0; x <= lev; x++){
				if(!(m&(1<<x)) && !used[pos+(1<<x)][m|(1<<x)]){
					used[pos+(1<<x)][m|(1<<x)] = 1;
					g[j].pb(mp(pos + (1<<x), m|(1<<x)));
				}
			}
			sym = min(sym, s[pos]);
		}
		for(int t=0; t < g[j].size(); t++){
			int pos = g[j][t].f;
			int m = g[j][t].s;
			if(s[pos] != sym) continue;
			used[pos+1][m] = 1;
			g[j+1].pb(mp(pos+1, m));
		}
		t += sym;
	}
	cout << t << "\n";
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