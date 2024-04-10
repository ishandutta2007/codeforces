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

ll a[N];
ll A[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> A[i];
		a[i] = A[i];
	}
	if(n == 1){
		cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[1] << '\n';
		return 0;
	}
	cout << "1 1\n" << -a[1] << '\n';
	a[1] = 0;
	cout << "2 " << n << '\n';
	for(int i = 2; i <= n; i++){
		ll md = ((a[i] % n) + n ) % n;
		cout << md * (n - 1) << ' ';
		a[i] += md * (n - 1);
	}
	cout << '\n';
	cout << "1 " << n << '\n';
	for(int i = 1; i <= n; i++) cout << -a[i] << ' ';
	cout << '\n';
	return 0;
}