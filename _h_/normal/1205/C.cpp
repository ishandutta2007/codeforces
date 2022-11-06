#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

bool query(int x1, int y1, int x2, int y2){
	if(x1 + y1 > x2 + y2){
		swap(x1, x2);
		swap(y1, y2);
	}
	cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<bool>> ans(n, vector<bool>(n));
	ans[0][0] = true;

	auto fun = [&](int i, int j, int a, int b){
		ans[i][j] = ans[a][b] == query(i,j, a,b);
	};
	fun(1, 2, 0, 1);
	fun(1, 0, 1, 2);
	fun(2, 1, 0, 1);
	rep(i,0,n) rep(j,0,n) if(i+j && ((i+j)%2 <= (max(i,j)>=3))){
		if(i && j) fun(i,j, i-1, j-1);
		else if(i >= 2) fun(i,j, i-2, j);
		else fun(i,j, i,j-2);
	}
	for(int i = 0; ; i += 2){
		if(!ans[i+2][i+2]){
			int x1, y1, x2, y2;
			if( ans[i][i] ^ ans[i+1][i] ^ ans[i+2][i] ^ ans[i+2][i+1] ){
				x1 = i+1, y1 = i;
				x2 = i+2, y2 = i+2;
			} else {
				x1 = i, y1 = i;
				x2 = i+2, y2 = i+1;
			}
			bool res = query(x1, y1, x2, y2);
			if( res != (ans[x1][y1] == ans[x2][y2]) ){
				rep(i,0,n) rep(j,0,n) if((i+j) % 2){
					ans[i][j] = !ans[i][j];
				}
			}
			cout << "!" << endl;
			rep(i,0,n){
				rep(j,0,n) cout << ans[i][j];
				cout << endl;
			}
			return 0;
		}
	}
}