// har ki ro didi goft mikhad beshe meslemon !
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
	memset(a, 0, sizeof a);
	int n, p, k;
	cin >> n >> p >> k;
	char X;
	for(int i = 1; i <= n; i++){
		cin >> X;
		a[i] = X - '0';
		a[i] = 1 - a[i];
	}
	for(int i = n; i >= 1; i--)
		a[i] += a[i + k];
	ll x, y;
	cin >> x >> y;

	ll ans = x * a[p];

	for(int i = 1; p + i <= n; i++){
		ans = min(ans, y * i + a[p + i]*x);
	}

	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	//T = 1;
	cin >> T;
	for(int i = 0; i < T; i++){
		Main();
	}
	return 0;
}