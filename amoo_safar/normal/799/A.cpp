// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, t, k, d;
	cin >> n >> t >> k >> d;
	n = (n + k - 1) / k;
	ll T1 = n * t;
	ll T2 = Inf;
	for(int i = 1; i < n; i++){
		T2 = min(T2, max(d + i*t, (n - i) * t));
	}
	cout << (T2 < T1 ? "YES\n" : "NO\n");
	return 0;
}