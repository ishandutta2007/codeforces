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

	int n;
	cin >> n;

	vi a(n);

	trav(x, a) cin >> x;

	rep(m,1,(1<<n)-1){
		int x = 0, y = 0;

		rep(i,0,n){
			if(m&(1<<i)) x += a[i];
			else         y += a[i];
		}

		if(x != y){
			vi ans;
			rep(i,0,n) if(m&(1<<i)) ans.push_back(i+1);
			cout << sz(ans) << endl;
			trav(x, ans) cout << x << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}