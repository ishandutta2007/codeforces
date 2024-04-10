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
pair< int, pii > a[100100];
ll t[1200100];
ll get(int v, int tl, int tr, int l, int r){
	if(tl > r || tr < l) return 0;
	if(tl >= l && tr <= r) return t[v];
	int mid = (tl + tr)>>1;
	return max(get(v*2, tl, mid, l, r), get(v * 2 + 1, mid+1, tr, l, r));
}
void upd (int v, int tl, int tr, int pos, ll val){
	if(tl == tr){
		t[v] = max(val, t[v]);
		return;
	}
	int mid = (tl + tr)>>1;
	if(pos <= mid) upd(v * 2, tl, mid, pos, val);
	else upd(v *2 + 1, mid+1, tr, pos, val);
	t[v] = max(t[v * 2] ,t[v * 2 + 1]);
	
}
void solve(){
	scanf("%d", &n);
	vector<int> lens;
	lens.pb(0);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &a[i].s.f, &a[i].f, &a[i].s.s);
		lens.pb(a[i].f);
		lens.pb(a[i].s.f);
		a[i].f *= -1;
		a[i].s.f *=-1;
	}
	sort(a, a + n);
	sort(all(lens));
	lens.resize(unique(all(lens)) - lens.begin());
	int k = lens.size();
	ll ans = 0;
	for(int i = 0; i < n; i++){
		a[i].f *= -1;
		a[i].s.f *=-1;
		int p = lower_bound(all(lens), a[i].f) - lens.begin();
		ll cur = get(1, 0, k-1, 0, p-1);
		p = lower_bound(all(lens), a[i].s.f) - lens.begin();
		upd(1, 0, k-1, p, cur + a[i].s.s);
	}
	cout << t[1] << endl;
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