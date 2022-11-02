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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (4e5 + 20)
using namespace std;
int n, m;
vector < int > g[MAXN];
bool used[MAXN];
map < pii, int > mapPii;
ll sum = 0;
ll cnt = 0;
ll t[5*MAXN];
int a[MAXN];
void go(int x){
	used[x] = 1;
	for(int i = 0; i < g[x].size(); i++){
		int to = g[x][i];
		if(!used[to]){
			if(a[x] + a[to] - mapPii[mp(x, to)] >= m) sum++;
			if( a[x] + a[to] >= m ) cnt++;
		}
	}
}
void update(int l, int v = 1, int tl = 0, int tr = n){
	if(tl == l && tr == l){
		t[v]++;
	}
	else {
		int mid = (tl + tr) >> 1;
		if(mid >= l) update(l, 2*v, tl, mid);
		else update(l, 2*v + 1, mid+1, tr);
		t[v] = t[2*v] + t[2*v + 1];
	}
}
ll get(int l, int r, int v = 1, int tl = 0, int tr = n){
	if(l > r) return 0;
	if(tl == l && tr == r){
		return t[v];
	}
	else {
		int mid= (tl+tr) >> 1;
		return get(l, min(r, mid), 2*v, tl, mid) + get(max(l, mid+1), r, 2*v + 1, mid+1, tr);
	}
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
    	int x, y;
    	scanf("%d%d", &x, &y);
    	a[x]++;
    	a[y]++;
    	if(mapPii.count(mp(x,y)) == 0){
    		g[x].pb(y);
    		g[y].pb(x);
    	}
    	mapPii[mp(x, y)]++;
		mapPii[mp(y, x)]++;
    }
    for(int i = 1; i <= n; i++){
    	go(i);
    	sum += get(max((m - a[i]), 0), n);
    	update(a[i]);
    }
    cout << sum - cnt << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}