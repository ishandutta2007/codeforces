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
	vi a(n+1);
	rep(i,0,n) cin >> a[i+1];
	ll sum = 0;
	trav(x, a) sum += x;
	if(sum % n){
		cout << -1 << endl;
		return;
	}
	int avg = sum / n;
	vi is, js, xs;
	auto add_op = [&](int i, int j, int x){
		a[i] -= x * i;
		a[j] += x * i;
		is.push_back(i);
		js.push_back(j);
		xs.push_back(x);
	};
	rep(i,2,n+1){
		int r = (i - a[i]%i)%i;
		add_op(1, i, r);
		add_op(i, 1, a[i] / i);
	}
	rep(i,2,n+1) add_op(1, i, avg);
	cout << sz(is) << endl;
	rep(i,0,sz(is)) cout << is[i] << " " << js[i] << " " << xs[i] << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	rep(_,0,n) solve();
}