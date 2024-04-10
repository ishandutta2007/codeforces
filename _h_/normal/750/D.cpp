#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
#define sz(v) int((v).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

const int L = 400;

bool grid[L][L];

bool done[L][L][30][8];

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi t(n);
	trav(x, t) cin >> x;
	function<void(int,int,int,int)> rek = [&](int x, int y, int i, int dir){
		if(done[x][y][i][dir]) return;
		done[x][y][i][dir] = 1;
		rep(_,0,t[i]){
			x += dx[dir];
			y += dy[dir];
			grid[x][y] = 1;
		}
		if(++i < n){
			rek(x,y,i,(dir+1)%8);
			rek(x,y,i,(dir+7)%8);
		}
	};
	rek(200,200,0,2);
	int ans = 0;
	rep(i,0,L) rep(j,0,L) ans += grid[i][j];
	cout << ans << endl;
}