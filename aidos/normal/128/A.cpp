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
int dp[70][515];
vector < pii > v;
int dx[] = {-1, 0, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 0, -1, 1, 1, -1};
int ok(int x, int y, int cur){
	for(int i = 0; i < v.size(); i++){
		if( y != v[i].s ) continue;
		if( x - v[i].f == cur) return true;
	}
	return false;
}

int get(int pos, int cur){
	if(cur > 509) return false;
	if(pos == 7) {
		//cout << cur << endl;
		return true;
	}
	int &res = dp[pos][cur];
	if( res != -1) return res;
	res = 0;
	int x = pos / 8;
	int y = pos % 8;
	//cout << x << " " << y << " "<< cur << endl;
	forit(v){
		if(it->s != y) continue;
		if( x-(it->f) == cur) return res = 0;
	}
	for(int k = 0; k < 9; k++){
		int X = x + dx[k];
		int Y = y + dy[k];		
		if(X < 0 || Y < 0 || X >= 8 || Y >= 8 || ok(X, Y, cur)) continue;
		res |= get(X * 8 + Y, cur+1);
	}
	
	return res;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
    		char c;
    		cin >> c;
    		if(c == 'S') {
    			v.pb(mp(i, j));
    			//cout << i << " " << j << endl;
    		}
    	}
    }
    for(int i =0;i < 69; i++)
    	for(int j = 0; j < 512; j++)
    		dp[i][j] = -1;
    if(get(56, 0)) cout << "WIN\n";
    else cout << "LOSE\n";






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}