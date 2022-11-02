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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

vector < int > v1, v2;
vector < pair < pii, pii > > v3[200100], v6[200100];

vector < int > v4[200100], v5[200100];
int t[1000000];
int x[200100];
int y[200100];
int a[200100];



void update(int v, int l, int r, int pos, int x){
	if(l == r) {
		t[v] = x;
		return;
	}
	int mid = ( l + r ) >> 1;
	if(mid >= pos) update(v* 2, l, mid, pos, x);
	else update(v* 2+1, mid+1, r, pos, x);
	t[v] = min(t[v*2], t[v*2+1]);

}

int get(int v, int l, int r, int tl, int tr){
	if(tl > tr) return 1000000;
	if( l== tl && tr == r) return t[v];
	int mid = (l+r)/2;
	return min(get(v*2, l, mid, tl, min(tr, mid)), get(v * 2 + 1, mid+1, r, max(mid+1, tl), tr));
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, m, k,q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++){
    	scanf("%d %d\n", &x[i], &y[i]);
    	v1.pb(x[i]);
    	v2.pb(y[i]);
    	v4[x[i]].pb(y[i]);

    	v5[y[i]].pb(x[i]);
    }
    sort(all(v1));
    sort(all(v2));
    v1.resize(unique(all(v1)) - v1.begin());

    v2.resize(unique(all(v2)) - v2.begin());

    for(int i = 1, x1, x2, y1, y2; i <= q; i++){
    	scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
    	if(x1 > x2) swap(x2, x1);
    	if(y1 > y2) swap(y2, y1);
		v3[x2].pb(mp(mp(x1, i), mp(y1, y2)));

		v6[y2].pb(mp(mp(y1, i), mp(x1, x2)));
	}
    	
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < v4[i].size(); j++){
    		update(1, 0, m, v4[i][j], i);
    	}
    	for(int j = 0; j < v3[i].size(); j++){
    		int y1 = v3[i][j].s.f;
    		int y2 = v3[i][j].s.s;
    		int id = v3[i][j].f.s;
    		int xx = v3[i][j].f.f;
    		if(get(1, 0, m, y1, y2) >= xx) a[id] = 1;
    	}
    }
    memset(t, 0,sizeof t);
    for(int i = 1; i <= m; i++){
    	for(int j = 0; j < v5[i].size(); j++){
    		update(1, 0, n, v5[i][j], i);
    	}
    	for(int j = 0; j < v6[i].size(); j++){
    		int y1 = v6[i][j].s.f;
    		int y2 = v6[i][j].s.s;
    		int id = v6[i][j].f.s;
    		int xx = v6[i][j].f.f;
    		
    		if(get(1, 0, n, y1, y2) >= xx) a[id] = 1;
    	}
    }
    	
    for(int i = 1; i <= q; i++){
    	if(a[i]) printf("YES\n");
    	else printf("NO\n");
    }





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}