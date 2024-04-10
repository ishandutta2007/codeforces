// vaziat meshki-ghermeze !
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

int a[N];

int Main(){
	int n;
	cin >> n;

	vector<int> A[2];
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		A[v & 1].pb(i);
	}
	int s0 = A[0].size();
	int s1 = A[1].size();
	// cerr << "!! " << s0 << ' ' << s1 << '\n';
	if(abs(s1 - s0) > 1) return cout << "-1\n", 0;
	ll ans = Inf;
	if(s0 == max(s0, s1)){
		ll res = 0;
		for(int i = 0; i < n; i += 2)
			res += abs(i - A[0][i/2]);
		ans = min(ans, res);
	}
	if(s1 == max(s0, s1)){
		ll res = 0;
		for(int i = 0; i < n; i += 2)
			res += abs(i - A[1][i/2]);
		ans = min(ans, res);
	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}