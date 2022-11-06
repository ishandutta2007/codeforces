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

	ll n;
	cin >> n;

	set<ll> f;

	auto fun = [&](ll d){
		ll res = n/d * (n-d+2) / 2;
		f.insert(res);
	};
	for(ll i = 1; i*i <= n; ++i){
		if(n%i == 0){
			fun(i);
			fun(n/i);
		}
	}

	trav(x, f) cout << x << ' ';
	cout << endl;
}