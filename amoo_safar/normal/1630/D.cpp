#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e6 + 10;

typedef long long ll;
typedef pair<ll, ll> pll;

ll A[N];

pll Solve(vector<ll>& V){
	if(V.empty()) return {0, 0};
	ll sm = 0;
	ll mn = abs(V[0]);
	int z = 0;
	int n = V.size();
	for(int i = 0; i < n; i++){
		z ^= (V[i] < 0);
		mn = min(mn, abs(V[i]));
		sm += abs(V[i]);
	}
	if(z) return {sm - 2 * mn, sm};
	return {sm, sm - 2 * mn};
}
int Main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> A[i];
	ll g = 0;
	for(int i = 0; i < m; i++){
		ll v;
		cin >> v;
		g = __gcd(v, g);
	}
	ll s0 = 0, s1 = 0;
	vector<ll> R;
	for(int x = 0; x < g; x ++){
		R.clear();
		for(int st = x; st < n; st += g)
			R.pb(A[st]);
		auto res = Solve(R);
		s0 += res.F;
		s1 += res.S;
	}
	cout << max(s1, s0) << '\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) Main();
	return 0;
}