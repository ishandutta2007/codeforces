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

const int inf = 200*1001;

void mineq(int &a, int b){
	a = min(a,b);
}

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<vi> a(n, vi(m));
	trav(v, a) trav(x, v) cin >> x;
	vector<vector<vi>> dp(1<<k, vector<vi>(n, vi(m, inf)));
	rep(i,0,k){
		int x,y;
		cin >> x >> y;
		--x, --y;
		dp[1<<i][x][y] = a[x][y];
	}
	rep(msk,1,1<<k){
		if(__builtin_popcount(msk) > 1){
			rep(sub,1,msk) if((sub|msk) == msk){
				int bus = msk ^ sub;
				if(bus < sub) continue;
				rep(i,0,n) rep(j,0,m)
					mineq(dp[msk][i][j], dp[sub][i][j] + dp[bus][i][j] - a[i][j]);
			}
		}
		priority_queue<pair<int,pii>> ko;
		rep(i,0,n) rep(j,0,m)
			ko.push({-dp[msk][i][j], {i,j}});
		while(!ko.empty()){
			auto pa = ko.top();
			ko.pop();
			int val = -pa.first, i = pa.second.first, j = pa.second.second;
			if(val > dp[msk][i][j]) continue;
			rep(t,0,4){
				int x = i+dx[t], y = j+dy[t];
				if(x+1 && y+1 && x<n && y<m){
					int val = dp[msk][i][j] + a[x][y];
					if(dp[msk][x][y] > val){
						dp[msk][x][y] = val;
						ko.push({-val, {x,y}});
					}
				}
			}
		}
	}
	int ans = inf;
	rep(i,0,n) rep(j,0,m) mineq(ans, dp[(1<<k)-1][i][j]);
	cout << ans << endl;
	vector<string> grid(n, string(m, '.'));

	function<void(int,int,int)> fill = [&](int msk, int i, int j){
		grid[i][j] = 'X';
		int cost = dp[msk][i][j];
		rep(t,0,4){
			int x = i+dx[t], y = j+dy[t];
			if(x+1 && y+1 && x<n && y<m){
				if(dp[msk][x][y]+a[i][j] == cost){
					fill(msk,x,y);
					return;
				}
			}
		}
		rep(sub,1,msk) if((sub|msk) == msk){
			int bus = msk ^ sub;
			if(bus < sub) continue;
			if(dp[bus][i][j] + dp[sub][i][j] == cost + a[i][j]){
				fill(bus, i, j);
				fill(sub, i, j);
				return;
			}
		}
	};
	rep(i,0,n) rep(j,0,m) if(ans == dp[(1<<k)-1][i][j]){
		fill((1<<k)-1, i, j);
		goto done;
	}
	done:
	trav(s, grid) cout << s << endl;
}