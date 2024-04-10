#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> A, B, C;

ll ans = Inf;

void Check(){
	for(auto x : B){
		if(x < A[0]) continue;
		ll a = *(--upper_bound(all(A), x));
		if(C.back() < x) continue;
		ll c = *lower_bound(all(C), x);
		ll b = x;
		ans = min(ans, (a-b)*(a-b) + (b-c)*(b-c) + (a-c)*(a-c));
	}
}

void Solve(){
	A.clear();
	B.clear();
	C.clear();
	
	ll n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	ll v;
	for(int i = 0; i < n1; i++){
		cin >> v;
		A.pb(v);
	}
	for(int i = 0; i < n2; i++){
		cin >> v;
		B.pb(v);
	}
	for(int i = 0; i < n3; i++){
		cin >> v;
		C.pb(v);
	}
	sort(all(A));
	sort(all(B));
	sort(all(C));
	
	ans = Inf;
	Check();
	swap(C, B);
	Check();
	
	swap(A, B);
	Check();
	swap(C, B);
	Check();
	
	swap(A, B);
	Check();
	swap(C, B);
	Check();
	
	cout << ans << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) Solve();
	return 0;
}