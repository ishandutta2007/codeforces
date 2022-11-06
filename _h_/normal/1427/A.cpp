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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	trav(x, a) cin >> x;
	int sum = 0;
	trav(x, a) sum += x;
	if(sum == 0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		sort(all(a));
		if(sum > 0) reverse(all(a));
		trav(x, a) cout << x << " ";
		cout << endl;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	rep(_,0,n) solve();
}