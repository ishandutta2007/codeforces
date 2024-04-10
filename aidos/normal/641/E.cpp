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

vector < int > g[4000100];
vector < int > dp[4000100];

vector < int > cnt[4000100];
vector <int> li;
int a[1000100],tt[1000100],x[1000100];
int n, m;


void merge_first(vector < int > &v, vector < int > &u, vector < int > &c){
	int l = 0, r = 0;
	while(l < v.size() && r < u.size()){
		if(v[l] == u[r]){
			c.pb(v[l]);
			l++;
			r++;
		}
		else if(v[l] < u[r]){
			c.pb(v[l]);
			l++;
		}
		else{
			c.pb(u[r]);
			r++;
		}
	}
	while(l < v.size()) {
		c.pb(v[l]);
		l++;
	}
	while(r < u.size()) {
		c.pb(u[r]);
		r++;
	}
}
void build(int id, int v, int l, int r){
	while(v >= cnt[id].size()) cnt[id].pb(0);
	if(l == r){
		return;
	}
	int mid = (l + r) >> 1;
	build(id, v * 2,l, mid);
	build(id, v * 2 + 1, mid + 1, r);

}

void add(int id, int v, int tl, int tr, int pp){
	
	cnt[id][v]++;
	if(tl== tr){
		return;
	}
	int mid = (tl + tr) >>1;
	if(mid >= pp){
		add(id, v*2,tl, mid, pp);
	}
	else {
		add(id, v*2+1, mid+1,tr, pp);
	}
}
void del(int id, int v, int tl, int tr, int pp){
	int mid = (tl + tr) >> 1;
	cnt[id][v]--;
	if(tl== tr){
		return;
	}
	if(mid >= pp){
		del(id, v*2,tl, mid, pp);
	}
	else {
		del(id, v*2+1, mid+1,tr, pp);
	}
}
int find_cnt(int id, int v, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(tl==l && tr == r){
		return cnt[id][v];
	}
	int mid = (tl + tr) >>1;
	return find_cnt(id, v * 2, tl, mid, l, min(r, mid)) + find_cnt(id, v * 2+1,mid+1, tr, max(l, mid+1),r);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &m);
    for(int i=0; i < m; i++){
    	scanf("%d %d %d", &a[i], &tt[i], &x[i]);
    	li.pb(x[i]);
    }
    sort(all(li));
    li.resize(unique(all(li))-li.begin());
    n = li.size();
    
    for(int i = 0; i < m; i++){
    	int pos = lower_bound(all(li), x[i]) - li.begin();
		g[pos].pb(tt[i]);
    }
    for(int i = 0; i<li.size(); i++){
    	sort(all(g[i]));
    	g[i].resize(unique(all(g[i]))-g[i].begin());
    	build(i, 1,0, ((int) g[i].size())-1);
    }
    
    for(int i = 0; i < m; i++){
    	int pos = lower_bound(all(li), x[i]) - li.begin();
    	if(a[i] == 1){

    		int pp = lower_bound(all(g[pos]), tt[i]) - g[pos].begin();
    		add(pos, 1, 0, ((int) g[pos].size())-1, pp);
    	}else if(a[i] == 2){

    		int pp = lower_bound(all(g[pos]), tt[i]) - g[pos].begin();
    		del(pos, 1, 0, ((int) g[pos].size())-1, pp);
    	}
    	else {
    		int pp = lower_bound(all(g[pos]), tt[i]) - g[pos].begin();
    		printf("%d\n", find_cnt(pos, 1, 0, ((int) g[pos].size())-1, 0, pp));
    	}
    }


    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}