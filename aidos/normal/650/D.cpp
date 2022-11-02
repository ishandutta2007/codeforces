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


vector < int > li;
int n, m;
vector < int > g[800400];
int q[800400];
int ans[800400];
bool ok[800400];
int t[800400];
int dp1[800400];
int dp2[800400];
int cnt[800400];

int get(int pos){
	int res = 0;
	while(pos >= 0){
		res = max(t[pos], res);
		pos = (pos & (pos+1) ) - 1;
	}
	return res;
}
int lim = 800100;
void upd(int pos, int v){
	while(pos < lim){
		t[pos] = max(t[pos], v);
		pos |= pos+1;
	}
}
void clr(){
	for(int i = 0; i < lim; i++)
		t[i] = 0;
}
int mxans = 0;
int pref[800400];
void find_mx(vector < int > &a){
	clr();
	vector < int > li, c;
	for(int i = 0; i < a.size(); i++)
		li.pb(a[i]);
	sort(all(li));
	li.resize(unique(all(li)) - li.begin());
	for(int i = 0; i < a.size(); i++){
		c.pb(lower_bound(all(li), a[i]) - li.begin());
	}
	for(int i = 0; i < c.size(); i++){
		int g = get(c[i]-1);
		dp1[i] = g + 1;
		upd(c[i], g + 1);
	}
	
	clr();
	int mx = 0;
	for(int i = (int) c.size() - 1; i >= 0; i--){
		int g = get((int)c.size() - c[i]-2);
		dp2[i] = g;
		upd((int)c.size() - c[i]-1, g+1);
		mx = max(mx, dp1[i] + dp2[i]);
	}
	for(int i = 0; i < c.size(); i++){
		if(dp1[i] + dp2[i] < mx) continue;
		cnt[dp1[i]]++;
	}
	mxans = mx;
	for(int i = 0; i < c.size(); i++){
		if(dp1[i] + dp2[i] < mx || cnt[dp1[i]] > 1) ok[i] = 1;
	}
	
}


void calc(vector < int > &a){
	clr();
	vector < int > li;
	for(int i = 0; i < a.size(); i++)
		li.pb(a[i]);
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < g[i].size(); j++){
			li.pb(q[g[i][j]]);
		}
	}
	sort(all(li));

	li.resize(unique(all(li)) - li.begin());


	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < g[i].size(); j++){
			int pos = lower_bound(all(li), q[g[i][j]]) - li.begin();
			pref[g[i][j]] = get(pos-1) + 1;
		}
		int pos = lower_bound(all(li), a[i]) - li.begin();
		int val = get(pos-1) + 1;
		upd(pos, val);
	}
	for(int i = 0; i < li.size(); i++)
		li[i] *= -1;
	reverse(all(li));
	/*for(int i = 0; i < m; i++){
		cout <<pref[i] << " ";
	}
	cout << endl;*/
	clr();
	for(int i = (int) a.size() - 1; i >= 0; i--){
		for(int j = 0; j < g[i].size(); j++){
			int pos = lower_bound(all(li), -q[g[i][j]]) - li.begin();
			pref[g[i][j]] += get(pos-1);
		}
		int pos = lower_bound(all(li), -a[i]) - li.begin();
		int val = get(pos-1) + 1;
		upd(pos, val);
	}

	/*for(int i = 0; i < m; i++){
		cout <<pref[i] << " ";
	}
	cout << endl;*/
	for(int i = 0; i < m; i++)
		ans[i] = max(ans[i], pref[i]);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0, x; i < n; i++){
    	scanf("%d", &x);
    	li.pb(x);
    }
    find_mx(li);
    vector < int > gg;
    for(int i = 0, ind; i < m; i++){
    	scanf("%d %d", &ind, &q[i]);
    	g[ind-1].pb(i);
    	if(ok[ind-1]) ans[i] = mxans;
    	else ans[i] = mxans-1;
    }
    calc(li);
    for(int i = 0; i < m; i++){
    	printf("%d\n", ans[i]);
    }

    
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}