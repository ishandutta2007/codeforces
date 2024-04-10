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

int n, m;
struct segmentTree{
	vector<int> b;
	vector<int> t;
	segmentTree(){
	}
	segmentTree(vector<int> g){
		b = g;
		b.pb(-inf);
		b.pb(inf);
		sort(all(b));
		b.resize(unique(all(b)) - b.begin());
		t.clear();
		for(int i = 0; i < 8 * b.size(); i++) t.pb(0);
	}
	void build(vector<int> g){
		b = g;
		b.pb(-inf);
		b.pb(inf);
		sort(all(b));
		b.resize(unique(all(b)) - b.begin());
		t.clear();
		for(int i = 0; i < 4 * b.size(); i++) t.pb(0);
	}
	int get(int v, int tl, int tr, int l, int r){
		if(tl > r || l > tr) return 0;
		if(l <= tl && tr <= r) return t[v];
		int mid = (tl + tr)>>1;
		return max(get(v * 2, tl, mid, l, r), get(v * 2+1, mid+1, tr, l, r));
	}
	int get(int r){
		return get(1, 0, (int)b.size()-1, 0, r);
	}
	void upd(int v, int l, int r, int pos, int val){
		if(l==r){
			t[v] = max(t[v], val);
		}else{
			int mid = (l + r)/2;
			if(mid >= pos) upd(v * 2, l, mid, pos, val);
			else upd(v * 2 + 1, mid+1, r, pos, val);
			t[v] = max(t[v * 2], t[v*2+1]);
		}
	}
	void upd(int p, int val){
		upd(1, 0, (int)b.size()-1, p, val);
	}
	int findPos(int x){
		return lower_bound(all(b), x) - b.begin();
	}
	int less(int x){
		return lower_bound(all(b), x) - b.begin() - 1;
	}
} t[100100];
vector<int> g[100100];
pair<pii, int> e[100100];
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &e[i].f.f, &e[i].f.s, &e[i].s);
		g[e[i].f.s].pb(e[i].s);
	}
	for(int i = 1; i <= n; i++){
		t[i].build(g[i]);
	}
	
	for(int i = 0; i<m;i++){
		int p1 = t[e[i].f.f].less(e[i].s);
		int V = t[e[i].f.f].get(p1);
		int p2 = t[e[i].f.s].findPos(e[i].s);
		t[e[i].f.s].upd(p2, V+1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int p = t[i].findPos(inf);
		ans = max(ans, t[i].get(p));
	}
	cout << ans << endl;
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