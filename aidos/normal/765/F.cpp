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
int a[100100];
vector<pii> qu[100100];
int m;
int ans[300300];
int t[500400];

int get(int pos){
	int res = inf;
	while(pos >= 0){
		res = min(t[pos], res);
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}
void upd(int pos, int val){
	while(pos < n){
		t[pos] = min(val, t[pos]);
		pos |= (pos + 1);
	}
}

vector<int> g[100100];
vector<int> gg[100100];
int b[100100];
int ind[100100];
int val[100100];
int tt[500500];
int get2(int v, int tl, int tr, int l, int r){
	if(tl > r || tr < l) return -inf;
	if(l <= tl && tr <= r) return tt[v];
	int mid = (tl + tr)>>1;
	return max(get2(v * 2,tl, mid, l, r), get2(v *2 +1, mid + 1, tr, l, r));
}
void upd2(int v, int l, int r, int pos, int val){
	if(l == r){
		tt[v] = max(val, tt[v]);
	}
	else{
		int mid = (l + r)>>1;
		if(pos <= mid) upd2(v * 2, l, mid, pos, val);
		else upd2(v * 2 + 1, mid + 1, r, pos, val);
		tt[v] = max(tt[v * 2], tt[v * 2 + 1]);
	}
}
int ppos[100100];
void build(){

	for(int i = 0; i < n; i++){
		b[i + 1] = a[i];
		ind[i] = i-1;
		val[i] = inf + 1;
	}
	b[0] = -1;
	sort(b, b + n + 1);
	int k = unique(b, b + n + 1) - b;
	for(int i = 0; i < n; i++){
		ppos[i] = lower_bound(b, b +k, a[i]) - b;
	}
	for(int it = 0; it < 28; it++){
		for(int i = 0; i < n; i++){
			gg[i].clear();
			if(ind[i] >= 0) gg[ind[i]].pb(i);
		}
		for(int i = 0; i < 4 * k + 100; i++)
			tt[i] = -1;
		for(int i = 0; i < n; i++){
			upd2(1, 0, k-1, ppos[i], i);
			for(int j = 0; j < gg[i].size(); j++){
				int cur = gg[i][j];
				int l = ppos[cur];
				int r = upper_bound(b+ppos[cur], b + k, val[cur]) - b - 1;
				if(l > r) {
					ind[cur] = -1;
					continue;
				}
				int pos = get2(1, 0, k-1,l, r);
				if(pos == -1) {
					ind[cur] = -1;
				}
				else {
					int el = (a[pos] - a[cur]);
					g[cur].pb(pos);
					val[cur] = (el + 1)/2 - 1 + a[cur];
					ind[cur]=pos-1;
				}
			}
		}
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= 4 * n + 10; i++)
		t[i] = inf;
	scanf("%d", &m);
	for(int i = 0, l, r; i < m; i++){
		scanf("%d%d", &l, &r);
		qu[r-1].pb(mp(l-1, i));
	}
	build();
	for(int i = 0; i < n; i++)
		a[i] = 1000 * 1000 * 1000 - a[i];
	build();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			int ind = g[i][j];
			upd(n-1-ind, abs(a[i] - a[ind]));
		}
		for(int j = 0; j < qu[i].size(); j++){
			ans[qu[i][j].s] = get(n-1-qu[i][j].f);
		}
	}
	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
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