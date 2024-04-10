#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vi a(n), b(n);
	trav(x, a) cin >> x;
	trav(x, b) cin >> x;

	vector<vi> ls(k);
	rep(i,0,n) ls[a[i]-1].push_back(b[i]);

	vi free;
	int num = 0;
	trav(l, ls) if(!l.empty()){
		sort(all(l));
		rep(i,0,sz(l)-1) free.push_back(l[i]);
	} else {
		++num;
	}
	sort(all(free));
	ll ans = 0;
	rep(i,0,num) ans += free[i];
	cout << ans << endl;
}