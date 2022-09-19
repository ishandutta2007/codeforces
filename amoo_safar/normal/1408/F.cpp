// That's How much we have in common
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


vector<pll> X;

ll Solve(ll L, ll R){
	if(L + 1 == R) return 0;
	int mid = (L + R) >> 1;
	assert(R - mid == mid - L);
	Solve(L, mid);
	Solve(mid, R);
	for(int i = L, j = mid; i < mid; i++, j++) X.pb({i, j});
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	if(n == 1) return cout << "0\n", 0;
	int p2 = 1;
	while(p2 + p2 < n) p2 += p2;
	Solve(1, p2 + 1);
	Solve(n + 1 - p2, n + 1);
	cout << X.size() << '\n';
	for(auto x : X) cout << x.F << ' ' << x.S << '\n';
	return 0;
}