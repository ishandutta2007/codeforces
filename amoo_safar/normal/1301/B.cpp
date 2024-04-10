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

ll a[N], n;

pll check(ll y){
	ll L = 0, R = Inf;
	for(int i = 1; i < n; i++){
		if(a[i - 1] == -1 && a[i] >= 0){
			L = max(L, a[i] - y);
			R = min(R, a[i] + y);
		}
		if(a[i] == -1 && a[i - 1] >= 0){
			L = max(L, a[i - 1] - y);
			R = min(R, a[i - 1] + y);
		}
		if(a[i - 1] >= 0 && a[i] >= 0){
			if(y < abs(a[i] - a[i - 1])) return {1, -1};
		}
	}
	return {L, R};
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		ll L = -1, R = Inf;
		ll mid;
		pll Q;
		while(L + 1 < R){
			mid = (L+R) >> 1;
			Q = check(mid);
			if(Q.F <= Q.S) R = mid;
			else L = mid;
		}
		cout << R << " " << check(R).F << '\n';
	}
	return 0;
}