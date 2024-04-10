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
int a[200200];
int p[200200];
int mx[200200];
int n;
pii t[4 * 200200];
void build(int v, int l, int r){
	if(l == r) {
		t[v] = mp(a[l], l);
	}
	else {
		int mid = (l + r)>>1;
		build(v * 2, l, mid);
		build(v * 2 + 1, mid+1, r);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}
pii get(int v, int tl, int tr, int l, int r){
	if(l > tr || tl > r) return mp(0, 0);
	if(l <= tl && tr <= r) return t[v];
	int mid  = (tl + tr)>>1;
	return max(get(v*2, tl, mid, l, r), get(v*2+1, mid+1, tr, l, r));
}
int ans = 0;
void rec(int l, int r) {
	if(r-l <= 1) return;
	pii D = get(1, 0, n-1, l, r);
	int val = D.f, pos = D.s;
	rec(l, pos-1);
	rec(pos + 1, r);
	if(pos - l < r - pos) {
		for(int i = l; i < pos; i++){
			if(p[val-a[i]] > pos && p[val-a[i]] <= r) ans++;
		}
	} else {
		for(int i = pos+1; i <= r; i++){
			if(p[val-a[i]] >= l && p[val-a[i]] <= pos) ans++;
		}
	}
}
void solve(){
	scanf("%d", &n);
	for(int i=0; i< n; i++) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	build(1, 0, n-1);
	rec(0, n-1);
	cout << ans << "\n";
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