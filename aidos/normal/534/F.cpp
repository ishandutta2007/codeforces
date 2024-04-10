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


int n;
int m;
char dp[150000][32][21];
int a[11], b[32];
int dd[] = {1, 11, 121, 1331, 14641};
char cc[11][111];
vector < int > v[111];

char dfs(int pos, int c, int mask){
	if(pos > m){
		return c==0; 
	}
	char &res = dp[c][mask][pos];
	if(res != -1) return res;
	vector < int > g;
	int C = c;
	for(int i = 0 ; i < n; i++){
		g.pb(C % 11);
		C/=11;
	}
	int cur = b[pos];
	res = 0;
	for(int i = 0; i < v[cur].size(); i++){
		//cout << pos << " "<< cur << " " << v[cur][i] << " " << endl;
		int ok = 1;
		int y = c;
		for(int j = 0;  j < n; j++){
			if(v[cur][i] & (1 << j)){
				if(mask & (1 << j)) continue;
				if(g[j] == 0) ok = 0;
				else y -= dd[j];
			}
		}
		if(!ok) continue;
		if(dfs(pos+1, y, v[cur][i])){
			res= 1;
			break;
		}
	}
	//if( res ) cout << pos << " " << c << " " << mask << endl;
	return res;
}

int get(int mask){
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if( (1<< i) & mask ) {
			if( cur ) continue;
			ans++;
			cur = 1;
		}
		else cur = 0;
	}
	return ans;
}

void rec(int pos, int c, int mask){
	if(pos > m){
		return;
	}

	vector < int > g;
	int C = c;
	for(int i = 0 ; i < n; i++){
		g.pb(C % 11);
		C/=11;
	}
	int cur = b[pos];
	for(int i = 0; i < v[cur].size(); i++){
		int ok = 1;
		int y = c;
		for(int j = 0;  j < n; j++){
			if(v[cur][i] & (1 << j)){
				if(mask & (1 << j)) continue;
				if(g[j] == 0) ok = 0;
				else y -= dd[j];
			}
		}
		if(!ok) continue;
		if(dfs(pos+1, y, v[cur][i])){
			for(int j = 0; j < n; j++){
				if(v[cur][i] & (1 << j) ) cc[j][pos-1] = '*';
				else cc[j][pos-1] = '.';
			}
			//cout << pos << endl;
			rec(pos+1, y, v[cur][i]);
			return;
		}
	}
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
	for(int  i = 1; i <= m; i++) cin >> b[i];

	int x = 0;
	for(int i = n; i > 0; i--)
		x = x * 11 + a[i];
	
	
	for(int i = 0; i < (1<<n); i++){
		v[get(i)].pb(i);
	}
	//cerr << "cur\n";
	memset(dp, -1, sizeof dp);
	dfs(1, x, 0);//cerr << "ok\n";
	rec(1, x, 0);
	//cerr << "cur2\n";
	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << cc[i][j];
		}
		cout << endl;
	}








    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}