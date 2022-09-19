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
const ld EPS = 1e-7;

ll a[N], b[N], c[N];
int Main(){
	ll n, k;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	cout << a[1] << ' ';
	ll la = a[1];
	for(int i = 2; i < n; i++){
		if(a[i] == la) la = b[i];
		else la = a[i];
		cout << la << ' ';
	}
	if((a[n] != la) && (a[n] != a[1])) la = a[n];
	else if((b[n] != la) && (b[n] != a[1])) la = b[n];
	else la = c[n];
	cout << la << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}