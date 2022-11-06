#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

typedef complex<ll> P;

bool frown(P a, P b, P c){
	a -= b, c -= b;
	return (a * conj(c)).imag() < 0;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<P> xz(n);
	rep(i,0,n){
		ll x, y;
		cin >> x >> y;
		xz[i] = P(x, y - x*x);
	}
	sort(all(xz), [&](P a, P b){
		return make_pair(a.real(),a.imag()) < make_pair(b.real(),b.imag());
	});

	vi hull;
	rep(i,0,n){
		if(i+1 < n && xz[i+1].real() == xz[i].real()) continue;
		while(sz(hull) >= 2){
			int a = sz(hull)-2, b = sz(hull)-1;
			a = hull[a], b = hull[b];
			if(!frown(xz[a], xz[b], xz[i])) hull.pop_back();
			else break;
		}
		hull.push_back(i);
	}
	cout << sz(hull)-1 << endl;
}