#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<ll> bs(n);
	trav(x, bs) cin >> x;

	if(count(all(bs), 0) == n){
		cout << "YES" << endl;
		rep(_,0,n) cout << 1 << ' ';
		cout << endl;
		return 0;
	}
	
	auto prv = [&](int i){
		return (i+n-1)%n;
	};

	bs.push_back(bs[0]);
	rep(i,0,n) if(bs[i] > bs[prv(i)]){
		vector<ll> a(n);
		a[i] = bs[i];
		for(int k = prv(i); k != i; k = prv(k)){
			int j = prv(k), l = (k+1)%n;

			ll x;
			ll dif = bs[j] - bs[k];
			if(dif < 0) x = 0;
			else {
				x = 1 + dif / a[l];
			}
			a[k] = bs[k] + x * a[l];
		}
		cout << "YES" << endl;
		trav(x, a) cout << x << ' ';
		cout << endl;
		return 0;
	}
	cout << "NO" << endl;
}