#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, q;
	cin >> n >> q;

	vector<vector<bool>> lava(2, vector<bool>(n, false));

	auto calc = [&](int r, int c){
		if(!lava[r][c]) return 0;
		int ans = 0;
		rep(t,-1,2){
			int c1 = c + t;
			if(c1 >= 0 && c1 < n){
				ans += lava[1-r][c1];	
			}
		}
		return ans;
	};

	int cnt = 0;

	rep(_,0,q){
		int r, c;
		cin >> r >> c;
		--r, --c;
		cnt -= calc(r,c);
		lava[r][c] = !lava[r][c];
		cnt += calc(r,c);
		cout << (cnt ? "No" : "Yes") << endl;
	}
}