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

ll p[N];
vector<pll> A, B;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll k, c;
	ll S = 0;
	for(int i = 0; i < n; i++){
		cin >> k >> c; 
		A.pb({c, k});
		S += k;
	}
	ll t;
	cin >> t;
	for(int i = 1; i <= t; i++) cin >> p[i];
	p[t + 1] = Inf;
	for(int i = 1; i <= t + 1; i++){
		ll d = min(S, p[i] - p[i - 1]);
		S -= d;
		//cerr << i << " : " << d << '\n'; 
		B.pb({i, d});
	}
	sort(all(A));

	ll ans = 0;
	while(A.size() && B.size()){
		if(A.back().S == 0){
			A.pop_back();
			continue;
		}
		if(B.back().S == 0){
			B.pop_back();
			continue;
		}
		ll d = min(A.back().S, B.back().S);
		ans += d * A.back().F * B.back().F;
		A[A.size() - 1].S -= d;
		B[B.size() - 1].S -= d;	
	}
	cout << ans << '\n';
	return 0;
}