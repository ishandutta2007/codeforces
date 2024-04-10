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

	int n;
	cin >> n;

	rep(_,0,n){
		int n;
		cin >> n;
		vi as(n);
		trav(x, as) cin >> x;
		int xo = 0;
		trav(x, as) xo ^= x;
		if(xo == 0){
			cout << "DRAW" << endl;
			continue;
		}
		int i = 31 - __builtin_clz(xo);
		int cnt = 0;
		trav(x, as) if(x & (1<<i)) ++cnt;
		if(cnt % 4 == 1 || n % 2 == 0) cout << "WIN" << endl;
		else cout << "LOSE" << endl;
	}
}