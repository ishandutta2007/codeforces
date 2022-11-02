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
int t[4*500500];
int a[500500];
int n, q;
int getL(int v, int l, int r, int tl, int tr, int x){
	if(tr < l || r < tl) return r + 1;
	if(t[v] % x == 0) return r + 1;
	if(l == r){
		return r;
	}
	int mid = (l + r)>>1;
	int res = getL(v * 2, l, mid, tl, tr, x);
	if(res == mid+1) return getL(v*2+1, mid+1, r, tl, tr, x);
	return res;
}
int getR(int v, int l, int r, int tl, int tr, int x){
	if(tr < l || r < tl) return l-1;
	if(t[v] % x == 0) return l - 1;
	if(l == r){
		return l;
	}
	int mid = (l + r)>>1;
	int res = getR(v * 2+1, mid+1,  r, tl, tr, x);
	if(res == mid) return getR(v*2, l, mid, tl, tr, x);
	return res;
}
void upd(int v, int l, int r, int p, int x){
	if(l == r){
		t[v] = x;
	}
	else{
		int mid = (l + r)>>1;
		if(p <= mid) upd(v * 2, l, mid, p, x);
		else upd(v*2+1, mid+1, r, p, x);
		t[v] = __gcd(t[v*2], t[v*2+1]);
	}
}
void build(int v, int l, int r){
	if(l == r){
		t[v] = a[l];
	}else{
		int mid = (l + r)>>1;
		build(v * 2, l, mid);
		build(v * 2+1, mid+1, r);
		t[v] = __gcd(t[v*2], t[v*2+1]);
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	build(1, 0, n-1);
	scanf("%d", &q);
	for(int i = 0, t, l, r, x; i < q; i++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d%d", &l, &r, &x);
			l--;
			r--;
			if(getL(1, 0, n-1, l, r, x) >= getR(1, 0, n-1, l, r, x)) {
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			scanf("%d%d", &l, &x);
			--l;
			upd(1, 0, n-1, l, x);
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