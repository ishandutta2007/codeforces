// written by aitch
// on 2019 12/17 at 16:05:00
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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	if(r + c == 2) cout << 0 << endl;
	else {
		vi rs(r), cs(c);
		if(r > 1){
			cs[0] = 1;
			rs[0] = 2;
			rs[1] = 3;
			int cur = 4;
			rep(i,1,c) cs[i] = cur++;
			rep(i,2,r) rs[i] = cur++;
		} else {
			rs[0] = 1;
			cs[0] = 2;
			cs[1] = 3;
			int cur = 4;
			rep(i,1,r) rs[i] = cur++;
			rep(i,2,c) cs[i] = cur++;
		}
		rep(i,0,r){
			rep(j,0,c) cout << rs[i] * cs[j] << ' ';
			cout << endl;
		}
	}
}