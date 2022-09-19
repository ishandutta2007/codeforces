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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 1e5 + 10;
const int Log = 30;
const int Sq = 360;

int n;
ll A[N];

int Solve(bool rev){
	vector<ll> V;
	V.reserve(1 << 20);
	int mx = 1;
	for(int d = 0; d < Sq; d++){
		V.clear();
		for(int i = 0; i < n; i++)
			V.pb(A[i] - 1ll * i * d);
		sort(all(V));
		int cnt = 1;
		for(int i = 1; i < n; i++){
			if(V[i] == V[i - 1]) mx = max(mx, ++cnt);
			else cnt = 1;
		}
	}
	if(rev) return n - mx;

	int d;
	vector< pair<ll, int> > mt;
	mt.reserve(1<<21);
	for(int i = 0; i < n; i++){
		for(int l = 1; l < Sq && i + l < n; l++){
			if((A[i + l] - A[i]) % l == 0){
				d = (A[i + l] - A[i]) / l;
				if(abs(d) < Sq) continue;

				mt.pb({A[i] - 1ll * i * d, d});
			}
		}
	}
	// mx = 0;
	sort(all(mt));
	ll cnt = 1, mx2 = 1;
	for(int i = 1; i < (int) mt.size(); i++){
		if(mt[i] == mt[i - 1]) mx2 = max(mx2, ++cnt);
		else cnt = 1;
	}
	int fl = 0;
	for(int i = 0; i < Sq; i++) if(i * (i - 1) == mx2 * 2) fl = 1, mx = max(mx, i);
	assert(fl);
	return n - mx;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if(n == 1) return cout << "0\n", 0;
	for(int i = 0; i < n; i++) cin >> A[i];	
	int ans = Solve(false);
	reverse(A, A + n);
	cout << min(ans, Solve(true)) << '\n';
	return 0;
}
/*
10
1001 2001 3001 4001 5001 5001 7002 8001 9002 10001

*/