#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool vis[1000][1000][2][3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	trav(s, grid) cin >> s;

	function<void(int,int,bool,int)> rek = [&](int i, int j, bool d, int turns){
		if(turns > 2) return;
		if(i < 0 || j < 0 || i >= n || j >= m) return;
		if(vis[i][j][d][turns]) return;
		if(grid[i][j] == '*') return;
		vis[i][j][d][turns] = 1;
		if(grid[i][j] == 'T'){
			puts("YES");
			exit(0);
		}
		if(d){
			rek(i+1,j,d,turns);
			rek(i-1,j,d,turns);
		} else {
			rek(i,j+1,d,turns);
			rek(i,j-1,d,turns);
		}
		rek(i,j,!d,turns+1);
	};
	rep(i,0,n) rep(j,0,m) if(grid[i][j] == 'S'){
		rek(i,j,0,0);
		rek(i,j,1,0);
	}
	puts("NO");

}