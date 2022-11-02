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

pair<pll, pair<ll, int> > t[400400];
int a[100100];
pair<pll, pair<ll, int> > merge(pair<pll, pair<ll, int> > a, pair<pll, pair<ll, int> > b){
	if(a.s.s){
		if(b.s.s){
			a.f.s += b.f.s;
			a.f.f += b.f.f;
			a.s.f = max(a.s.f, a.f.s);
			return a;
		}
		b.f.f += a.f.f;
		b.s.f = max(b.s.f, b.f.f);
		return b;
	}
	else if(b.s.s){
		a.f.s += b.f.s;
		a.s.f = max(a.s.f, a.f.s);
		return a;
	}
	a.s.f = max(a.s.f, b.s.f);
	a.s.f = max(a.s.f, a.f.s + b.f.f);
	a.f.s = b.f.s;
	return a;
} 

void build(int v, int l, int r){
	if(l == r){
		t[v] = mp(mp(a[l], a[l]), mp(a[l], 1));
		return;
	}
	int mid = (l + r)>>1;
	build(v * 2, l,mid);
	build(v * 2 + 1, mid+1, r);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos){
	if(l == r){
		t[v] = mp(mp(0, 0), mp(0, 0));
		return;
	}
	int mid = (l + r)>>1;
	if(pos<=mid) upd(v * 2, l, mid, pos);
	else upd(v * 2 + 1, mid+1, r, pos);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}
int n;
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build(1, 0, n-1);
	for(int i = 0, x; i < n; i++){
		scanf("%d",&x);
		x--;
		upd(1, 0, n-1, x);
		printf("%I64d\n", t[1].s.f);
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