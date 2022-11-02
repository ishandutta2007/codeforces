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

char c[111][111][111];
int n, m, k;
int u1[111][111][111];
int u2[111][111][111];
int u3[111][111][111];
int cn1 = 0;
int cn2 = 0;
int cn3 = 0;
int X, Y, Z;

void dfs(int x, int y, int z){
	if(u1[x][y][z] != cn1) return;
	if(u2[x][y][z] == cn2) return;
	
	u2[x][y][z] = cn2;
	if(x + 1< n) dfs(x + 1, y, z);
	if(y + 1< m) dfs(x, y + 1, z);
	if(z + 1< k) dfs(x, y, z+1);
}
void dfs2(int x, int y, int z){
	
	if(X == x && Y == y && Z == z) return;
	if(u1[x][y][z] != cn1) return;
	if(u3[x][y][z] == cn3) return;
	if(c[x][y][z] == '0') return;
	u3[x][y][z] = cn3;
	if(x + 1< n) dfs2(x + 1, y, z);
	if(y + 1< m) dfs2(x, y + 1, z);
	if(z + 1< k) dfs2(x, y, z+1);
}

bool check(int x, int y, int z){
	if(c[x][y][z] == '0') return 0;
	++cn1;
	for(int i = -1; i < 2; i++){
		if(i + x < 0 || i + x >= n) continue;
		for(int j = -1; j < 2; j++){
			if(j + y < 0 || j + y >= m) continue;
			for(int t=-1; t < 2; t++){
				if(z + t < 0 || z + t >= k) continue;
				if(c[x + i][y + j][z + t] == '0') continue;
				u1[x + i][y + j][z + t] = cn1;
			}
		}
	}
	X = x;
	Y = y;
	Z = z;
	bool ok  =0;
	if(x > 0 && c[x-1][y][z] == '1') {
		++cn2;
		++cn3;
		dfs(x-1, y, z);
		dfs2(x-1, y, z);
		if(x +1 < n && c[x+1][y][z] == '1') {
			if((u2[x+1][y][z] == cn2) && (u3[x+1][y][z] != cn3)) ok = 1;
		}
		if(y +1 < m && c[x][y+1][z] == '1') {
			if((u2[x][y+1][z] == cn2) && (u3[x][y+1][z] != cn3)) ok = 1;
		}
		if(z + 1 < k && c[x][y][z+1] == '1'){
			if((u2[x][y][z+1] == cn2) && (u3[x][y][z+1] != cn3)) ok = 1;
		}
	}

	if(y > 0 && c[x][y-1][z] == '1') {
		++cn2;
		++cn3;
		dfs(x, y-1, z);
		dfs2(x, y-1, z);
		if(x +1 < n && c[x+1][y][z] == '1') {
			if((u2[x+1][y][z] == cn2) && (u3[x+1][y][z] != cn3)) ok = 1;
		}
		if(y +1 < m && c[x][y+1][z] == '1') {
			if((u2[x][y+1][z] == cn2) && (u3[x][y+1][z] != cn3)) ok = 1;
		}
		if(z + 1 < k && c[x][y][z+1] == '1'){
			if((u2[x][y][z+1] == cn2) && (u3[x][y][z+1] != cn3)) ok = 1;
		}
	}
	if(z > 0 && c[x][y][z-1] == '1') {
		++cn2;
		++cn3;
		dfs(x, y, z-1);
		dfs2(x, y, z-1);
		
		if(x +1 < n && c[x+1][y][z] == '1') {
			if((u2[x+1][y][z] == cn2) && (u3[x+1][y][z] != cn3)) ok = 1;
		}
		if(y +1 < m && c[x][y+1][z] == '1') {
			if((u2[x][y+1][z] == cn2) && (u3[x][y+1][z] != cn3)) ok = 1;
		}
		if(z + 1 < k && c[x][y][z+1] == '1'){
			if((u2[x][y][z+1] == cn2) && (u3[x][y][z+1] != cn3)) ok = 1;
		}
	}
	return ok;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		scanf("%s", c[i][j]);
    	}
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		for(int t = 0; t < k; t++){
    			if(c[i][j][t] == '0') continue;
    			if(check(i, j, t)) {
    				ans++;
    			}
    		}
    	}
    }
    cout << ans << endl;
    
    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}