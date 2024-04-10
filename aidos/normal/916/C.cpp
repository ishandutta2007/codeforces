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
int n, m;
int prime(int x){
	for(int i = 2; i * i<=x; i++)
		if(x % i == 0) return 0;
	return x > 1;
}
void solve(){
	cin >> n >> m;
	int k = n;
	while(!prime(k)) k++;
	vector< pair<pii, int> > ans;
	int cur = k;
	for(int i = 2; i < n; i++){
		ans.pb(mp(mp(i-1, i), 1));
		k--;
	}
	ans.pb(mp(mp(n-1, n), k));
	for(int i = 1; i <= n && ans.size() < m; i++){
		for(int j = i + 2; j <= n && ans.size() < m; j++){
			ans.pb(mp(mp(i, j), 1e9));
		}
	}
	printf("%d %d\n", cur, cur);
	for(int i = 0; i < ans.size(); i++){
		printf("%d %d %d\n", ans[i].f.f, ans[i].f.s, ans[i].s);
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