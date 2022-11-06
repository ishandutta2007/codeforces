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
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<string> b(n);
	rep(i,0,n)
		cin >> b[i];
	vector<vi> cmp(n, vi(n,-1)), sz(n, vi(n));
	vi cnt(n*n);
	rep(i,0,n) rep(j,0,n){
		int num = i*n + j;
		if(b[i][j] == 'X'){
			cmp[i][j] = num;
			sz[i][j] = 1;
		} else if(cmp[i][j] == -1){
			int s = 0;
			stack<pii> st;
			st.push(pii(i,j));
			while(!st.empty()){
				pii p = st.top();
				st.pop();
				int x = p.first, y = p.second;
				if(x < 0 || y < 0 || x >= n || y >= n || 
					cmp[x][y] != -1 || b[x][y]=='X') continue;
				cmp[x][y] = num;
				++s;
				rep(t,0,4)
					st.push(pii(x+dx[t], y+dy[t]));
			}
			sz[i][j] = s;
		}
	}
	int ans = 0;
	rep(i,0,n-k+1){
		cnt.assign(n*n,0);
		int cur = 0;
		auto ins = [&](int x, int y, bool bo){
			if(x < 0 || y < 0 || x >= n || y >= n) return;
			if(!bo && b[x][y]=='X')return;
			int num = cmp[x][y];
			assert(cnt[num] >= 0);
			if(!cnt[num]++)
				cur += sz[num/n][num%n];
		};
		auto rem = [&](int x, int y, bool bo){
			if(x < 0 || y < 0 || x >= n || y >= n) return;
			if(!bo && b[x][y]=='X')return;
			int num = cmp[x][y];
			if(!--cnt[num])
				cur -= sz[num/n][num%n];
		};
		rep(x,i-1,i+k+1) rep(y,-1,k+1){
			if(y != k || (x != i-1 && x != i+k))
				ins(x,y,(x!=i-1 && x != i+k && y != k));
		}
		ans = max(ans, cur);
		rep(j,1,n-k+1){
			rep(x,i,i+k){
				rem(x, j-2, 0);
				rem(x,j-1,1);
				ins(x,j-1,0);
			}
			rem(i-1,j-1, 0);
			rem(i+k,j-1, 0);
			rep(x,i,i+k){
				ins(x,j+k,0);
				rem(x,j+k-1,0);
				ins(x,j+k-1,1);
			}
			ins(i-1,j+k-1,0);
			ins(i+k,j+k-1,0);
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
}