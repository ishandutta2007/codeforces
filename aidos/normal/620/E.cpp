#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

ll t[2000200];

ll tt[2000200];
void push (int v) {
	if (t[v] != -1) {
		t[v*2] = t[v*2+1] = t[v];
		tt[v*2] = tt[v*2+1] = t[v];
		t[v] = -1;
	}
}
 
void update (int v, int tl, int tr, int l, int r, ll color) {
	if (l > r)
		return;
	if (l == tl && tr == r){
		t[v] = color;
		tt[v] = color;
	}
	else {
		push (v);
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), color);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
		tt[v] = (tt[v * 2]|tt[v * 2+1]);
	}
}
 
ll get (int v, int tl, int tr, int l, int r) {
	if(l > r) return 0ll;
	if (tl == l && tr == r)
		return tt[v];
	push ( v);
	int tm = (tl + tr) / 2;
	return (get(v * 2, tl, tm, l, min(r, tm))|get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int c[500100];
int l[500100];
int r[500100];
vector < int > g[500500];
int timer = 0;
int n;
int m;
void dfs(int v, int p = -1){
	l[v] = timer++;
	for(int x: g[v]){
		if(x != p) dfs(x, v);
	}
	r[v] = timer-1;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 0; i < 2000020; i++)
    	t[i] = -1;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
    	scanf("%d", &c[i]);
    }
    for(int i = 1, x, y; i < n; i++){
    	scanf("%d %d", &x, &y);
    	g[x].pb(y);
    	g[y].pb(x);
    }
    dfs(1);
    for(int i = 0; i < n; i++){
    	update(1, 0, n-1, l[i+1], l[i+1], 1ll << c[i]);
    }
    int ty, a, b;
    for(int i = 0; i < m; i++){
    	scanf("%d %d", &ty, &a);
    	if(ty == 1){
    		scanf("%d", &b);
    		update(1, 0, n-1, l[a], r[a], 1ll<<b);
    	}
    	else {
    		ll cnt = get(1, 0, n-1, l[a], r[a]);
    		int cc = 0;
    		while(cnt > 0) {
    			cc += cnt & 1;
    			cnt >>= 1;
    		}
			printf("%d\n", cc);
    	}
    }
    

    
    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}