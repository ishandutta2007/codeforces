#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef tree< pair<int, int>,null_type,less< pair<int, int> >,rb_tree_tag,tree_order_statistics_node_update> order_set;

order_set t[100100];

int xx, yy, zz;
int n, m, k;
pair< int, pii > x[100100];
string ans[100100];
int cnt[100100];
vector< pair< pii, pii > > g[100100];
vector< pii > gr[100100];

void add_qu(int x, int y, int z, int i, int sgn){
	if(x == 0 || y == 0 || z == 0) return;
	g[x].pb(mp(mp(y, z), mp(i, sgn)));
}

bool inside(int x, int l, int r){
	return x >= l && x <= r;
}

int sz = 0;

void add(int y, int z){
	sz++;
	while(y <= yy){
		t[y].insert(mp(z, sz));
		y|=y+1;
	}
}

int get(int y, int z){
	int res = 0;
	sz++;
	while(y >= 0){
		res += t[y].order_of_key(mp(z, sz));
		y = (y&(y+1)) - 1;
	}
	return res;
}
void solve(){
	cin >> xx >> yy >> zz;
	cin >> n >> m >> k;
	int minx = xx;
	int maxx = 1;
	int miny = yy;
	int maxy = 1;
	int minz = zz;
	int maxz = 1;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		maxx = max(a, maxx);
		minx = min(a, minx);
		maxy = max(b, maxy);
		miny = min(b, miny);
		maxz = max(c, maxz);
		minz = min(c, minz);
	}
	for(int i = 0; i < m; i++){
		cin >> x[i].f >> x[i].s.f >> x[i].s.s;
		if(inside(x[i].f, minx, maxx) && inside(x[i].s.f, miny, maxy) && inside(x[i].s.s, minz, maxz)){
			cout << "INCORRECT\n";
			return;
		}
	}
	sort(x, x + m);
	for(int i = 0; i < m; i++){
		gr[x[i].f].pb(x[i].s);
	}
	for(int i = 0; i < k; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(inside(a, minx, maxx) && inside(b, miny, maxy) && inside(c, minz, maxz)){
			ans[i] = "OPEN";
			continue;
		}
		int x[3][2] = {{min(minx, a) - 1, max(maxx, a)}, {min(miny, b) - 1, max(maxy, b)}, {min(minz, c) - 1, max(maxz, c)}};
		for(int mask = 0; mask < 8; mask++){
			int aa[3] = {0, 0, 0};
			int sgn = -1;
			for(int j = 0; j < 3; j++){
				if(mask & (1<<j)){
					aa[j] = x[j][1];
					sgn *= -1;
				}else aa[j] = x[j][0];
			}
			add_qu(aa[0], aa[1], aa[2], i, sgn);
		}
	}
	for(int i = 1; i <= xx; i++){
		for(int j = 0; j < gr[i].size(); j++){
			add(gr[i][j].f, gr[i][j].s);
		}
		for(int j = 0; j < g[i].size(); j++){
			int x = g[i][j].f.f;
			int y = g[i][j].f.s;
			int ind = g[i][j].s.f;
			int sgn = g[i][j].s.s;
			cnt[ind] += sgn * get(x, y);
		}
	}
	
	cout << "CORRECT\n";
	for(int i = 0; i < k; i++){
		if(ans[i] == "OPEN"){
			cout << ans[i] <<"\n";
			continue;
		}
		if(cnt[i] > 0){
			cout << "CLOSED\n";
		}else {
			cout << "UNKNOWN\n";
		}	
	}
	
}

int main () {
		ios_base::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}