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
int n, m;
void solve(){
	cin >> n >> m;
	int l = 1, r = n;
	vector<pii> ans;
	while(l < r) {
		for(int i = 1; i <= m; i++){
			ans.pb(mp(l, i));
			ans.pb(mp(r, m-i+1));
		}
		l++;
		r--;
	}
	if(l == r) {
		int tl = 1, tr = m;
		for(int i = 1; i <= m; i++){
			if(i & 1) {
				ans.pb(mp(l, tl));
				tl++;
			}
			else {
				ans.pb(mp(l, tr));
				tr--;
			}
		}
	}
	for(int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].f, ans[i].s);
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