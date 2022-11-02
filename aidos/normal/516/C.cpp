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


ll dp[200100];
ll h[200100];

pair < pll, ll > t[1000100];

void build(int v, int l, int r){
	if( l == r){
		t[v] = mp(mp(2 * h[l], 2 * h[r]), 0);
	}
	else {
		int mid = (l+r) /2;
		build(v*2, l, mid);
		build(v * 2+1, mid+1, r);
		t[v].s = max(t[v*2].s, t[v*2+1].s);
		t[v].s = max(t[v].s, t[v*2].f.s + t[v*2 + 1].f.f + dp[mid+1] - dp[mid]);
		t[v].f.f = max(t[v*2].f.f, t[v*2+1].f.f + dp[mid+1] - dp[l]);
		t[v].f.s = max(t[v*2].f.s + dp[r] - dp[mid], t[v*2+1].f.s);
	}
}

const ll miinf = -(1ll << 50);

pair < pll, ll > get(int l, int r, int v, int tl, int tr){
	if(l > r) return mp(mp(miinf, miinf), miinf);
	if( tl == l && tr == r) return t[v];
	int mid = (tl + tr)/2;
	pair < pll, ll > le = get(l, min(r, mid), v * 2, tl, mid);
	pair < pll, ll > ri = get(max(mid+1, l), r, v * 2+1, mid+1, tr);
	pair < pll, ll > ans;// = get(max(mid+1, l), r, v * 2+1, mid+1, r);


	ans.s = max(le.s, ri.s);
	ans.s = max(ans.s, le.f.s + ri.f.f + dp[mid+1] - dp[mid]);
	ans.f.f = max(le.f.f, ri.f.f + dp[mid+1] - dp[tl]);
	ans.f.s = max(le.f.s + dp[tr] - dp[mid], ri.f.s);
	return ans;
}


int n, m;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >>n >> m;
    for(int i = 2;  i<= n; i++){
    	cin >> dp[i];
    	dp[n+i] = dp[i];
    }
    cin >> dp[n+1];

    for(int i = 1;  i<= n; i++){
    	cin >> h[i];
    	h[n+i] = h[i];
    }
    for(int i = 1; i<=n + n; i++){
    	dp[i] += dp[i-1];
    }
    build(1, 1, 2 * n);
    pair < pll, ll > ans = get(1, n, 1, 1, 2 * n);
    //cout << miinf << endl;
   // cout << ans.s << endl;

    for(int i = 0, a, b; i < m; i++){
    	cin >> a >> b;
    	if( b < a) b += n;
    	//cout << a << "  " << b << endl;
    	pair < pll, ll > ans = get(b+1, a + n-1, 1, 1, 2 * n);
    	
    	cout << ans.s << endl;
    }


    	




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}