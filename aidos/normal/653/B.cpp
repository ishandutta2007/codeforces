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


int dp[111][111];
int n, q;
string a, b;
vector < int > g[1111];
int get(int x, int y){
	if(x == n - 1) return 1;
	int &res = dp[x][y];
	if(res != -1) return res;
	res = 0;
	for(int j = 0; j < g[y].size(); j++){
		res += get(x + 1, g[y][j]);
	}
	return res;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> q;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < q; i++){
    	cin >> a >> b;
    	g[b[0] - 'a'].pb(a[0] - 'a');
    }
    cout << get(0, 0) << endl;
    

    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}