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
pii a[100100];
int p[100100];
int b[100100];
int n;

void Swap(int x, int y){
	swap(b[x], b[y]);
	p[b[x]] = x;
	p[b[y]] = y;
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].f);
		a[i].s = i;
	}
	int ok = 1;
	for(int i = 1; i < n; i++){
		ok &= (a[i].f >= a[i-1].f);
	}
	if(ok){
		printf("0\n");
		return;
	}
	sort(a, a + n);
	int l = -1;
	for(int i = 0; i < n; i++){
		b[a[i].s] = i;
		int o = 1;
		int d = a[i].f;
		while(d > 0){
			if(d % 10 !=4 && d % 10 != 7) o = 0;
			d /= 10;
		}
		if(o) {
			l = i;
		}
	}
	if(l == -1){
		printf("-1\n");
		return;
	}
	vector<pii> ans;
	for(int i = 0; i < n; i++){
		p[b[i]] = i;
	}
	for(int i = 0; i < n; i++){
		if(b[i] != i){
			if(i == l) continue;
			if(p[l] != i){
				ans.pb(mp(p[l], i));
				Swap(p[l], i);
			}
			if(p[i] != p[l]){
				ans.pb(mp(p[l], p[i]));
				Swap(p[l], p[i]);
			}
			
		}
	}
	printf("%d\n", ans.size());
	forit(it, ans){
		printf("%d %d\n", it->f + 1, it->s+1);
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