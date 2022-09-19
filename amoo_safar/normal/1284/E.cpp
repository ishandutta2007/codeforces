#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> p;

const int Maxn = 2500 + 10;

p a[Maxn];

ll C4(ll x){
	return x * (x - 1) * (x - 2) * (x - 3) / 24;
}
ll C3(ll x){
	return x * (x - 1) * (x - 2) / 6;
}
vector<ld> deg;

ld pi = acos(-1);


ll cross(p a, p b){
	return a.F * b.S - a.S * b.F;
}
ll lef(p a, p b){
	return a.F * b.S > a.S * b.F;
}
vector<ll> A, B, C;
vector<pll> X;

bool up(p A){
	if(A.F >= 0) return true;
	return false;
}

bool CMP(p a, p b){
	if(up(a) != up(b)){
		return up(a);
	}
	return lef(a, b);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//cout <<fixed << setprecision(16) << pi << '\n';
	ll n;
	cin >> n;
	ld x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a[i] = p(x, y);
		//cout << a[i] << '\n';
	}
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		X.clear();
		for(int j = 0; j < n; j++){
			if(i != j){
				X.pb({a[j].F-a[i].F, a[j].S-a[i].S});
			}
		}
		//cerr << "S\n";
		sort(all(X), CMP);
		//for(int i = 0; i < n - 1; i ++) if(deg[i] < 0) deg[i] += pi + pi;
		//for(auto D : deg) cout << fixed << setprecision(3) << D << ' '; cout << '\n';
		
		ans += C4(n - 1);
		ll cnt = 0;
		ll p = 0;
		for(int i = 0; i < n - 1; i++){
			if(p == i){
				p = i + 1;
				cnt = 0;
			}
			if(p == n - 1) p = 0;
			//cerr << i << '\n';
			while(p!=i && lef(X[i], X[p])){
				p++;
				cnt ++;
				if(p == n - 1) p = 0;
			}
			
			ans -= C3(cnt);
			cnt --;
		}
		
	}
	//cout << ans << '\n';
	cout << ans << '\n';
	return 0;

}