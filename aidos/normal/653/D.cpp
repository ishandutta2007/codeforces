#include <bits/stdc++.h>

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

const int inf = (int)1e9;
const int maxn = (int) 1e5 + 10;

using namespace std;

ll f[111][111];
ll c[111][111];
ll aa[111][111];
int used[111];
int n, m, x;


bool dfs(int v, int t, int x){
	if(used[v]) return false;
	if(v == t) return true;
	used[v] = 1;
	for(int i = 1; i <= n; i++){
		if(c[v][i] - f[v][i] >= x && dfs(i, t, x)){
			f[v][i] += x;
			f[i][v] -= x;
			return true;
		}
	}
	return false;
}



ll max_flow(int s, int t){
	ll flow = 0;
	int x = 1e9;
	while(x > 0){
		for(int i = 1; i <= n; i++)
			used[i] = false;
		while(dfs(s, t,x)){	
			for(int i = 1; i <= n; i++)
				used[i] = false;
			flow += x;
		}
		x/=2;
	}
	return flow;
}


void init(double xx){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			c[i][j] = 0;
			f[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(aa[i][j] == 0) continue;
			//if(xx * x < aa[i][j]) c[i][j] = x;
			//else 
			c[i][j] = aa[i][j]/xx;
		}
	}
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> m >> x;

    for(int i = 0, a, b, c; i < m; i++){
    	cin >> a >> b >> c;
    	aa[a][b] += c;
    }
    double l = 0, r = 1e9;
    for(int i = 0; i < 80; i++){
    	double mid = (l+r)/2.0;
    	init(mid);
    	if(max_flow(1, n) >= x){
    		l = mid;
    	}
    	else r = mid;
    }
    r *= x;
    printf("%.12lf\n", r);







    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}