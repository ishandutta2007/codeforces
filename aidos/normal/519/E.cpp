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

int d[100100];
int col[100100];
int par[100100][22];
vector < int > g[100100];

void dfs(int v, int p, int dis){
	d[v] = dis;
	par[v][0] = p;
	for(int i = 1; i < 20; i++){
		par[v][i] = par[par[v][i-1]][i-1];
	}
	forit(g[v]){
		if(*it == p) continue;
		dfs(*it, v, dis+1);
		col[v]+=col[*it];
	}
	col[v]++;
}

int get(int x, int y){
	if( d[x] < d[y]){
		return get(y, x);
	}

	for(int i = 19; i>=0; i--){
		if(par[x][i] > 0 && d[par[x][i]] >= d[y]) x = par[x][i];
	}
	if(x == y) return x;
	for(int i = 19; i>=0; i--){
		if(par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int getP(int x, int len){
	int dis = d[x];
	for(int i = 19; i>=0; i--){
		if(par[x][i] > 0 && dis - d[par[x][i]] <= len){
			x = par[x][i];
		}
	}
	return x;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    for(int i = 1, x, y; i < n; i++){
    	cin >> x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    dfs(1, 0, 0);

    int m;
    cin>>m;

    for(int i = 0, x, y; i < m; i++){
    	cin >> x >> y;
    	if(x == y) {
    		cout << n << endl;
    		continue;
    	}
    	if((d[x] + d[y]) % 2 == 1){
    		cout << 0 << endl;
    		continue;
    	}
    	if(d[x] < d[y]) swap(x, y);
    	if(d[x] == d[y]){
    		int gg = get(x, y);
    		int aa = n - col[gg];
    		int len = d[x] - d[gg] - 1;
    		int x1=getP( x, len);
    		int y1 =getP(y, len);
    		cout << n - col[x1] - col[y1] << endl;
    	}
    	else {
    		int gg = get(x, y);
    		int len = (d[x] + d[y] - 2 * d[gg])/2;
    		int x1 = getP( x,len);
    		int y1= getP(x, len-1);
    		cout << col[x1] - col[y1] << endl;
    	}	
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}