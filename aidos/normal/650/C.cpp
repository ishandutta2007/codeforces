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

int usedx[1000100];
int usedy[1000100];

int cn;
pair < int, pii > x[1000100];
int val[1000100];
int ans[1000100];
int p[1000100];
vector < int > g[1000100];
int n, m;
int get(int v){
	if(p[v] == v) return v;
	return p[v] = get(p[v]);
}
void uni(int v, int u){
	v =get(v);
	u = get(u);
	if( u == v) return;
	p[u] = v;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    int sz = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		scanf("%d",&x[sz].f);
    		x[sz].s = mp(i, j);
    		val[i * m + j] = x[sz].f;
    		sz++;
    	}
    }
    for(int i = 0; i < sz; i++){
    	p[i] = i;
    }
    sort(x, x+sz);
    for(int i = 1; i < sz; i++){
    	if(x[i].f == x[i-1].f && x[i].s.f == x[i-1].s.f){
    		int id1 = x[i].s.f * m + x[i].s.s;
    		int id2 = x[i-1].s.f * m + x[i-1].s.s;
    		uni(id1, id2);
    	}
    }
    for(int i = 0; i < sz; i++){
    	swap(x[i].s.s, x[i].s.f);
    }
    sort(x, x + sz);
    for(int i = 1; i < sz; i++){
    	if(x[i].f == x[i-1].f && x[i].s.f == x[i-1].s.f){
    		int id1 = x[i].s.s * m + x[i].s.f;
    		int id2 = x[i-1].s.s * m + x[i-1].s.f;
    		uni(id1, id2);
    	}
    }
    for(int i = 0; i < sz; i++){
    	swap(x[i].s.s, x[i].s.f);
    }
    for(int i = 0; i < sz; i++){
    	g[get(i)].pb(i);
    }
    vector < pii > li;
    for(int i = 0; i < sz; i++){
    	if(get(i) == i){
    		li.pb(mp(val[i], i));
    	}
    }
    sort(all(li));
    for(int i = 0; i < li.size(); i++){
    	int mx= 0;
    	int dd = li[i].s;
    	for(int j = 0; j < g[dd].size(); j++){
    		int id = g[dd][j];
    		int nn = id/m;
    		int mm = id % m;
    		mx = max(usedx[nn]+1, mx);
    		mx = max(usedy[mm]+1, mx);
    	}
    	for(int j = 0; j < g[dd].size(); j++){
    		int id = g[dd][j];
    		int nn = id/m;
    		int mm = id % m;
    		ans[id] = mx;
    		usedx[nn] = mx;
    		usedy[mm] = mx;
    	}
    }
    for(int i = 0; i < n;i++){
    	for(int j = 0; j < m; j++){
    		printf("%d ", ans[i * m + j]);
    	}
    	printf("\n");
    }
    

    
    
    
    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}