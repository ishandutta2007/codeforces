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

const int inf = (1ll << 30) ;
const int maxn = (int) 1e5 + 10;

using namespace std;

int t[8000100];
int a[500100];
int id[2000100];
int ans[500500];
int n,m;
vector < pii > v;

void build(int v, int l, int r){
	t[v] = inf;
	if(l != r) {
		int mid = (l+r) >> 1;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
	}
}

int get(int v, int tl, int tr, int l, int r){
	if(l > r) return inf;
	if(tl == l && tr == r) return t[v];
	int mid = (tl+tr) >> 1;
	return min(get(2 * v, tl, mid, l, min(r, mid)), get(2 * v + 1, mid+1, tr, max(mid+1, l), r));
}

void update(int v, int l, int r, int pos, int x){
	if(l == r){
		t[v] =  x;
	}
	else {
		int mid = (l+r) >> 1;
		if(mid >= pos) update(2 *v, l, mid, pos, x);
		else update(2 * v + 1, mid+1, r, pos, x);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}





int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    map < int, int > tt;
    for(int i = n-1; i>=0; i--){
    	if(tt.count(a[i]) > 0){
    		v.pb(mp(i, i));
    		v.pb(mp(tt[a[i]], i));
    	}
    	tt[a[i]] = i;
    }


    for(int i = 0, l, r; i < m; i++){
    	scanf("%d %d", &l, &r);
    	v.pb(mp(l-1, -i-n));
    	v.pb(mp(r-1, i+n));
    }
    sort(all(v));
    int sz = v.size();
    build(1, 0, sz-1);
    for(int i = 0; i < sz; i++){
    	///cout << v[i].f << " " << v[i].s << endl;
    }
    for(int i = 0; i < sz; ++i){
    	int x = v[i].f;
    	int y = v[i].s;
    	if(y < 0){
    		y = -y;
    		id[y] = i;
    	}
    	else if(y >= n){
    		ans[y - n] = get(1, 0, sz-1, id[y], i);
    		//cout << y << " " <<x << " " << v[id[y]].f << " " <<ans[y-n] << endl;
    	}
    	else if(x == y){
    		id[x] = i;
    	}
    	else {
    		//cout <<"2 " << id[y] << " "<< x-y << endl;
    		update(1, 0, sz-1, id[y], x - y);
    	}
    }
    for(int i = 0; i < m; i++){
    	if(ans[i] == inf) ans[i] = -1;
    	printf("%d\n", ans[i]);
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}