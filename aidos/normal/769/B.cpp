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
int n;
int a[1111];
int used[1111];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	used[1] = 1;
	vector<pii> ans;
	for(int i = 2; i <= n; i++){
		int k = 0;
		for(int j = 1; j <= n; j++){
			if(used[j] && a[j]>0) {
				if(k == 0 || a[j] > a[k]) k = j;
			}
		}
		if(k == 0) {
			cout << -1 << endl;
			return;
		}
		int t = 0;
		for(int j = 1; j <= n; j++){
			if(used[j]) continue;
			if(t == 0 || a[j] > a[t]) t = j;
		}
		a[k]--;
		used[t] = 1;
		ans.pb(mp(k, t));
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].f << " "<< ans[i].s << endl;
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