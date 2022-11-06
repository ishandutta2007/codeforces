#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int n, m;
	cin >> n >> m;

	vi ut(n,-1), in(n, -1);
	int ans = 0;
	rep(_,0,m){
		int x, y;
		cin >> x >> y;
		if(x != y){
			--x, --y;
			++ans;
			ut[x] = y;
			in[y] = x;
		}
	}
	vector<bool> vis(n, false);
	rep(i,0,n) if(!vis[i] && ut[i] != -1 && in[i] == -1){
		int j = i;
		do {
			vis[j] = true;
			j = ut[j];
		} while(j != -1);
	}
	rep(i,0,n) if(!vis[i] && ut[i] != -1){
		++ans;
		int j = i;
		do {
			vis[j] = true;
			j = ut[j];
		} while(j != i);
	}
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}