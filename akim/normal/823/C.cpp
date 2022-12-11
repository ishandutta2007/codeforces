#include <bits/stdc++.h>

#define f first
#define s second 
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

const int N = (int)3e5;

int a[N];
vector<ll> vc;

int n;
ll k;

bool check(ll m) {
	ll s = 0,x;
	for(int i = 0; i < n; i++) {
		x = a[i] % m;
		if(x != 0){
			s += m - x;
		}
		if(s > k) return 0;
	}
	return 1;
}

int main(){

	scanf("%d%lld", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 1; j * j <= a[i]; j++) {
			vc.pb(j);
			vc.pb(a[i] / j);
			vc.pb(a[i] / j + !!(a[i] % j));
		}
	}
	vc.pb((ll)(1e11)+(ll)(1e10));
	sort(vc.begin(), vc.end());
//	for(ll i : vc) {
//		cout << i << " ";
//	}
	for(int i = vc.size() - 2; i >= 0; i--) {
		if(check(vc[i])) {
			ll l = vc[i], r = vc[i + 1];
			while(l + 1 < r) {
				ll m = (l + r) >> 1;
				if(check(m)) {
					l = m;
				} else {
					r = m;
				}
			}
			cout << l << endl;
			return(0);
		}
	}


	return 0;
}