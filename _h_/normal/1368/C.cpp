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

void pp(int x, int y){
	cout << x << " " << y << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	cout << 3 * n + 4 << endl;

	pp(0,0);
	pp(0,1);
	rep(i,0,n){
		rep(y, i, i+3)
			pp(i+1, y);
	}
	pp(n+1, n);
	pp(n+1, n+1);
}