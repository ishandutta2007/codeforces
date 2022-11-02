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
#include <bitset>

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
vector<pii> q[1000100];
vector<int> dq[1000100];
ll ans[1000100];
ll t[1000100];
ll a[1000100];
int n, m;

void modify(int v, int l, int r, int p, int val){
	if(l == r) {
		t[v] = val;
	}else{
		int mid = (l + r)>>1;
		if(p <= mid) modify(v * 2, l, mid, p, val);
		else modify(v * 2 + 1, mid+1, r, p, val);
		t[v] = t[v * 2] + t[v*2+1];
	}
}
int get(int v, int tl ,int tr, int l, int r) {
	if(tl > r || l > tr) return 0;
	if(l <= tl &&tr <= r) return t[v];
	int mid = (tl+tr)>>1;
	return get(v * 2, tl, mid, l, r) + get(v * 2 + 1, mid+1, tr, l,r);
}

int get(int p) {
	p = n-p-1;
	int res = 0;
	while(p >= 0) {
		res += t[p];
		p = (p&(p+1)) - 1;
	}
	return res;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		if(l>r) swap(l, r);
		q[r].pb(mp(l, i));
	}
	for(int i = 0; i < n; i++) {
		if(a[i] <= n) {
			dq[a[i]].push_back(i);
			if(dq[a[i]].size() == a[i]) {
				modify(1, 0, n-1, dq[a[i]][0], 1);
			}else if(dq[a[i]].size() >= a[i] + 1) {
				modify(1, 0, n-1, dq[a[i]][dq[a[i]].size()-a[i]-1], -1);
				modify(1, 0, n-1, dq[a[i]][dq[a[i]].size()-a[i]], 1);
				if(dq[a[i]].size() >= a[i] + 2) {
					modify(1, 0, n-1, dq[a[i]][dq[a[i]].size()-a[i]-2], 0);
				}
			}
		}
		for(int j = 0; j < q[i].size(); j++) {
			ans[q[i][j].s] = get(1, 0, n-1, q[i][j].f, i);
			
		}
	}
	for(int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
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