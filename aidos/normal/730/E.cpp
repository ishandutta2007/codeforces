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
int a[111], d[111];
int n;
int b[111];
int p[111];
int cmp(int i, int j){
	if(b[i] == b[j]) return i < j;
	return b[i] > b[j];
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i], &d[i]);
		b[i] = a[i] + d[i];
		p[i] = i;
	}
	sort(p, p + n, cmp);
	vector<int> ord1, ord2;
	for(int i = 0; i < n; i++){
		if(d[p[i]] > 0) {
			ord1.pb(p[i]);
		}else if(d[p[i]] < 0){
			ord2.pb(p[i]);
		}
	}
	reverse(all(ord1));
	for(int i = 0; i < n; i++)
		b[i] = a[i];
	ll ans = 0;

	sort(p, p + n, cmp);
	for(int i = 0; i < ord1.size(); i++){
		int ind = ord1[i];
		b[ind] = a[ind] + d[ind];
		int x=-1;
		for(int j = 0; j < n; j++)
			if(p[j] == ind) x = j;
		sort(p, p + n, cmp);

		for(int j = 0; j < n; j++)
			if(p[j] == ind) ans += abs(x - j);
	}
	for(int i = 0; i < ord2.size(); i++){
		int ind = ord2[i];
		b[ind] = a[ind] + d[ind];
		int x=-1;
		for(int j = 0; j < n; j++)
			if(p[j] == ind) x = j;
		sort(p, p + n, cmp);

		for(int j = 0; j < n; j++)
			if(p[j] == ind) ans += abs(x - j);
	}
	cout << ans << endl;
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