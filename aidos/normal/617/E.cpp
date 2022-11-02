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

int n, m, k;
int a[100100];
int c[100100];

ll dbl[350][350];
int l[100100];
int r[100100];
vector < int > qu[100100];
int d[100100];
int id[2000100];        
int cnt[350][100100];
int cnt2[2000100];
int doit[100100];

int kk ;
int bl_s = 300;

ll ans[100100];


void update(int el, int pos){
	int el_id = id[el];
	int cur_id = id[el ^ k];
	if(cur_id == -1) {
		return;
	}
	int bl = pos/bl_s;
	ll cc = 0;
	for(int i = bl; i >= 0; i--){
		cc += cnt[i][cur_id];
		dbl[bl][i] += cc;
	}
	doit[pos] = cnt2[el ^ k];
	cnt2[el]++;
	cnt[bl][el_id]++;
}
ll sum(int l, int r){
	ll ans = 0;
	
	for(int i = l; i <= r; i++){
		ans += cnt2[c[i] ^ k] - doit[i] - (c[i] == (c[i] ^ k));
	}
	return ans;
}
ll get(int l, int r){
	int bl = l/bl_s;
	int br = r/bl_s;
	ll ans = 0;
	if(bl == br){
		ans = sum(l, r);
	}
	else {
		for(int i = br; i >= bl + 1; i--)
			ans += dbl[i][bl + 1];
		ans += sum(l, (bl+1) * bl_s - 1);
	}
	return ans;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <=n; i++)
    	scanf("%d", &a[i]);
	d[0] = 0;
	c[0] = 0;
	for(int i = 1; i <= n; i++){
		c[i] = c[i-1] ^ a[i];
		d[i] = c[i];
	}
	sort(d, d + n + 1);
	kk = unique(d, d + n+1) - d;
	for(int i = 0; i < 2000010; i++)
		id[i] = -1;
	for(int i = 0; i < kk; i++)
		id[d[i]] = i;
	
	
	for(int i = 0; i < m; i++){
		scanf("%d %d", &l[i], &r[i]);
		qu[r[i]].pb(i);
	}
	update(0, 0);
	for(int i = 1; i <= n; i++){
		update(c[i], i);
		for(int j = 0; j < qu[i].size(); j ++){
			int com_id = qu[i][j];
			ans[com_id] = get(l[com_id]-1, r[com_id]);
		}
	}
	for(int i = 0; i < m; i++){
		printf("%I64d\n", ans[i]);
	}
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}