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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = abs(a - c), y = abs(d - b);
		int ans;
		if(x == 0 && y == 0) ans = 0;
		else if(x == 0) ans = y;
		else if(y == 0) ans = x;
		else ans = x + y + 2;
		cout << ans << endl;
	}
}