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
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
int main(){
	cin.sync_with_stdio(0);
	ll n,m,k;
	cin >> n >> m >> k;
	vi t(n*m+100,-1), ixs(n*m);
	vector<vi> as(n+10,vi(m+10));
	rep(i,0,n) rep(j,0,m) cin >> as[i][j];
	rep(i,0,n*m) ixs[i] = i;
	sort(allof(ixs),[&](int a, int b){
		return as[a/m][a%m] < as[b/m][b%m];
	});
	function<int(int)> find = [&](int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	};
	auto uni = [&](int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
	};
	reverse(allof(ixs));
	for(int i : ixs){
		int x = i/m, y = i%m;
		rep(t,0,4){
			int xx = x + dx[t], yy = y + dy[t];
			if(xx >= 0 && xx < n && yy >= 0 && y < m && as[xx][yy] >= as[x][y])
				uni(i, xx*m + yy);
		}
		if(k % as[x][y] == 0 && -(ll)t[find(i)]*as[x][y] >= k){
			cout << "YES\n";
			vector<vi> ans(n,vi(m));
			stack<pii> st;
			st.push(pii(x,y));
			while(!st.empty()){
				pii p = st.top();
				st.pop();
				int xx = p.first, yy = p.second;
				if(xx < 0 || yy < 0 || xx >= n || yy >= m || as[xx][yy] < as[x][y] || ans[xx][yy] > 0) continue;
				ans[xx][yy] = as[x][y];
				k -= as[x][y];
				if(k == 0) break;
				rep(t,0,4){
					st.push(pii(xx+dx[t],yy+dy[t]));
				}
			}
			rep(i,0,n){
				rep(j,0,m) cout << ans[i][j] << ' ';
				cout << endl;
			}
			return 0;
		}
	}
	puts("NO");
}